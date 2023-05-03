#include "FlamingoCore.h"

#include "FlamingoUtils/Timer.h"
#include "ResourcesLoader/Loader.h"

#include "ECS/InputHandler.h"
#include "ECS/Manager.h"

#include "Audio/AudioSystem.h"
#include "FlamingoBase/MapReader.h"
#include "Physics/PhysicsSystem.h"
#include "Render/RenderSystem.h"
#include "Scripting/ScriptingSystem.h"
#include "UI/UISystem.h"

// TEMPORAL -> TO DO : quitarlos
#include "FlamingoBase/SceneManager.h"
#include "Render/Animator.h"
#include "Render/Light.h"
#include "Render/MeshRenderer.h"
#include "Scripting/PruebaScript.h"
#include "Scripting/ScriptManager.h"
#include <ECS/InputHandlerContainer.h>
#include <FlamingoBase/Transform.h>
#include <FlamingoUtils/FlamingoKeys.h>
#include <FlamingoUtils/SVector2.h>
#include <Ogre.h>
#include <UI/UIElement.h>

namespace Flamingo
{

    FlamingoCore* FlamingoCore::m_instance = nullptr;

    Flamingo::FlamingoCore::FlamingoCore()
    {
        m_scenes_to_load.clear();
        initialized = false;
        m_motor_running = false;
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

        // //Cámara y Luces iniciales
         auto cam = mainScene->getObject("myCamera");
         auto m_camera = m_mngr->getComponent<Flamingo::Camera>(cam);
        //
        // m_camera->setViewPortBackgroundColour(SColor(0.3f, 0.2f, 0.6f));
        // m_camera->lookAt(SVector3(0, 0, 0), STransformSpace::LOCAL);
        // m_camera->setNearClipDistance(1);
        // m_camera->setFarClipDistance(100000);
        //// m_camera->setTarget(mainScene->getObject("Arbol"));
        // //t->translate({-15000, 0, 0}, LOCAL);
         render_sys->setMainCamera(m_camera);

         auto light = mainScene->getObject("mylight");
         auto cmp_light = m_mngr->getComponent<Flamingo::Light>(light);
         cmp_light->setType(Light::DIRECTIONAL);
         cmp_light->setDirection(SVector3(0, -1, -1));
         cmp_light->setSpecularColour();
         cmp_light->setDiffuseColour();
        //
        // initialized = true;
        return true;
    }

    void Flamingo::FlamingoCore::FlamingoLoop()
    {
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

        m_motor_running = true;
        // ScriptManager::instance()->startComponents();
        while (m_motor_running && !render_sys->getWindow()->isWindowClosed())
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

            render_sys->manipulateCamera();

            ihdlr.refresh();

            m_mngr->refresh();
            m_mngr->flushMessages();
        }
    
        delete player_timer;
    }

    bool Flamingo::FlamingoCore::FlamingoExit()
    {
        Manager::instance()->getSystem<RenderSystem>()->getWindow()->closeWindow();
        Manager::instance()->getSystem<UISystem>()->eraseContext();

        Manager::close();
        InputHandler::close();
        InputHandlerContainer::close();
        ScriptManager::instance()->deleteScriptsTemplates();
        ScriptManager::close();

        if (!initialized)
        {
            return false;
        }

        initialized = false;
        return true;
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

    void FlamingoCore::endRunning()
    {
        m_motor_running = false;
    }

    void FlamingoCore::addGameScript(std::string t_n, BehaviourScript* t_s)
    {
        auto fCore = Flamingo::ScriptManager::instance();
        fCore->addGameScript(t_n, t_s);
    }
} // namespace Flamingo
