//#include "MiFlamingo.h"
//
//using namespace Flamingo;
//
//MiFlamingo::MiFlamingo()
//{
//}
//
//MiFlamingo::~MiFlamingo()
//{
//}
//void MiFlamingo::prueba()
//{
//    ecs::GameObject* cube_go = m_mngr->addGameObject(render_sys->getSceneManager()->getSceneActive()->getSceneRoot(), {ecs::GROUP_RENDER});
//    auto cmp2 = ecs::AddComponent<MeshRenderer>(cube_go);
//    cmp2->initValues(cube_go->getNode(), render_sys->getSceneManager()->getSceneActive()->getSceneManger(), "cube.mesh", "CubeEntity");
//    cmp2->changeMaterial("Prueba/MichaelScott");
//    Transform* cmp_tr2 = ecs::AddComponent<Transform>(cube_go);
//    cmp_tr2->initValues(cube_go->getNode());
//    cmp_tr2->setPosition(SVector3(0, 0, 0));
//    render_sys->getSceneManager()->getSceneActive()->addObjects(cube_go);
//
//    ecs::GameObject* light_go = m_mngr->addGameObject(render_sys->getSceneManager()->getSceneActive()->getSceneRoot(), {ecs::GROUP_RENDER});
//    Light* cmp_light = ecs::AddComponent<Light>(light_go);
//    cmp_light->initValues(render_sys->getSceneManager()->getSceneActive()->getSceneManger(), light_go->getNode(), "myLight");
//    cmp_light->initComponent();
//    cmp_light->setType(Light::DIRECTIONAL);
//    SVector3 direction = SVector3(-1, -1, 0);
//    // direction *= -1;
//    cmp_light->setDirection(direction);
//    cmp_light->setSpecularColour();
//    cmp_light->setDiffuseColour();
//    render_sys->getSceneManager()->getSceneActive()->addObjects(light_go);
//
//    ecs::GameObject* cam_go = m_mngr->addGameObject(render_sys->getSceneManager()->getSceneActive()->getSceneRoot(), {ecs::GROUP_RENDER});
//    auto m_camera = ecs::AddComponent<Camera>(cam_go);
//    m_camera->initValues(render_sys->getSceneManager()->getSceneActive()->getSceneManger(), cam_go->getNode(), render_sys->getWindow(), "myCamera");
//    m_camera->initComponent();
//    m_camera->setViewPortBackgroundColour(Ogre::ColourValue(0.3f, 0.2f, 0.6f));
//    // m_camera->setViewPortBackgroundColour(Ogre::ColourValue(0.0, 0.0, 0.0));
//    m_camera->lookAt(SVector3(0, 0, 0), Camera::WORLD);
//    m_camera->setNearClipDistance(1);
//    m_camera->setFarClipDistance(10000);
//    render_sys->getSceneManager()->getSceneActive()->addObjects(cam_go);
//
//    Ogre::ParticleSystem* pSys = render_sys->getSceneManager()->getSceneActive()->getSceneManger()->createParticleSystem("psBomba", "PsPrueba/Smoke");
//
//    pSys->setEmitting(true);
//    Ogre::SceneNode* prueba = render_sys->getSceneManager()->getSceneActive()->getSceneRoot()->createChildSceneNode();
//    prueba->setPosition({0, 60, 0});
//    prueba->attachObject(pSys);
//}
//void MiFlamingo::loadScene(RenderSystem* t_render_sys)
//{
//    MapReader* m_mapReader = new MapReader();
//
//    m_mapReader->readMap("Assets/Maps/mapPrueba.json", t_render_sys);
//}
//bool MiFlamingo::setup()
//{
//    Ogre::String s = "Motor";
//    m_mngr = ecs::Manager::instance();
//    m_mngr->init();
//
//    render_sys = m_mngr->addSystem<RenderSystem>(s);
//    physics_sys = m_mngr->addSystem<PhysicsSystem>();
//    lua_system = m_mngr->addSystem<LuaSystem>();
//
//    playerTimer = new Flamingo::Timer();
//    time = playerTimer->getElapsedTime();
//    dt = playerTimer->getElapsedTime() - time;
//
//    loadScene(render_sys);
//
//    //// Sinbad
//    // ecs::GameObject* sinbad_go = m_mngr->addGameObject(render_sys->getSceneManager()->getSceneActive()->getSceneRoot(), {ecs::GROUP_RENDER, ecs::GROUP_PHYSICS});
//    // auto cmp = ecs::AddComponent<MeshRenderer>(sinbad_go);
//    // cmp->initValues(sinbad_go->getNode(), render_sys->getSceneManager()->getSceneActive()->getSceneManger(), /*"cube.mesh"*/ "Sinbad.mesh", "myEntity");
//    //// cmp->changeMaterial("Prueba/espana");
//    // Transform* cmp_tr = ecs::AddComponent<Transform>(sinbad_go);
//    // cmp_tr->initValues(sinbad_go->getNode());
//    // cmp_tr->setScale(SVector3(25, 25, 25));
//    // cmp_tr->setPosition({0, 200, 0});
//    // Flamingo::Animator* animator = ecs::AddComponent<Flamingo::Animator>(sinbad_go);
//    // animator->initValues(render_sys->getSceneManager()->getSceneActive()->getSceneManger());
//    // animator->setAnimation("Dance", true, true);
//    //// TODO Falta probarlo:
//    //// m_mngr->setHandler(ecs::HANDLER_EXAMPLE, go);
//    // render_sys->getSceneManager()->getSceneActive()->addObjects(sinbad_go);
//    // PlayerController* m_controller = ecs::AddComponent<PlayerController>(sinbad_go);
//    // m_controller->initValues(20.0f);
//    ////RigidBody* m_rigid_body = ecs::AddComponent<RigidBody>(sinbad_go);
//    ////m_rigid_body->initValues(1.0f, false, true);
//
//    // ecs::GameObject* ground = m_mngr->addGameObject(render_sys->getSceneManager()->getSceneActive()->getSceneRoot(), {ecs::GROUP_RENDER});
//    // cmp = ecs::AddComponent<MeshRenderer>(ground);
//    // cmp->initValues(ground->getNode(), render_sys->getSceneManager()->getSceneActive()->getSceneManger(), "cube.mesh", "mygroundEntity");
//    //// cmp->changeMaterial("Prueba/espana");
//    // cmp_tr = ecs::AddComponent<Transform>(ground);
//    // cmp_tr->initValues(ground->getNode());
//    // cmp_tr->setPosition(SVector3(0, 0, 0));
//    // cmp_tr->setScale(SVector3(50, 0.5, 50));
//    // animator = ecs::AddComponent<Flamingo::Animator>(ground);
//    // animator->initValues(render_sys->getSceneManager()->getSceneActive()->getSceneManger());
//    // cmp->changeMaterial("Prueba/cesped");
//
//    // animator->setAnimation("Dance", true, true);
//    //  Falta probarlo:
//    //  m_mngr->setHandler(ecs::HANDLER_EXAMPLE, go);
//    // render_sys->getSceneManager()->getSceneActive()->addObjects(ground);
//    prueba();
//    return true;
//    // Flamingo::ParticleSystem* pSys = ecs::AddComponent<Flamingo::ParticleSystem>(sinbad_go, scene_active->getSceneManger(), scene_active->getSceneRoot()->createChildSceneNode());
//}
//
//void MiFlamingo::loop()
//{
//    auto& ihldr = ih();
//    bool game_playing = true;
//    while (game_playing && !render_sys->getWindow()->isWindowClosed())
//    {
//        // Delta time en milisegundos
//        dt = playerTimer->getElapsedTime() - time;
//        // Tiempo transcurrido desde el inicio del programa en milisegundos
//        time = playerTimer->getElapsedTime();
//
//        // leer entrada
//
//        physics_sys->update(dt);
//        render_sys->update(dt);
//
//        // m_controller->handleInput();
//        render_sys->manipulateCamera();
//        ihldr.refresh();
//        /*
//        if (ihldr.keyDownEvent())
//        {
//            if (ihldr.isKeyDown(SDLK_0))
//                std::cout << "prueba";
//        }*/
//
//        m_mngr->refresh();
//        m_mngr->flushMessages();
//    }
//}
//void MiFlamingo::exit()
//{
//    render_sys->getWindow()->closeWindow();
//
//    _CrtDumpMemoryLeaks();
//}
