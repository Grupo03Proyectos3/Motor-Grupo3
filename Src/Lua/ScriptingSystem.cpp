#include "ScriptingSystem.h"

extern "C"
{
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"
}

#include "ECS/GameObject.h"
#include "ECS/Manager.h"
#include <ECS/Components.h>
#include <LuaBridge\LuaBridge.h>
// AUDIO
#include "Audio/AudioSystem.h"
// UI
#include "UI/UISystem.h"
// RENDER
#include "Render/Animator.h"
#include "Render/ParticleSystem.h"

#include "Render/Camera.h"
#include "Render/Light.h"
// PHYSICS
#include "Physics/PhysicsSystem.h"
#include "Physics/RigidBody.h"
// BASE
#include "BehaviourScript.h"

#include "FlamingoBase/Transform.h"
// SCRIPTING
#include "BehaviourScript.h"
#include "FlamingoBase/SceneManager.h"
namespace Flamingo
{

    Flamingo::ScriptingSystem::ScriptingSystem()
        : m_scene_mngr(FlamingoSceneManager())
    {
        m_componentFactory = ComponentsFactory::instance();
        m_mngr = Manager::instance();
    }

    Flamingo::ScriptingSystem::~ScriptingSystem()
    {
        if (m_componentFactory != nullptr)
        {
            ComponentsFactory::close();
        }

        if (&m_scene_mngr != nullptr)
        {
            SceneManager::close();
        }

        lua_close(lua_state);
    }

    void Flamingo::ScriptingSystem::initSystem()
    {
        auto renderSystem = m_mngr->getSystem<Flamingo::RenderSystem>();
        m_componentFactory->addFactory("MeshRenderer", new MeshRendererFactory(renderSystem));
        m_componentFactory->addFactory("RigidBody", new RigidBodyFactory());
        m_componentFactory->addFactory("Transform", new TransformFactory());
        m_componentFactory->addFactory("Light", new LightFactory(renderSystem));
        m_componentFactory->addFactory("Camera", new CameraFactory(renderSystem));
        m_componentFactory->addFactory("Animator", new AnimatorFactory(renderSystem));
        m_componentFactory->addFactory("Scripts", new ScriptFactory());
        m_componentFactory->addFactory("UIElement", new UIElementFactory());

        // crear un Lua state
        lua_state = luaL_newstate();
        // cargar las standard libs
        luaL_openlibs(lua_state);
        // guardarme en Lua las funciones internas de Flamingo
        createSystemFuntions();
        // readScript("camara");
        // loadScene();
    }

    void Flamingo::ScriptingSystem::update(float t_delta_time)
    {
        // TO DO : CHANGE TO SCRIPT GROUP
        for (auto gO : Manager::instance()->getEntities(GROUP_SCRIPTING))
        {
            for (auto c : gO->getCurrentComponents())
            {
                auto s = dynamic_cast<BehaviourScript*>(c.second);
                if (s != nullptr && s->gameObject()->getActive() && s->gameObject()->getAlive())
                {
                    s->update(t_delta_time);
                }
            }
        }
    }

    void Flamingo::ScriptingSystem::recieve(const Message& t_m)
    {
        switch (t_m.id)
        {
            case MSG_COLLISION_STAY:
            {
                // Si alguno de los GameObjects implicados en la colisi�n tiene BehaviourScript,
                // se llama a su OnCollisionStay() para ejecutar la acci�n determinada por el usuario.
                if (auto bsCmp = m_mngr->getBehaviourComponent<BehaviourScript>(t_m.collision.obj1))
                {
                    bsCmp->onCollisionStay(t_m.collision.obj2);
                }

                if (auto bsCmp = m_mngr->getBehaviourComponent<BehaviourScript>(t_m.collision.obj2))
                {
                    bsCmp->onCollisionStay(t_m.collision.obj1);
                }

                break;
            }
            case MSG_COLLISION_ENTER:
            {
                if (auto bsCmp = m_mngr->getBehaviourComponent<BehaviourScript>(t_m.collision.obj1))
                {
                    bsCmp->onCollisionEnter(t_m.collision.obj2);
                }

                if (auto bsCmp = m_mngr->getBehaviourComponent<BehaviourScript>(t_m.collision.obj2))
                {
                    bsCmp->onCollisionEnter(t_m.collision.obj1);
                }

                break;
            }
            case MSG_COLLIISION_EXIT:
            {
                if (auto bsCmp = m_mngr->getBehaviourComponent<BehaviourScript>(t_m.collision.obj1))
                {
                    bsCmp->onCollisionExit(t_m.collision.obj2);
                }

                if (auto bsCmp = m_mngr->getBehaviourComponent<BehaviourScript>(t_m.collision.obj2))
                {
                    bsCmp->onCollisionExit(t_m.collision.obj1);
                }

                break;
            }
            default:
                break;
        }
    }

