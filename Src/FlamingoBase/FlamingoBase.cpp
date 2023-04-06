#include "FlamingoBase.h"

// Audio
#include "Audio/AudioSystem.h"

// Carga de mapas
#include "MapReader.h"
#include "ResourcesLoader/Loader.h"

// ECS
#include "ECS/Manager.h"

// Físicas
#include "Physics/PhysicsSystem.h"

// FlamingoBase
#include "FlamingoUtils/Timer.h"

// LUA
#include <Lua/LuaSystem.h>

// Render3D
#include "Render/RenderSystem.h"

// Debug de memory leaks
#include <crtdbg.h>

// INCLUDES TEMPORALES PARA LA ESCENA DE JUEGO
#include <Render/Light.h>

namespace Flamingo
{
    FlamingoBase::FlamingoBase()
    {
    }

    FlamingoBase::~FlamingoBase()
    {
    }

    bool FlamingoBase::loadScene(RenderSystem* t_sys)
    {
        try
        {
            MapReader* map_reader = new MapReader(t_sys);

            map_reader->readMap("Assets/Maps/mapPrueba.json");

            delete map_reader;
        }
        catch (...)
        {
            return false;
        }

        return true;
    }

    bool FlamingoBase::FlamingoInit()
    {
        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

        Loader l;
        l.loadDirectories();

        std::string s = "Motor";
        ecs::Manager* m_mngr = ecs::Manager::instance();
        m_mngr->init();

        RenderSystem* render_sys = m_mngr->addSystem<RenderSystem>(s);
        PhysicsSystem* physics_sys = m_mngr->addSystem<PhysicsSystem>();
        AudioSystem* audio_sys = m_mngr->addSystem<AudioSystem>();
        Flamingo::LuaSystem* lua_system = m_mngr->addSystem<Flamingo::LuaSystem>();

        if (!loadScene(render_sys))
        {
            std::cout << "No ha sido posible cargar la escena";
            return false;
        }

        auto nodo = render_sys->getSceneManager()->getSceneActive()->getSceneRoot();
        ecs::GameObject* cam_go = m_mngr->addGameObject({ecs::GROUP_RENDER});
        auto m_camera = ecs::AddComponent<Camera>(cam_go);
        lua_system->addCameraToLua(m_camera, "cam1"); // Añado la referenacia a LUA
        m_camera->initValues(render_sys->getSceneManager()->getSceneActive()->getSceneManger(), nodo->createChildSceneNode(), render_sys->getWindow(), "myCamera");
        m_camera->initComponent();
        m_camera->setViewPortBackgroundColour(Ogre::ColourValue(0.3f, 0.2f, 0.6f));
        // Ogre::ColourValue color = Ogre::ColourValue(0.0, 0.0, 0.0);
        // lua_system->pushColorToLua(color, "color");
        // lua_system->callLuaFunction("changeVPcolor");
        bool autoradio = true;
        lua_system->pushBool(autoradio, "autoradio");
        lua_system->callLuaFunction("autoAspectRatio");

        m_camera->lookAt(SVector3(0, 0, 0), Camera::WORLD);
        m_camera->setNearClipDistance(1);
        m_camera->setFarClipDistance(10000);
        render_sys->getSceneManager()->getSceneActive()->addObjects(cam_go);

        ecs::GameObject* light_go = m_mngr->addGameObject({ecs::GROUP_RENDER});
        Light* cmp_light = ecs::AddComponent<Light>(light_go);
        cmp_light->initValues(render_sys->getSceneManager()->getSceneActive()->getSceneManger(), nodo->createChildSceneNode(), "myLight");
        cmp_light->initComponent();
        cmp_light->setType(Light::DIRECTIONAL);
        SVector3 direction = SVector3(-1, -1, 0);
        // direction *= -1;
        cmp_light->setDirection(direction);
        cmp_light->setSpecularColour();
        cmp_light->setDiffuseColour();
        render_sys->getSceneManager()->getSceneActive()->addObjects(light_go);

        return true;
    }

    void FlamingoBase::FlamingoLoop()
    {
        bool motor_running = true;

        Flamingo::Timer* player_timer = new Flamingo::Timer();
        auto time = player_timer->getElapsedTime();
        auto dt = player_timer->getElapsedTime() - time;

        ecs::Manager* m_mngr = ecs::Manager::instance();

        auto render_sys = m_mngr->getSystem<RenderSystem>();

        auto& ihldr = ih();

        while (motor_running && !render_sys->getWindow()->isWindowClosed())
        {
            // Delta time en milisegundos
            dt = player_timer->getElapsedTime() - time;
            // Tiempo transcurrido desde el inicio del programa en milisegundos
            time = player_timer->getElapsedTime();

            // leer entrada

            for (auto sys : m_mngr->getSystems())
            {
                if (sys)
                {
                    sys->update(dt);
                }
            }

            // m_controller->handleInput();
            render_sys->manipulateCamera();
            ihldr.refresh();

            m_mngr->refresh();
            m_mngr->flushMessages();
        }
        //  ui_sys->eraseContext();
        render_sys->getWindow()->closeWindow();
        delete player_timer;

        //_CrtDumpMemoryLeaks();
    }

    bool FlamingoBase::FlamingoExit()
    {
        return false;
    }
} // namespace Flamingo
