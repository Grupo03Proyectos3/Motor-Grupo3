#include "FlamingoCore.h"

#include "FlamingoUtils/Timer.h"
#include "ResourcesLoader/Loader.h"

#include "ECS/InputHandler.h"
#include "ECS/Manager.h"

#include "Audio/AudioSystem.h"
#include "FlamingoBase/MapReader.h"
#include "Lua/ScriptingSystem.h"
#include "Physics/PhysicsSystem.h"
#include "Render/RenderSystem.h"
#include "UI/UISystem.h"

// TEMPORAL -> TO DO : quitarlos
#include "FlamingoBase/SceneManager.h"
#include "Lua/PruebaScript.h"
#include "Lua/ScriptManager.h"
#include "Render/Animator.h"
#include "Render/Light.h"
#include "Render/MeshRenderer.h"
#include <ECS/InputHandlerContainer.h>
#include <FlamingoBase/Transform.h>
#include <FlamingoUtils/FlamingoKeys.h>
#include <FlamingoUtils/SVector2.h>
#include <Ogre.h>
#include <UI/UIElement.h>
// chapucilla
#include <Physics/PlayerController.h>
#include <Render/EnemyAI.h>

namespace Flamingo
{

    FlamingoCore* FlamingoCore::m_instance = nullptr;

    Flamingo::FlamingoCore::FlamingoCore()
    {
        m_scenes_to_load.clear();
    }

    Flamingo::FlamingoCore::~FlamingoCore()
    {
    }

    bool Flamingo::FlamingoCore::FlamingoInit()
    {
        if (m_scenes_to_load.empty())
        {
            throw std::runtime_error("ERROR: No scenes set to load.\n");
        }

        bool initSuccessful = true;

        Loader l;
        l.loadDirectories();

        std::string s = "Motor";
        Manager* m_mngr = Manager::instance();
        m_mngr->init();
        SceneManager* sceneManager = getSceneManager();
        Flamingo::UISystem* ui_system = m_mngr->addSystem<Flamingo::UISystem>();
        RenderSystem* render_sys = m_mngr->addSystem<RenderSystem>(s);
        ui_system->initContext();
        sceneManager->initManager("SceneManager", m_mngr);
        PhysicsSystem* physics_sys = m_mngr->addSystem<PhysicsSystem>();
        AudioSystem* audio_sys = m_mngr->addSystem<AudioSystem>();
        Flamingo::ScriptingSystem* scripting_sys = m_mngr->addSystem<Flamingo::ScriptingSystem>();
        render_sys->inicializarShaders();

        bool load_success = false;
        std::string loading_scene = "";
        for (auto scene : m_scenes_to_load)
        {
            loading_scene = scene;
            load_success = scripting_sys->loadScene(scene);
            ScriptManager::instance()->startComponents();
        }

        if (!load_success)
        {
            throw std::runtime_error("ERROR: Failed loading scene " + loading_scene + "\n");
        }

        sceneManager->setSceneActive(m_first_scene);

        Scene* mainScene = sceneManager->getSceneActive();
        auto nodo = mainScene->getSceneRoot();
        
        /*GameObject* UI = m_mngr->addGameObject({GROUP_UI});
        auto y = addComponent<Transform>(UI);
        
        y->initValues();
        auto x = addComponent<Flamingo::UIElement>(UI);
        x->setElementWidget("FlamingoDefaultUI/Button", "COSO");
        x->setText("ODIO CEGUI");
        x->setImage("NormalImage", "paco", "100.png");
        x->setImage("PushedImage", "paco2", "alonso1.png");
        x->setImage("HoverImage", "paco3", "esp.png");
        y->setPosition({50, 50, 0});
        y->setScale({100, 100, 0});
        x->subscribeEvent(&FlamingoCore::prueba, this);
        x->setActive(true);*/

        /*  ScriptManager::instance()->addGameScript("PruebaScript", new PruebaScript());
          Flamingo::GameObject* g = m_mngr->addGameObject();
          Flamingo::addComponent<Transform>(g);
          Flamingo::addComponent<PruebaScript>(g);
          if (Flamingo::hasComponent<PruebaScript>(g) && !Flamingo::hasComponent<EnemyAI>(g))
              std::cout << "hasComponent \n";*/

        // TO DO: eliminar despues de comprobar las animaciones
        // auto d = mainScene->getObject("dragon");
        // auto a = m_mngr->getComponent<Flamingo::Animator>(d);
        // a->setAnimation("idle", true, true);

        // enemigos
        // auto enemigo = m_mngr->getEntities(GROUP_RENDER);
        // auto ene = m_mngr->addComponent<EnemyAI>(enemigo[2]);
        // ene->initValues();
        // m_mngr->addGameObjectToGroups(enemigo[2], {GROUP_SCRIPTING});

        // ecs::GameObject* p = m_mngr->addGameObject({ecs::GROUP_RENDER});
        //  auto t = ecs::AddComponent<Transform>(p);
        //  t->initValues(SVector3(0 , 100, 0));
        //  auto r = ecs::AddComponent<MeshRenderer>(p);
        //
       
        auto cam = mainScene->getObject("myCamera");
        auto m_camera = m_mngr->getComponent<Flamingo::Camera>(cam);
        
        m_camera->setViewPortBackgroundColour(SColor(0.3f, 0.2f, 0.6f));
        m_camera->lookAt(SVector3(0, 0, 0), STransformSpace::LOCAL);
        m_camera->setNearClipDistance(1);
        m_camera->setFarClipDistance(100000);
       // m_camera->setTarget(mainScene->getObject("Arbol"));
        //t->translate({-15000, 0, 0}, LOCAL);
        render_sys->setMainCamera(m_camera);

        auto light = mainScene->getObject("mylight");
        auto cmp_light = m_mngr->getComponent<Flamingo::Light>(light);
        cmp_light->setType(Light::DIRECTIONAL);
        cmp_light->setDirection(SVector3(0, -1, -1));
        cmp_light->setSpecularColour();
        cmp_light->setDiffuseColour();
       
        return initSuccessful;
    }

