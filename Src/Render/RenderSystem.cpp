#include "RenderSystem.h"

#include "ECS/InputHandler.h"
#include "FlamingoBase/GameObject.h"
#include "FlamingoBase/SceneManager.h"
#include "Light.h"

#include <FlamingoBase/Render.h>
#include <OgreConfigFile.h>
#include <OgreEntity.h>
#include <OgreFileSystemLayer.h>
#include <OgreGpuProgramManager.h>
#include <OgreRoot.h>

RenderSystem::RenderSystem(Ogre::String& t_app_name)
    : m_app_name(t_app_name)
    , m_camera(nullptr)
{
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
        setUp();
        OgreScene::SceneManager* mySceneManager = getSceneManager();
        OgreScene::Scene* sceneActive = mySceneManager->getSceneActive();
        Ogre::SceneManager* scene_mgr = sceneActive->getSceneManger();
        Ogre::SceneNode* root_scene_node = sceneActive->getSceneRoot();

        // Cubo

        Ogre::Entity* entity = scene_mgr->createEntity("myEntity", "cube.mesh");
        Ogre::SceneNode* node = root_scene_node->createChildSceneNode();
        GameObject* go = new GameObject(m_mngr);
        auto cmp = go->addComponent<Render>(node, entity, "Prueba/espana");
        sceneActive->addObjects(go);
        // Luz
        GameObject* light_go = new GameObject(m_mngr);
        Ogre::SceneNode* cam_node = root_scene_node->createChildSceneNode();
        Light* cmp_light = light_go->addComponent<Light>(scene_mgr, cam_node, "myLight");
        cmp_light->setType(Light::DIRECTIONAL);
        cmp_light->setDirection(SVector3(0, -1, 0));
        cmp_light->setSpecularColour();
        cmp_light->setDiffuseColour();
        sceneActive->addObjects(light_go);

        // Camara
        GameObject* cam_go = new GameObject(m_mngr, SVector3(500, 500, 1000));
        Ogre::SceneNode* light_node = root_scene_node->createChildSceneNode();
        m_camera = cam_go->addComponent<Camera>(scene_mgr, light_node, getWindow(), "myCamera");
        m_camera->setViewPortBackgroundColour(Ogre::ColourValue(0.3, 0.2, 0.6));
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
    m_root->renderOneFrame();
    m_window->pollEvents();
    //manipulateCamera();
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