    lua_State* Flamingo::ScriptingSystem::getLuaState()
    {
        return lua_state;
    }

    void Flamingo::ScriptingSystem::readScript(const std::string& t_name)
    {
        std::string path = PATH_PREFIX + t_name + FILE_EXTENSION;
        // Cargar el script de lua
        int fd = luaL_dofile(lua_state, path.c_str());
        // Comprobar si ha fallado
        if (fd == 0)
        {
            return;
        }
        else
        {
            // remove error message from Lua state
            lua_pop(lua_state, 1);
            throw std::runtime_error("[LUA ERROR] " + (std::string)lua_tostring(lua_state, -1));
        }
    }

    void Flamingo::ScriptingSystem::callLuaFunction(std::string t_name)
    {
        luabridge::LuaRef fun = getFromLua(t_name);
        fun();
    }

    bool Flamingo::ScriptingSystem::loadScene(std::string t_scene, bool t_first)
    {
        if (t_scene.empty())
        {
            return false;
        }

        auto myScene = m_scene_mngr.createScene(t_scene, true);

        m_mngr->getSystem<RenderSystem>()->addShadersScene(myScene);
        // TO DO : a�adir control de excepciones devolviendo false si algo falla
        // Por ej : no encuentra el fichero
        readScript(t_scene);
        luabridge::LuaRef allEnts = getFromLua("entities");
        int n = allEnts.length();
        // Recorro las entidades del script de lua
        for (int i = 1; i <= n; i++)
        {
            luabridge::LuaRef entity = getFromLua(allEnts[i]);
            GameObject* gO = m_mngr->addGameObject({GROUP_EXAMPLE});

            // Ordenar componentes de la entidad
            std::vector<std::string> componentNames;
            lua_pushnil(entity);
            if (entity.isNil())
                throw std::exception("ERROR loading the scene");
            while (!entity.isNil() && lua_next(entity, 0) != 0) // Recorro los componentes que hay la entidad
            {
                std::string compName = lua_tostring(entity, -2); // Tipo de componente
                componentNames.push_back(compName);
                lua_pop(entity, 1);
            }

            // Ordenar atributos de cada componente
            std::sort(componentNames.begin(), componentNames.end());
            for (const auto& compName : componentNames)
            {
                luabridge::LuaRef component = entity[compName];
                lua_pushnil(component);

                while (lua_next(component, 0) != 0) // Recorro los atributos del componente
                {
                    std::string key = lua_tostring(entity, -2); // Nombre del atributo
                    std::string val = lua_tostring(entity, -1); // Valor del atributo
                    if (compName == "Name")
                    {
                        gO->setName(val);
                        if (val == "player")
                        {
                            m_mngr->setHandler(_hdr_player, gO);
                        }
                    }
                    else
                        m_data.insert({key, val});
                    lua_pop(component, 1);
                }
                if (compName != "Name")
                    m_componentFactory->addComponent(gO, compName, m_data); // (GameObject, tipo de componente, el map)

                m_data.clear();
            }
            m_scene_mngr.getScene(t_scene)->addObjects(gO); //Añadir el objeto a la escena

            for (auto c : gO->getCurrentComponents())
            {
                c.second->initComponent();
            }
        }

        return true;
    }

