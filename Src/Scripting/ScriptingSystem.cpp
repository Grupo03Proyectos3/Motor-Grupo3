#include "ScriptingSystem.h"

extern "C"
{
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"
}
#include <LuaBridge\LuaBridge.h>

#include "ECS/GameObject.h"
#include "ECS/Manager.h"
#include "ECS/ManagerFunctions.h"
#include "Render/RenderSystem.h"

//FACTORIAS
#include "FlamingoBase/AudioFactory.h"
#include "FlamingoBase/ComponentsFactory.h"
#include "FlamingoBase/MeshRendererFactory.h"
#include "FlamingoBase/RigidbodyFactory.h"
#include "FlamingoBase/TransformFactory.h"
#include "FlamingoBase/LightFactory.h"
#include "FlamingoBase/UIElementFactory.h"
#include "FlamingoBase/CameraFactory.h"
#include "FlamingoBase/AnimatorFactory.h"
#include "FlamingoBase/ScriptFactory.h"

namespace Flamingo
{

    ScriptingSystem::ScriptingSystem()
        : m_scene_mngr(FlamingoSceneManager())
    {
        m_componentFactory = ComponentsFactory::instance();
        m_mngr = Manager::instance();
    }

    ScriptingSystem::~ScriptingSystem()
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
    void ScriptingSystem::addFactories()
    {
        auto renderSystem = m_mngr->getSystem<Flamingo::RenderSystem>();
        m_componentFactory->addFactory("MeshRenderer", new MeshRendererFactory(renderSystem));
        m_componentFactory->addFactory("RigidBody", new RigidBodyFactory());
        m_componentFactory->addFactory("Transform", new TransformFactory());
        m_componentFactory->addFactory("Light", new LightFactory(renderSystem));
        m_componentFactory->addFactory("Camera", new CameraFactory(renderSystem));
        m_componentFactory->addFactory("Animator", new AnimatorFactory(renderSystem));
        m_componentFactory->addFactory("Scripts", new ScriptFactory());
        m_componentFactory->addFactory("AudioSource", new AudioFactory());
        m_componentFactory->addFactory("UIElement", new UIElementFactory());
    }

    void ScriptingSystem::initSystem()
    {
        addFactories();
        // crear un Lua state
        lua_state = luaL_newstate();
        // cargar las standard libs
        luaL_openlibs(lua_state);
    }

    void ScriptingSystem::update(float t_delta_time)
    {
        //Gestiona solo las entidades del grupo scripting
        for (auto gO : Manager::instance()->getEntities(GROUP_SCRIPTING))
        {
            if (gO == nullptr || !gO->getAlive() || !gO->getActive())
                continue;

            for (auto c : gO->getCurrentComponents())
            {
                auto s = dynamic_cast<BehaviourScript*>(c.second);
                if (s != nullptr)
                {
                    s->update(t_delta_time);
                }
            }
        }
    }

    void ScriptingSystem::recieve(const Message& t_m)
    {
        switch (t_m.id)
        {
            case MSG_COLLISION_STAY:
            {
                // Si alguno de los GameObjects implicados en la colision tiene BehaviourScript,
                // se llama a su OnCollisionStay() para ejecutar la accion determinada por el usuario.
                for (auto c : t_m.collision.obj1->getCurrentComponents())
                {
                    auto s = dynamic_cast<BehaviourScript*>(c.second);
                    if (s != nullptr && s->gameObject()->getActive() && s->gameObject()->getAlive())
                    {
                        s->onCollisionStay(t_m.collision.obj2);
                    }
                }
                for (auto c : t_m.collision.obj2->getCurrentComponents())
                {
                    auto s = dynamic_cast<BehaviourScript*>(c.second);
                    if (s != nullptr && s->gameObject()->getActive() && s->gameObject()->getAlive())
                    {
                        s->onCollisionStay(t_m.collision.obj1);
                    }
                }
                break;
            }
            case MSG_COLLISION_ENTER:
            {
                for (auto c : t_m.collision.obj1->getCurrentComponents())
                {
                    auto s = dynamic_cast<BehaviourScript*>(c.second);
                    if (s != nullptr && s->gameObject()->getActive() && s->gameObject()->getAlive())
                    {
                        s->onCollisionEnter(t_m.collision.obj2);
                    }
                }
                for (auto c : t_m.collision.obj2->getCurrentComponents())
                {
                    auto s = dynamic_cast<BehaviourScript*>(c.second);
                    if (s != nullptr && s->gameObject()->getActive() && s->gameObject()->getAlive())
                    {
                        s->onCollisionEnter(t_m.collision.obj1);
                    }
                }
                break;
            }
            case MSG_COLLIISION_EXIT:
            {
                for (auto c : t_m.collision.obj1->getCurrentComponents())
                {
                    auto s = dynamic_cast<BehaviourScript*>(c.second);
                    if (s != nullptr && s->gameObject()->getActive() && s->gameObject()->getAlive())
                    {
                        s->onCollisionExit(t_m.collision.obj2);
                    }
                }
                for (auto c : t_m.collision.obj2->getCurrentComponents())
                {
                    auto s = dynamic_cast<BehaviourScript*>(c.second);
                    if (s != nullptr && s->gameObject()->getActive() && s->gameObject()->getAlive())
                    {
                        s->onCollisionExit(t_m.collision.obj1);
                    }
                }
                break;
            }
            default:
                break;
        }
    }

