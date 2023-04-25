#include "RenderSystem.h"

#include "Animator.h"
#include "ECS/InputHandler.h"
#include "FlamingoBase/SceneManager.h"
#include "MeshRenderer.h"
#include "Window.h"

#include <OgreConfigFile.h>
#include <OgreFileSystemLayer.h>
#include <OgreGpuProgramManager.h>
#include <OgreRoot.h>
#include <Physics/RigidBody.h>

namespace Flamingo
{
    RenderSystem::RenderSystem(std::string& t_app_name)
        : m_app_name(t_app_name)
    {
        m_group = ecs::GROUP_RENDER;
        m_fs_layer = new Ogre::FileSystemLayer(m_app_name);
    }

    void RenderSystem::recieve(const Message& t_m)
    {
        // TO DO :  limpiar para reutilizar código -> mover a una función externa?
        switch (t_m.id)
        {
            case MSG_TRANSFORM_MOVE:
            {
                if (t_m.entity_affected == nullptr)
                    return;
                auto mesh = m_mngr->getComponent<MeshRenderer>(t_m.entity_affected);

                if (mesh == NULL)
                    return;
                mesh->getNode()->setPosition(SVector3(t_m.vector.x, t_m.vector.y, t_m.vector.z));
                break;
            }
            case MSG_TRANSFORM_ROTATE:
            {
                if (t_m.entity_affected == nullptr)
                    return;
                auto mesh = m_mngr->getComponent<MeshRenderer>(t_m.entity_affected);

                if (mesh == NULL)
                    return;
                mesh->getNode()->setOrientation(SQuaternion(t_m.quaternion.x, t_m.quaternion.y, t_m.quaternion.z, t_m.quaternion.w));
                break;
            }
            case MSG_TRANSFORM_SCALING:
            {
                if (t_m.entity_affected == nullptr)
                    return;
                auto mesh = m_mngr->getComponent<MeshRenderer>(t_m.entity_affected);

                if (mesh == NULL)
                    return;
                mesh->getNode()->setScale(SVector3(t_m.vector.x, t_m.vector.y, t_m.vector.z));
                break;
            }
            default:
                break;
        }
    }

    void RenderSystem::initSystem()
    {
        createRoot();

        if (config())
        {
            setUp();
        }
    }
    
    void RenderSystem::update(float t_delta_time)
    {
        for (auto game_object : m_mngr->getEntities(ecs::GROUP_RENDER))
        {
            if (game_object->getActive())
            {
                auto rb = m_mngr->getComponent<RigidBody>(game_object);
                if (rb && !rb->isKinematic())
                {
                    auto t = m_mngr->getComponent<Transform>(game_object);
                    t->setPositionPerPhysics(rb->getPosition());
                    t->setRotationPerPhysics(rb->getRotation());
                    t->setRotationPerPhysics(rb->getRotation());
                }
                auto animator = m_mngr->getComponent<Flamingo::Animator>(game_object);

                if (animator != nullptr)
                    animator->updateAnimations(t_delta_time * 0.001); // PQ HAY Q PASARLO A MILISEGUNDOS
            }
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

        //m_root = new Ogre::Root(pluginsPath, m_fs_layer->getWritablePath("ogre.cfg"), m_fs_layer->getWritablePath("ogre.log"));
        m_root = new Ogre::Root("plugins.cfg", "ogre.cfg", "Ogre.log");
        m_scene_mngr = new Flamingo::SceneManager(m_app_name + " - SceneManager", m_mngr);

        // mSceneManager = mRoot->createSceneManager(Ogre::DefaultSceneManagerFactory::FACTORY_TYPE_NAME, mAppName);

        // SI NO LO PONGO NO PILLA NINGUN RENDER ACTIVO **NO NECESARIO CON config(), ya lo hace auto **
        // mRenderSystem = mRoot->getRenderSystemByName("Direct3D11 Rendering Subsystem");
        // mRoot->setRenderSystem(mRenderSystem);
    }

    void RenderSystem::setUp()
    {
        m_root->initialise(false);
        m_scene_mngr->init(m_root);
        m_window = new Flamingo::Window(m_app_name, m_root);
        m_window->setSceneManager(m_scene_mngr);
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

    void RenderSystem::bringResources(std::string & sec_name, std::string & type_name, std::string & arch_name)
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

        arch_name = genLocs.front().archive->getName() + "/Essencial";
        type_name = genLocs.front().archive->getType();

        // A�ADIR LOS LENGUAJES DE PROGRAMACION DE LOS SHADERS
        // Add locations for supported shader languages
        /*if (Ogre::GpuProgramManager::getSingleton().isSyntaxSupported("glsles")){

        }*/
        // Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch_name + "/programs/GLSLES", type_name, sec_name);
        // if (Ogre::GpuProgramManager::getSingleton().isSyntaxSupported("glsl"))
        //{
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
        //}
        // Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch_name + "/programs/HLSL", type_name, sec_name);
        /* else if (Ogre::GpuProgramManager::getSingleton().isSyntaxSupported("hlsl")){
                Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch_name + "/programs/HLSL", type_name, sec_name);
            }*/

        std::string mRTShaderLibPath = arch_name + "/Essencial/RTShaderLib";
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
            if (ihldr.isKeyDown(SDLK_RIGHT))
            {
                m_camera->translate(10.0f, 0.0f, 0.0f);
            }
            else if (ihldr.isKeyDown(SDLK_LEFT))
            {
                m_camera->translate(-10.0f, 0.0f, 0.0f);
            }
            else if (ihldr.isKeyDown(SDLK_UP))
            {
                m_camera->translate(0.0f, 0.0f, -10.0f);
            }
            else if (ihldr.isKeyDown(SDLK_DOWN))
            {
                m_camera->translate(0.0f, 0.0f, +10.0f);
            }
        }
    }

    RenderSystem::~RenderSystem()
    {
        m_window->destroyRTShaderSystem();
        delete m_scene_mngr;
        m_scene_mngr = nullptr;

        m_window->shutdown();
        delete m_window;
        m_window = nullptr;

        if (m_camera != nullptr)
        {
            delete m_camera;
            m_camera = nullptr;
        }

        delete m_fs_layer;
        m_fs_layer = nullptr;

        if (m_root != nullptr)
        {
            delete m_root;
            m_root = nullptr;
        }
    }
}