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
// PLAYER CONTROLLER
#include "Physics/PlayerController.h"
// SCRIPTING
#include "BehaviourScript.h"

Flamingo::ScriptingSystem::ScriptingSystem(SceneManager* t_scene_mngr)
{
    m_componentFactory = ComponentsFactory::instance();
    m_mngr = ecs::Manager::instance();
    m_scene_mngr = t_scene_mngr;
}

Flamingo::ScriptingSystem::~ScriptingSystem()
{
    lua_close(lua_state);
}

void Flamingo::ScriptingSystem::initSystem()
{
    auto renderSystem = m_mngr->getSystem<Flamingo::RenderSystem>();
    m_componentFactory->addFactory("PlayerController", new PlayerControllerFactory());
    m_componentFactory->addFactory("MeshRenderer", new MeshRendererFactory(renderSystem));
    m_componentFactory->addFactory("RigidBody", new RigidBodyFactory());
    m_componentFactory->addFactory("AATransform", new TransformFactory());
    m_componentFactory->addFactory("Light", new LightFactory(renderSystem));
    m_componentFactory->addFactory("Camera", new CameraFactory(renderSystem));
    m_componentFactory->addFactory("ZAnimator", new AnimatorFactory(renderSystem));
    m_componentFactory->addFactory("Scripts", new ScriptFactory());

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
    for (auto game_object : m_mngr->getEntities(ecs::GROUP_SCRIPTING))
    {
        if (game_object != nullptr && game_object->getActive())
            //se llama a los update de los componentes que heredan de BehaviourScript
            m_mngr->getBehaviourComponent<BehaviourScript>(game_object)->update(t_delta_time);
    }
}