    void Flamingo::ScriptingSystem::createSystemFuntions()
    {
        // SceneManager
        luabridge::getGlobalNamespace(lua_state)
            .beginClass<Flamingo::SceneManager>("SceneManager")
            /*.addStaticFunction("getSceneManager", &SceneManager::getInstance)*/
            .addFunction("createScene", (&Flamingo::SceneManager::createScene))
            .addFunction("deleteScene", (&Flamingo::SceneManager::delScene))
            .addFunction("getCurrentScene", (&Flamingo::SceneManager::getSceneActive))
            .addFunction("setCurrentScene", (&Flamingo::SceneManager::setSceneActive))
            .endClass();

        // AudioSystem
        luabridge::getGlobalNamespace(lua_state)
            .beginClass<AudioSystem>("AudioSystem")
            .addFunction("play", (&AudioSystem::playAudio))
            .addFunction("setMusicVolume", (&AudioSystem::setMusicVolume))
            .addFunction("setFxVolume", (&AudioSystem::setSoundEffectsVolume))
            .endClass();
        // RenderSystem
        luabridge::getGlobalNamespace(lua_state)
            .beginClass<RenderSystem>("RenderSystem")
            .endClass();
        // ParticleSystem
        luabridge::getGlobalNamespace(lua_state)
            .beginClass<Flamingo::ParticleSystem>("ParticleSystem")
            .endClass();
        // PhysicsSystem
        luabridge::getGlobalNamespace(lua_state)
            .beginClass<PhysicsSystem>("PhysicsSystem")
            .addFunction("addRigidBody", (&PhysicsSystem::addRigidBody))
            .addFunction("removeRigidBody", (&PhysicsSystem::removeRigidBody))
            .endClass();
        // UISystem
        luabridge::getGlobalNamespace(lua_state)
            .beginClass<Flamingo::UISystem>("UISystem")
            .addFunction("changeScreenSize", (&UISystem::chageScreenSize))
            .endClass();
        // Manager
        luabridge::getGlobalNamespace(lua_state)
            .beginClass<Manager>("Manager")
            .addStaticFunction("getSceneManager", &Manager::instance)
            .addFunction("addGameObject", (&Manager::addGameObject))
            .addFunction("addComponent", (&Manager::addComponent<Camera>))
            .addFunction("addComponent", (&Manager::addComponent<Light>))
            .addFunction("addComponent", (&Manager::addComponent<MeshRenderer>))
            .addFunction("addComponent", (&Manager::addComponent<Transform>))
            .addFunction("addComponent", (&Manager::addComponent<RigidBody>))
            .addFunction("addSystem", (&Manager::addSystem<RenderSystem>))
            .addFunction("addSystem", (&Manager::addSystem<PhysicsSystem>))
            //.addFunction("addSystem", (&ecs::Manager::addSystem<Flamingo::ParticleSystem>))
            .addFunction("addSystem", (&Manager::addSystem<AudioSystem>))
            .addFunction("addSystem", (&Manager::addSystem<UISystem>))
            .addFunction("getComponent", (&Manager::getComponent<Camera>))
            .addFunction("getComponent", (&Manager::getComponent<Light>))
            .addFunction("getComponent", (&Manager::getComponent<MeshRenderer>))
            .addFunction("getComponent", (&Manager::getComponent<Transform>))
            .addFunction("getComponent", (&Manager::getComponent<RigidBody>))
            .addFunction("getEntities", (&Manager::getEntities))
            .addFunction("getHandler", (&Manager::getHandler))
            .addFunction("getSystem", (&Manager::getSystem<AudioSystem>))
            .addFunction("getSystem", (&Manager::getSystem<RenderSystem>))
            //.addFunction("getSystem", (&ecs::Manager::getSystem<Flamingo::ParticleSystem>))
            .addFunction("getSystem", (&Manager::getSystem<PhysicsSystem>))
            .addFunction("getSystem", (&Manager::getSystem<UISystem>))
            .addFunction("hasComponent", (&Manager::hasComponent<Camera>))
            .addFunction("hasComponent", (&Manager::hasComponent<MeshRenderer>))
            .addFunction("hasComponent", (&Manager::hasComponent<Light>))
            .addFunction("hasComponent", (&Manager::hasComponent<Transform>))
            .addFunction("hasComponent", (&Manager::hasComponent<RigidBody>))
            .addFunction("isAlive", (&Manager::isAlive))
            .addFunction("setAlive", (&Manager::setAlive))
            .addFunction("removeComponent", (&Manager::removeComponent<Camera>))
            .addFunction("removeComponent", (&Manager::removeComponent<Light>))
            .addFunction("removeComponent", (&Manager::removeComponent<MeshRenderer>))
            .addFunction("removeComponent", (&Manager::removeComponent<Transform>))
            .addFunction("removeComponent", (&Manager::removeComponent<RigidBody>))
            .addFunction("removeSystem", (&Manager::removeSystem<AudioSystem>))
            .addFunction("removeSystem", (&Manager::removeSystem<UISystem>))
            .addFunction("removeSystem", (&Manager::removeSystem<RenderSystem>))
            //.addFunction("removeSystem", (&ecs::Manager::removeSystem<Flamingo::ParticleSystem>))
            .addFunction("removeSystem", (&Manager::removeSystem<PhysicsSystem>))
            .addFunction("setAlive", (&Manager::setAlive))
            .addFunction("setHandler", (&Manager::setHandler))
            .endClass();
    }

    luabridge::LuaRef Flamingo::ScriptingSystem::getFromLua(std::string t_name)
    {
        return luabridge::getGlobal(lua_state, t_name.c_str());
    }
} // namespace Flamingo