#include "RenderSystem.h"

#include "ECS/Components.h"
#include "ECS/GameObject.h"
#include "ECS/InputHandler.h"
#include "FlamingoBase/SceneManager.h"
#include "FlamingoBase/Transform.h"
#include "Light.h"
#include "MeshRenderer.h"
#include "Animator.h"

#include <OgreConfigFile.h>
#include <OgreEntity.h>
#include <OgreFileSystemLayer.h>
#include <OgreGpuProgramManager.h>
#include <OgreRoot.h>
#include <Physics/RigidBody.h>

RenderSystem::RenderSystem(Ogre::String& t_app_name)
    : m_app_name(t_app_name)
{
    m_group = ecs::GROUP_RENDER;
    m_fs_layer = new Ogre::FileSystemLayer(m_app_name);
}

void RenderSystem::recieve(const Message&)
{
}

void RenderSystem::initSystem()
{
    createRoot();

    if (config())
    {
        m_group = ecs::_grp_GENERAL;
        setUp();
        OgreScene::SceneManager* mySceneManager = getSceneManager();
        OgreScene::Scene* sceneActive = mySceneManager->getSceneActive();
        Ogre::SceneManager* scene_mgr = sceneActive->getSceneManger();
        Ogre::SceneNode* root_scene_node = sceneActive->getSceneRoot();

        // Sinbad
        ecs::GameObject* sinbad_go = m_mngr->addGameObject(root_scene_node);
        auto cmp = ecs::AddComponent<MeshRenderer>(sinbad_go, sinbad_go->getNode(), scene_mgr, /*"cube.mesh"*/ "Sinbad.mesh", "myEntity");
        //cmp->changeMaterial("Prueba/espana");
        Transform* cmp_tr = ecs::AddComponent<Transform>(sinbad_go, sinbad_go->getNode());
        cmp_tr->setScale(SVector3(25, 25, 25));
        Flamingo::Animator* animator = ecs::AddComponent<Flamingo::Animator>(sinbad_go, scene_mgr);
        animator->setAnimation("Dance",true,true);
        // Falta probarlo:
        //m_mngr->setHandler(ecs::HANDLER_EXAMPLE, go);
        sceneActive->addObjects(sinbad_go);
        m_controller = ecs::AddComponent<PlayerController>(sinbad_go, 20.0f);

        // Cubo
        ecs::GameObject* cube_go = m_mngr->addGameObject(root_scene_node);
        auto cmp2 = ecs::AddComponent<MeshRenderer>(cube_go, cube_go->getNode(), scene_mgr, "cube.mesh", "CubeEntity");
        cmp2->changeMaterial("Prueba/espana");
        Transform* cmp_tr2 = ecs::AddComponent<Transform>(cube_go, cube_go->getNode());
        cmp_tr2->setPosition(SVector3(0, 300, 0));
        sceneActive->addObjects(cube_go);
        
        // Luz
        ecs::GameObject* light_go = new ecs::GameObject(root_scene_node);
        Light* cmp_light = ecs::AddComponent<Light>(light_go, scene_mgr, light_go->getNode(), "myLight");
        cmp_light->setType(Light::DIRECTIONAL);
        SVector3 direction = SVector3(-1, -1, 0);
        //direction *= -1;
        cmp_light->setDirection(direction);
        cmp_light->setSpecularColour();
        cmp_light->setDiffuseColour();
        sceneActive->addObjects(light_go);

        // Camara
        ecs::GameObject* cam_go = new ecs::GameObject(root_scene_node);
        m_camera = ecs::AddComponent<Camera>(cam_go, scene_mgr, cam_go->getNode(), getWindow(), "myCamera");
        m_camera->setViewPortBackgroundColour(Ogre::ColourValue(0.3, 0.2, 0.6));
        //m_camera->setViewPortBackgroundColour(Ogre::ColourValue(0.0, 0.0, 0.0));
        m_camera->lookAt(SVector3(0, 0, 0), Camera::WORLD);
        m_camera->setNearClipDistance(1);
        m_camera->setFarClipDistance(10000);
        sceneActive->addObjects(cam_go);

        /* myWindow->getSceneManager()->createScene("NUEVA1", true);
         myWindow->addRTShaderSystem(myWindow->getSceneManager()->getSceneActive()->getSceneManger());*/
    }
}

void RenderSystem::update(float t_delta_time)
{
    for (auto game_object : m_mngr->getEntities(m_group))
    {
        auto rb = m_mngr->getComponent<RigidBody>(game_object);
        if (rb && !rb->isKinematic())
        {
            m_mngr->getComponent<Transform>(game_object)->setPosition(rb->getPosition());
            m_mngr->getComponent<Transform>(game_object)->setRotation(rb->getRotation());
        }
        auto animator = m_mngr->getComponent<Flamingo::Animator>(game_object);

        if (animator != nullptr) animator->updateAnimations(t_delta_time);   //ESTO HAY Q HACERLO POR MESNAJES CADA CIERTO TIEMPO     
    }

    // TODO actualizar Transform con input/scripts
    


    m_root->renderOneFrame();
    m_window->update();
    // manipulateCamera();
}

