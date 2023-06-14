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

        if (readLua)
        {
            bool load_success = false;
            std::string loading_scene = "";
            for (auto scene : m_scenes_to_load)
            {
                loading_scene = scene;
                load_success = scripting_sys->loadScene(scene);
            }

            if (!load_success)
            {
                throw std::runtime_error("ERROR: Failed loading scene " + loading_scene + "\n");
            }
        }
        else
        {
            std::string loading_scene = "";
            int index = 0;
            mapReader = new MapReader(render_sys);

            for (auto scene : m_scenes_to_load)
            {
                auto p = sceneManager->createScene("escenaJ" + std::to_string(index), true);
                index++;
                mapReader->readMap(scene, p);
            }
        }

        if (m_first_scene.empty())
        {
            throw std::runtime_error("ERROR: No scene set as first.\n");
        }

        sceneManager->setSceneActive(m_first_scene);
        sceneManager->startScene(m_first_scene);
        initialized = true;
        
        //Initialize visual debugging after creating scenes
        physics_sys->initDebugMode();

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
         
            ihdlr.update(dt);

            m_mngr->refresh();
            m_mngr->flushMessages();

            SceneManager::instance()->reloadScene();
        }

        delete player_timer;
    }

    bool Flamingo::FlamingoCore::FlamingoExit()
    {
        if (!initialized)
        {
            return false;
        }

        Manager::instance()->freeAllGameObjects();
      
        InputHandler::close();
        InputHandlerContainer::close();
        ScriptManager::instance()->deleteScriptsTemplates();
        ScriptManager::close();

        if (mapReader != nullptr)
            delete mapReader;


        initialized = false;

        SceneManager::close();
        Manager::instance()->getSystem<RenderSystem>()->getWindow()->closeWindow();
        Manager::instance()->getSystem<UISystem>()->eraseContext();    
        Manager::close();

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

    void FlamingoCore::setLUA(bool lua)
    {
        readLua = lua;
    }

    void FlamingoCore::endRunning()
    {
        m_motor_running = false;
    }

    bool FlamingoCore::addGameScript(std::string t_n, BehaviourScript* t_s)
    {
        auto fCore = Flamingo::ScriptManager::instance();
        return fCore->addGameScript(t_n, t_s);
    }
} // namespace Flamingo
