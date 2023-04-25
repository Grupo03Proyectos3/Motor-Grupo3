#include "FlamingoCore.h"
#include "pch.h"

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

#include "ECS/SingletonECS.h"

// TEMPORAL -> TO DO : quitarlos
#include "Render/Light.h"
#include "Render/MeshRenderer.h"
#include <FlamingoBase/Transform.h>
#include <FlamingoUtils/SVector2.h>
#include <UI/UIElement.h>
// chapucilla
#include <Physics/PlayerController.h>
#include <Render/EnemyAI.h>

namespace Flamingo
{

    Flamingo::FlamingoCore::FlamingoCore()
    {
    }

    Flamingo::FlamingoCore::~FlamingoCore()
    {
    }

    bool Flamingo::FlamingoCore::FlamingoInit()
    {
        bool initSuccessful = true;

        Loader l;
        l.loadDirectories();

        std::string s = "Motor";
        ecs::Manager* m_mngr = ecs::Manager::instance();
        m_mngr->init();

        Flamingo::UISystem* ui_system = m_mngr->addSystem<Flamingo::UISystem>();
        RenderSystem* render_sys = m_mngr->addSystem<RenderSystem>(s);
        PhysicsSystem* physics_sys = m_mngr->addSystem<PhysicsSystem>();
        AudioSystem* audio_sys = m_mngr->addSystem<AudioSystem>();
        Flamingo::ScriptingSystem* scripting_sys = m_mngr->addSystem<Flamingo::ScriptingSystem>();

        ui_system->initContext();

        if (!scripting_sys->loadScene(m_first_scene))
        {
            std::cout << "No ha sido posible cargar la escena\n\n";
            return false;
        }

        SceneManager* sceneManager = render_sys->getSceneManager();
        Scene* mainScene = sceneManager->getSceneActive();
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
        auto tr_transform = ecs::AddComponent<Transform>(light_go);
        tr_transform->initValues(SVector3(0.0, 350.0, 200.0), SQuaternion(0.0, 0.0, 0.0, 1.0), SVector3(1.0, 1.0, 1.0));
        //MeshRenderer* cmp_mesh = ecs::AddComponent<MeshRenderer>(light_go);
        //cmp_mesh->initValues(nodo->createChildSceneNode(), mainScene->getSceneManger(), SVector3(1, 1, 1), "cube.mesh", "cuboluz");
        Light* cmp_light = ecs::AddComponent<Light>(light_go);
        cmp_light->initValues(mainScene->getSceneManger(), nodo->createChildSceneNode(), "myLight2");
        cmp_light->initComponent();
        cmp_light->setType(Light::DIRECTIONAL);
        cmp_light->setDirection(SVector3(0, -1, -1));
        cmp_light->setSpecularColour();
        cmp_light->setDiffuseColour();
        mainScene->addObjects(light_go);
        /*ecs::GameObject* light_go = m_mngr->addGameObject({ecs::GROUP_RENDER});
        light_go->setName("mylight");
        auto tr_transform = ecs::AddComponent<Transform>(light_go);
        tr_transform->initValues(SVector3(0.0, 0.0, 0.0), SQuaternion(0.0, 0.0, 0.0, 1.0), SVector3(1.0, 1.0, 1.0));
        Light* cmp_light = ecs::AddComponent<Light>(light_go);
        cmp_light->initValues(mainScene->getSceneManger(), nodo->createChildSceneNode(), "myLight");
        cmp_light->initComponent();
        cmp_light->setType(Light::DIRECTIONAL);
        cmp_light->setDirection(SVector3(0, -1, 0));
        cmp_light->setSpecularColour();
        cmp_light->setDiffuseColour();
        mainScene->addObjects(light_go);*/

        ecs::GameObject* UI = m_mngr->addGameObject({ecs::GROUP_UI});
        auto y = ecs::AddComponent<Transform>(UI);
        y->initValues();
        // y->setPosition({75, 75, 0});
        auto x = ecs::AddComponent<Flamingo::UIElement>(UI);
        x->setElementWidget("FlamingoDefaultUI/Button", "COSO");
        x->setText("ODIO CEGUI");
        x->setImage("NormalImage", "paco", "100.png");
        x->setImage("PushedImage", "paco2", "alonso1.png");
        x->setImage("HoverImage", "paco3", "esp.png");
        y->setPosition({50, 50, 0});
        y->setScale({100, 100, 0});

        // x->subscribeEvent(prueba, this);

        x->setActive(true);
        std::cout << "x: " << x->GetPosition().getX() << " ,y: " << x->GetPosition().getY() << "\n";

        // enemigos
        auto enemigo = m_mngr->getEntities(ecs::GROUP_RENDER);
        auto ene = m_mngr->addComponent<EnemyAI>(enemigo[2]);
        ene->initValues();
        m_mngr->addGameObjectToGroups(enemigo[2], {ecs::GROUP_SCRIPTING});
        return initSuccessful;
    }

    void Flamingo::FlamingoCore::FlamingoLoop()
    {
        bool motor_running = true;
        SVector3 m_velocity;
        // var pruebas
        int m_timeSinceLastDirectionChange = 0;
        //

        Flamingo::Timer* player_timer = new Flamingo::Timer();
        auto time = player_timer->getElapsedTime();
        auto dt = player_timer->getElapsedTime() - time;

        ecs::Manager* m_mngr = ecs::Manager::instance();
        auto ui_system = m_mngr->getSystem<Flamingo::UISystem>();
        auto render_sys = m_mngr->getSystem<RenderSystem>();

        auto& ihdlr = ih();

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
            // pruebas de enemigos

            auto enemigo = m_mngr->getEntities(ecs::GROUP_RENDER);
            auto controller = m_mngr->getComponent<PlayerController>(enemigo[0]);

            render_sys->manipulateCamera();
            controller->handleInput();

            /// MOVIMIENTO RANDOM ENEMIGOS COMENTADO
            // m_timeSinceLastDirectionChange += dt;
            //// SVector3 m_velocity;
            ////  Si ha pasado suficiente tiempo, cambia la direcci�n del enemigo
            // if (m_timeSinceLastDirectionChange >= 1000.0f)
            //{
            //     float x = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
            //     float y = 0;
            //     float z = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;

            //    //std::cout << "MARACUY�!!!!!!!!!!!! x: " << x << " y: " << y << " z: " << z << std::endl;

            //    // Crea un vector con estos valores y normal�zalo
            //    SVector3 direction(x, y, z);
            //    direction.normalize();
            //    //std::cout << "Normalice!!!!!!!!!!!! x: " << direction.getX() << " y: " << direction.getY() << " z: " << direction.getZ() << std::endl;

            //    // Genera una direcci�n aleatoria
            //    SVector3 randomDirection = direction;

            //    // Asigna una velocidad constante a lo largo de esta direcci�n
            //    m_velocity = randomDirection * 0.2f;

            //    // Reinicia el contador de tiempo
            //    m_timeSinceLastDirectionChange = 0;
            //}
            // test->translate(m_velocity * dt);

            // acaban pruebas

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
        return false;
    }

    void FlamingoCore::setFirstScene(const std::string& t_name)
    {
        m_first_scene = t_name;
    }

    std::string FlamingoCore::getFirstScene()
    {
        return m_first_scene;
    }

    void SetFirstScene(const std::string& t_scene_name)
    {
        Flamingo::FlamingoCore* core = Flamingo::FlamingoCore::instance();
        core->setFirstScene(t_scene_name);
    }

    void FlamingoCore::prueba()
    {
        std::cout << "PRUEBA\n";
        /* m_mng*/
    }
} // namespace Flamingo
