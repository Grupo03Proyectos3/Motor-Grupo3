#include "FlamingoBase.h"

// Audio
#include "Audio/AudioSystem.h"

// Carga de mapas
#include "MapReader.h"
#include "ResourcesLoader/Loader.h"

// ECS
#include "ECS/Manager.h"

// F�sicas
#include "Physics/PhysicsSystem.h"

// FlamingoBase
#include "FlamingoUtils/Timer.h"

// LUA
#include <Lua/LuaSystem.h>

// Render3D
#include "Render/RenderSystem.h"

// UI
#include "UI/UISystem.h"

// Debug de memory leaks
#include <crtdbg.h>

// INCLUDES TEMPORALES PARA LA ESCENA DE JUEGO
#include <Render/Light.h>
#include <UI/UIElement.h>
#include <functional>
#include <iostream>

namespace Flamingo
{
    FlamingoBase::FlamingoBase()
    {
    }

    FlamingoBase::~FlamingoBase()
    {
    }


    bool FlamingoBase::FlamingoInit()
    {
        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

        Loader l;
        l.loadDirectories();

        std::string s = "Motor";
        ecs::Manager* m_mngr = ecs::Manager::instance();
        m_mngr->init();

        Flamingo::UISystem* ui_system = m_mngr->addSystem<Flamingo::UISystem>();
        RenderSystem* render_sys = m_mngr->addSystem<RenderSystem>(s);
        PhysicsSystem* physics_sys = m_mngr->addSystem<PhysicsSystem>();
        AudioSystem* audio_sys = m_mngr->addSystem<AudioSystem>();
        Flamingo::LuaSystem* lua_system = m_mngr->addSystem<Flamingo::LuaSystem>(render_sys);

        ui_system->initContext();

        SceneManager* sceneManager = render_sys->getSceneManager();
        Scene* mainScene = sceneManager->getSceneActive();

        //if (!loadScene(render_sys, mainScene))
        //{
        //    std::cout << "No ha sido posible cargar la escena";
        //    return false;
        //}

        lua_system->loadScene();

        auto nodo = mainScene->getSceneRoot();

        ecs::GameObject* cam_go = m_mngr->addGameObject({ecs::GROUP_RENDER});
        cam_go->setName("myCamera");
        auto m_camera = ecs::AddComponent<Camera>(cam_go);
        m_camera->initValues(mainScene->getSceneManger(), nodo->createChildSceneNode(), render_sys->getWindow(), "myCamera");
        m_camera->initComponent();
        m_camera->setViewPortBackgroundColour(SColor(0.3f, 0.2f, 0.6f));

        m_camera->lookAt(SVector3(0, 0, 0), Camera::WORLD);
        m_camera->setNearClipDistance(1);
        m_camera->setFarClipDistance(10000);
        mainScene->addObjects(cam_go);

        ecs::GameObject* light_go = m_mngr->addGameObject({ecs::GROUP_RENDER});
        light_go->setName("mylight");
        Light* cmp_light = ecs::AddComponent<Light>(light_go);
        cmp_light->initValues(mainScene->getSceneManger(), nodo->createChildSceneNode(), "myLight");
        cmp_light->initComponent();
        cmp_light->setType(Light::DIRECTIONAL);
        cmp_light->setDirection(SVector3(-1, -1, 0));
        cmp_light->setSpecularColour();
        cmp_light->setDiffuseColour();
        mainScene->addObjects(light_go);

        // PRUEBAS DE UI
        ecs::GameObject* UI = m_mngr->addGameObject({ecs::GROUP_UI});
        auto y = ecs::AddComponent<Transform>(UI);
        y->initValues();
        y->setPosition({75, 75, 0});
        auto x = ecs::AddComponent<Flamingo::UIElement>(UI);
        x->setElementWidget("TaharezLook/Label", "COSO");
        x->setText("ODIO CEGUI");
        // x->setImage("", "");
        y->setPosition({0, 0, 0});
        y->setScale({50, 50, 0});

        /*  std::function<void()> f_display = hola;
          x->subs(f_display);*/

        /*  x->subscribeEvent(hol1a);*/
        /*
           std::function<void()> funcionEnlazada = prueba1;
           {
               std::cout << "fuegirola" << std::endl;
           };

           x->subs(prueba1);*/

        /* bool (FlamingoBase::* pfunc)() = &FlamingoBase::prueba2;
          x->subscribeEvent(FlamingoBase::prueba2);*/

        // ecs::GameObject* UI2 = m_mngr->addGameObject({ecs::GROUP_UI});
        // auto y2 = ecs::AddComponent<Transform>(UI2);
        // y2->initValues();
        // y2->setPosition({75, 75, 0});
        // auto x2 = ecs::AddComponent<Flamingo::UIElement>(UI2);
        // x2->setElementWidget("TaharezLook/Label", "COSO2");
        // x2->setText("ODIO CEGUI");
        // y2->setPosition({200, 200, 0});
        //
        // x->addChild(x2);
        // PRUEBAS DE UI

        /*sceneManager->createScene("Menu", true);
        mainScene = sceneManager->getSceneActive();
        nodo = mainScene->getSceneRoot();

        cam_go = m_mngr->addGameObject({ecs::GROUP_RENDER});
        m_camera = ecs::AddComponent<Camera>(cam_go);
        m_camera->initValues(mainScene->getSceneManger(), nodo->createChildSceneNode(), render_sys->getWindow(), "myCamera2dsa");
        m_camera->initComponent();
        m_camera->setViewPortBackgroundColour(SColor(0.8f, 0.05f, 0.9f));

        m_camera->lookAt(SVector3(0, 0, 0), Camera::WORLD);
        m_camera->setNearClipDistance(1);
        m_camera->setFarClipDistance(10000);
        mainScene->addObjects(cam_go);

        light_go = m_mngr->addGameObject({ecs::GROUP_RENDER});
        light_go->setName("mylight2");
        cmp_light = ecs::AddComponent<Light>(light_go);
        cmp_light->initValues(mainScene->getSceneManger(), nodo->createChildSceneNode(), "myLight2");
        cmp_light->initComponent();
        cmp_light->setType(Light::DIRECTIONAL);
        cmp_light->setDirection(SVector3(-1, -1, 0));
        cmp_light->setSpecularColour();
        cmp_light->setDiffuseColour();
        mainScene->addObjects(light_go);

        ecs::GameObject* cube_go = m_mngr->addGameObject({ecs::GROUP_RENDER});
        cube_go->setName("fgddfgdfg");
        Transform* cmp_tr2 = ecs::AddComponent<Transform>(cube_go);
        cmp_tr2->setPosition(SVector3(0, 200, 0));
        cmp_tr2->setScale({50, 50, 50});
        auto cmp2 = ecs::AddComponent<MeshRenderer>(cube_go);
        cmp2->initValues(nodo->createChildSceneNode(), mainScene->getSceneManger(), SVector3(50, 50, 50), "Torus.mesh", "CubeEntity");
        cmp2->changeMaterial("Prueba/MichaelScott");
        mainScene->addObjects(cube_go);*/

        return true;
    }

    void FlamingoBase::FlamingoLoop()
    {
        bool motor_running = true;

        Flamingo::Timer* player_timer = new Flamingo::Timer();
        auto time = player_timer->getElapsedTime();
        auto dt = player_timer->getElapsedTime() - time;

        ecs::Manager* m_mngr = ecs::Manager::instance();
        auto ui_system = m_mngr->getSystem<Flamingo::UISystem>();
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
        ui_system->eraseContext();
        render_sys->getWindow()->closeWindow();
        delete player_timer;

        //_CrtDumpMemoryLeaks();
    }

    bool FlamingoBase::FlamingoExit()
    {
        return false;
    }

    bool FlamingoBase::loadScene(RenderSystem* t_render_sys, Scene* t_scene)
    {
        try
        {
            MapReader* map_reader = new MapReader(t_render_sys);

            map_reader->readMap("Assets/Maps/mapPrueba.json", t_scene);

            delete map_reader;
        }
        catch (...)
        {
            return false;
        }

        return true;
    }

  

} // namespace Flamingo