    void ScriptingSystem::loadObjects(std::string t_scene)
    {
        readScript(t_scene);
        luabridge::LuaRef allEnts = getFromLua("entities");
        int n = allEnts.length();
        // Recorro las entidades del script de lua
        for (int i = 1; i <= n; i++)
        {
            luabridge::LuaRef entity = getFromLua(allEnts[i]);
            GameObject* gO = m_mngr->addGameObject({GROUP_EXAMPLE});

            lua_pushnil(entity);
            if (entity.isNil())
                throw std::exception("ERROR loading the scene");

            while (!entity.isNil() && lua_next(entity, 0) != 0)
            {
                std::string compName = lua_tostring(entity, -2); // Tipo de componente
                luabridge::LuaRef component = entity[compName];
                lua_pushnil(component);

                while (lua_next(component, 0) != 0) // Recorro los atributos del componente
                {
                    std::string key, val;
                    if (compName == "Scripts")
                    {
                        key = "t_scriptName";
                        val = lua_tostring(entity, -1); // Valor del atributo
                        m_data.insert({key, val});
                        m_componentFactory->addComponent(gO, compName, m_data);
                        m_data.clear();
                    }
                    else if (compName == "Name")
                    {
                        key = lua_tostring(entity, -2); // Nombre del atributo
                        val = lua_tostring(entity, -1); // Valor del atributo
                        gO->setName(val);
                        if (val == "player")
                        {
                            m_mngr->setHandler(_hdr_player, gO);
                        }
                    }
                    else
                    {
                        key = lua_tostring(entity, -2); // Nombre del atributo
                        val = lua_tostring(entity, -1); // Valor del atributo
                        m_data.insert({key, val});
                    }

                    lua_pop(component, 1);
                }
                if (compName != "Name" && compName != "Scripts")
                    m_componentFactory->addComponent(gO, compName, m_data); // (GameObject, tipo de componente, el map)

                lua_pop(entity, 1);
                m_data.clear();
            }
            m_scene_mngr.getScene(t_scene)->addObjects(gO); // Añadir el objeto a la escena
          

            for (auto c : gO->getCurrentComponents())
            {
                c.second->initComponent();
            }

              if (!m_scene_mngr.getScene(t_scene)->isSceneActive())
                gO->setActive(false);
        }
    }

    lua_State* ScriptingSystem::getLuaState()
    {
        return lua_state;
    }

    void ScriptingSystem::readScript(const std::string& t_name)
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
            // Quita el mensage de error de lua
            lua_pop(lua_state, 1);
            throw std::runtime_error("[LUA ERROR] Invalid map: " + (std::string)lua_tostring(lua_state, -1));
        }
    }

    void ScriptingSystem::callLuaFunction(std::string t_name)
    {
        luabridge::LuaRef fun = getFromLua(t_name);
        fun();
    }

    bool ScriptingSystem::loadScene(std::string t_scene, bool t_first)
    {
        if (t_scene.empty())
        {
            return false;
        }
        auto myScene = m_scene_mngr.createScene(t_scene, true);

        m_mngr->getSystem<RenderSystem>()->addShadersScene(myScene);
       
        SceneManager::instance()->setSceneToAttach(myScene);

        loadObjects(t_scene); //Carga todos los objetos desde un script de lua

        return true; //Si todo va bien devuelve true
    }

    luabridge::LuaRef ScriptingSystem::getFromLua(std::string t_name)
    {
        return luabridge::getGlobal(lua_state, t_name.c_str());
    }
} // namespace Flamingo