void RenderSystem::createRoot()
{
    Ogre::String pluginsPath;

    pluginsPath = m_fs_layer->getConfigFilePath("plugins.cfg");
    if (!Ogre::FileSystemLayer::fileExists(pluginsPath))
    {
        OGRE_EXCEPT(Ogre::Exception::ERR_FILE_NOT_FOUND, "plugins.cfg", m_app_name + ": createRoot");
    }

    m_root = new Ogre::Root(pluginsPath, m_fs_layer->getWritablePath("ogre.cfg"), m_fs_layer->getWritablePath("ogre.log"));

    m_ogre_scene_mngr = new OgreScene::SceneManager(m_app_name + " - SceneManager");

    // mSceneManager = mRoot->createSceneManager(Ogre::DefaultSceneManagerFactory::FACTORY_TYPE_NAME, mAppName);

    // SI NO LO PONGO NO PILLA NINGUN RENDER ACTIVO **NO NECESARIO CON config(), ya lo hace auto **
    // mRenderSystem = mRoot->getRenderSystemByName("Direct3D11 Rendering Subsystem");
    // mRoot->setRenderSystem(mRenderSystem);
}

void RenderSystem::setUp()
{
    m_root->initialise(false);
    m_ogre_scene_mngr->init(m_root);
    m_window = new OgreWindow::Window(m_app_name, m_root);
    m_window->setSceneManager(m_ogre_scene_mngr);
    m_window->createWindow(m_app_name);
    // createWindow(mAppName);

    locateResources();
    m_window->initialiseRTShaderSystem();
    loadResources();
}

void RenderSystem::locateResources()
{
    Ogre::String sec_name, type_name, arch_name;

    sec_name = Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME; // miro a ver si ya se han cargado los recursos en el resourceManager
    const Ogre::ResourceGroupManager::LocationList genLocs2 = Ogre::ResourceGroupManager::getSingleton().getResourceLocationList(sec_name);

    if (genLocs2.empty()) // si no estan cargados los cargo
        bringResources(sec_name, type_name, arch_name);
}

void RenderSystem::loadResources()
{
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}

void RenderSystem::bringResources(Ogre::String& sec_name, Ogre::String& type_name, Ogre::String& arch_name)
{
    Ogre::ConfigFile cf;
    cf.load("resources.cfg");

    Ogre::ConfigFile::SettingsBySection_ seci = cf.getSettingsBySection();
    for (auto i = seci.begin(); i != seci.end(); i++)
    {
        sec_name = i->first;
        Ogre::ConfigFile::SettingsMultiMap settings = i->second;
        Ogre::ConfigFile::SettingsMultiMap::iterator mmi;
        for (mmi = settings.begin(); mmi != settings.end(); ++mmi)
        {
            type_name = mmi->first;
            arch_name = mmi->second;
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
                arch_name, type_name, sec_name);
        }
    }
    sec_name = Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME;
    auto genLocs = Ogre::ResourceGroupManager::getSingleton().getResourceLocationList(sec_name);

    arch_name = genLocs.front().archive->getName();
    type_name = genLocs.front().archive->getType();

    // AÑADIR LOS LENGUAJES DE PROGRAMACION DE LOS SHADERS
    // Add locations for supported shader languages
    /*if (Ogre::GpuProgramManager::getSingleton().isSyntaxSupported("glsles")){
        Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch_name + "/programs/GLSLES", type_name, sec_name);
    }*/
    if (Ogre::GpuProgramManager::getSingleton().isSyntaxSupported("glsl"))
    {
        Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch_name + "/programs/GLSL120", type_name, sec_name);

        if (Ogre::GpuProgramManager::getSingleton().isSyntaxSupported("glsl150"))
        {
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch_name + "/programs/GLSL150", type_name, sec_name);
        }
        else
        {
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch_name + "/programs/GLSL", type_name, sec_name);
        }

        if (Ogre::GpuProgramManager::getSingleton().isSyntaxSupported("glsl400"))
        {
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch_name + "/programs/GLSL400", type_name, sec_name);
        }
    }
    /* else if (Ogre::GpuProgramManager::getSingleton().isSyntaxSupported("hlsl")){
         Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch_name + "/programs/HLSL", type_name, sec_name);
     }*/

    Ogre::String mRTShaderLibPath = arch_name + "/RTShaderLib";
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation(mRTShaderLibPath + "/materials", type_name, sec_name);
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation(mRTShaderLibPath + "/GLSL", type_name, sec_name); // CARGO GLSL
}

bool RenderSystem::config()
{
    if (!m_root->restoreConfig())
    {
        return m_root->showConfigDialog(nullptr);
    }
    return true;
}

void RenderSystem::manipulateCamera()
{
    m_controller->handleInput();

    auto& ihldr = ih();
    ihldr.refresh();

    if (ihldr.keyDownEvent())
    {
        if (ihldr.isKeyDown(SDLK_r))
        {
            m_camera->roll(1.0f);
        }
        else if (ihldr.isKeyDown(SDLK_y))
        {
            m_camera->yaw(1.0f);
        }
        else if (ihldr.isKeyDown(SDLK_p))
        {
            m_camera->pitch(1.0f);
        }
    }
}

RenderSystem::~RenderSystem()
{
    delete m_window;
    m_window = nullptr;
    /*delete m_ogre_scene_mngr;
    m_ogre_scene_mngr = nullptr;*/
    delete m_fs_layer;
    m_fs_layer = nullptr;
}