void Flamingo::ScriptingSystem::recieve(const Message& t_m)
{
    switch (t_m.id)
    {
        case MSG_COLLISION_STAY:
        {
            // Si alguno de los GameObjects implicados en la colisión tiene BehaviourScript,
            // se llama a su OnCollisionStay() para ejecutar la acción determinada por el usuario.
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
    std::cerr << "[LUA ERROR] " << lua_tostring(lua_state, -1) << std::endl;
    // remove error message from Lua state
    lua_pop(lua_state, 1);
    exit(1);
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
    m_scene_mngr->createScene(t_scene, t_first);
    // TO DO : añadir control de excepciones devolviendo false si algo falla
    // Por ej : no encuentra el fichero
    readScript(t_scene); 
    luabridge::LuaRef allEnts = getFromLua("entities");
    int n = allEnts.length();
    // Recorro las entidades del script de lua
    for (int i = 1; i <= n; i++)
    {
        luabridge::LuaRef entity = getFromLua(allEnts[i]);
        ecs::GameObject* gO = m_mngr->addGameObject({ecs::GROUP_EXAMPLE});

        // Ordenar componentes de la entidad
        std::vector<std::string> componentNames;
        lua_pushnil(entity);
        while (lua_next(entity, 0) != 0) // Recorro los componentes que hay la entidad
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
                }
                else m_data.insert({key, val});
                lua_pop(component, 1);
            }
            if (compName != "Name")
                m_componentFactory->addComponent(gO, compName, m_data); // (GameObject, tipo de componente, el map)
            // lua_pop(entity, 1);
            m_data.clear();
        }
        //m_scene_mngr->getSceneActive()->addObjects(gO);
        m_scene_mngr->getScene(t_scene)->addObjects(gO);
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
        .beginClass<ecs::Manager>("Manager")
        .addStaticFunction("getSceneManager", &ecs::Manager::instance)
        .addFunction("addGameObject", (&ecs::Manager::addGameObject))
        .addFunction("addComponent", (&ecs::Manager::addComponent<Camera>))
        .addFunction("addComponent", (&ecs::Manager::addComponent<Light>))
        .addFunction("addComponent", (&ecs::Manager::addComponent<MeshRenderer>))
        .addFunction("addComponent", (&ecs::Manager::addComponent<Transform>))
        .addFunction("addComponent", (&ecs::Manager::addComponent<RigidBody>))
        .addFunction("addComponent", (&ecs::Manager::addComponent<PlayerController>))
        .addFunction("addSystem", (&ecs::Manager::addSystem<RenderSystem>))
        .addFunction("addSystem", (&ecs::Manager::addSystem<PhysicsSystem>))
        //.addFunction("addSystem", (&ecs::Manager::addSystem<Flamingo::ParticleSystem>))
        .addFunction("addSystem", (&ecs::Manager::addSystem<AudioSystem>))
        .addFunction("addSystem", (&ecs::Manager::addSystem<UISystem>))
        .addFunction("getComponent", (&ecs::Manager::getComponent<Camera>))
        .addFunction("getComponent", (&ecs::Manager::getComponent<Light>))
        .addFunction("getComponent", (&ecs::Manager::getComponent<MeshRenderer>))
        .addFunction("getComponent", (&ecs::Manager::getComponent<Transform>))
        .addFunction("getComponent", (&ecs::Manager::getComponent<RigidBody>))
        .addFunction("getComponent", (&ecs::Manager::getComponent<PlayerController>))
        .addFunction("getEntities", (&ecs::Manager::getEntities))
        .addFunction("getHandler", (&ecs::Manager::getHandler))
        .addFunction("getSystem", (&ecs::Manager::getSystem<AudioSystem>))
        .addFunction("getSystem", (&ecs::Manager::getSystem<RenderSystem>))
        //.addFunction("getSystem", (&ecs::Manager::getSystem<Flamingo::ParticleSystem>))
        .addFunction("getSystem", (&ecs::Manager::getSystem<PhysicsSystem>))
        .addFunction("getSystem", (&ecs::Manager::getSystem<UISystem>))
        .addFunction("hasComponent", (&ecs::Manager::hasComponent<Camera>))
        .addFunction("hasComponent", (&ecs::Manager::hasComponent<MeshRenderer>))
        .addFunction("hasComponent", (&ecs::Manager::hasComponent<Light>))
        .addFunction("hasComponent", (&ecs::Manager::hasComponent<Transform>))
        .addFunction("hasComponent", (&ecs::Manager::hasComponent<RigidBody>))
        .addFunction("hasComponent", (&ecs::Manager::hasComponent<PlayerController>))
        .addFunction("isAlive", (&ecs::Manager::isAlive))
        .addFunction("setAlive", (&ecs::Manager::setAlive))
        .addFunction("removeComponent", (&ecs::Manager::removeComponent<Camera>))
        .addFunction("removeComponent", (&ecs::Manager::removeComponent<Light>))
        .addFunction("removeComponent", (&ecs::Manager::removeComponent<MeshRenderer>))
        .addFunction("removeComponent", (&ecs::Manager::removeComponent<Transform>))
        .addFunction("removeComponent", (&ecs::Manager::removeComponent<RigidBody>))
        .addFunction("removeComponent", (&ecs::Manager::removeComponent<PlayerController>))
        .addFunction("removeSystem", (&ecs::Manager::removeSystem<AudioSystem>))
        .addFunction("removeSystem", (&ecs::Manager::removeSystem<UISystem>))
        .addFunction("removeSystem", (&ecs::Manager::removeSystem<RenderSystem>))
        //.addFunction("removeSystem", (&ecs::Manager::removeSystem<Flamingo::ParticleSystem>))
        .addFunction("removeSystem", (&ecs::Manager::removeSystem<PhysicsSystem>))
        .addFunction("setAlive", (&ecs::Manager::setAlive))
        .addFunction("setHandler", (&ecs::Manager::setHandler))
        .endClass();
}

luabridge::LuaRef Flamingo::ScriptingSystem::getFromLua(std::string t_name)
{
    return luabridge::getGlobal(lua_state, t_name.c_str());
}