    void Flamingo::FlamingoCore::FlamingoLoop()
    {
        bool motor_running = true;
        SVector3 m_velocity;
        // var pruebas
        int m_timeSinceLastDirectionChange = 0;

        Flamingo::Timer* player_timer = new Flamingo::Timer();
        auto time = player_timer->getElapsedTime();
        auto dt = player_timer->getElapsedTime() - time;

        Manager* m_mngr = Manager::instance();
        auto ui_system = m_mngr->getSystem<Flamingo::UISystem>();
        auto render_sys = m_mngr->getSystem<RenderSystem>();
        auto physic_sys = m_mngr->getSystem<PhysicsSystem>();
        auto script_sys = m_mngr->getSystem<ScriptingSystem>();
        auto audio_sys = m_mngr->getSystem<AudioSystem>();

        auto& ihdlr = ih();

        //ScriptManager::instance()->startComponents();
        while (motor_running && !render_sys->getWindow()->isWindowClosed())
        {
            // Delta time en milisegundos
            dt = player_timer->getElapsedTime() - time;
            // Tiempo transcurrido desde el inicio del programa en milisegundos
            time = player_timer->getElapsedTime();

            // Update de los sistemas
            script_sys->update(dt);
            physic_sys->update(dt);
            audio_sys->update(dt);
            render_sys->update(dt);
            ui_system->update(dt);

            // pruebas de enemigos

            auto enemigo = m_mngr->getEntities(GROUP_RENDER);
            auto controller = m_mngr->getComponent<PlayerController>(enemigo[0]);

            controller->handleInput();
            render_sys->manipulateCamera();

            ihdlr.refresh();

            m_mngr->refresh();
            m_mngr->flushMessages();
        }
        ui_system->eraseContext();
        render_sys->getWindow()->closeWindow();
        delete player_timer;
    }

    bool Flamingo::FlamingoCore::FlamingoExit()
    {
        Manager::close();
        InputHandler::close();
        InputHandlerContainer::close();

        return false;
    }

    void FlamingoCore::setFirstScene(std::string t_name)
    {
        m_first_scene = t_name;
    }

    void FlamingoCore::addSceneToLoad(std::string t_name)
    {
        m_scenes_to_load.push_back(t_name);
    }

    std::string FlamingoCore::getFirstScene()
    {
        return m_first_scene;
    }

    FlamingoCore* FlamingoCore::instance()
    {
        if (m_instance == nullptr)
        {
            m_instance = new FlamingoCore();
        }
        return m_instance;
    }

    Manager* FlamingoCore::getManager()
    {
        return Manager::instance();
    }

    SceneManager* FlamingoCore::getSceneManager()
    {
        return SceneManager::instance();
    }

    void FlamingoCore::addGameScript(std::string t_n, BehaviourScript* t_s)
    {
        auto fCore = Flamingo::ScriptManager::instance();
        fCore->addGameScript(t_n, t_s);
    }
} // namespace Flamingo
