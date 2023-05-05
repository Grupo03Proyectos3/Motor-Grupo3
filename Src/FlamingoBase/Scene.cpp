#include "Scene.h"
#include "ECS/Manager.h"
#include "Render/Camera.h"
#include <UI/UIElement.h>
#include <iostream>
#include <OgreSceneManager.h>
#include "CEGUI/WindowRenderer.h"
#include "UI/UISystem.h"
#include "Scripting/ScriptManager.h"

namespace Flamingo{
    Scene::Scene()
    {
        m_SceneManager = nullptr;
        m_OgreRootNode = nullptr;
        m_CeguiRootNode = nullptr;
        m_SceneGameObjects = std::unordered_map<Ogre::String, GameObject*>();
        mDebug = false;
    }

    Scene::~Scene()
    {
        m_SceneGameObjects.clear();
        m_SceneManager = nullptr;
        m_OgreRootNode = nullptr;
    }

    void Scene::initScene(std::string name)
    {
        m_mngr = Manager::instance();
        auto sysR = m_mngr->getSystem<RenderSystem>();
        auto sysu = m_mngr->getSystem<UISystem>();
        m_SceneManager = sysR->createSceneManager(name);
        m_OgreRootNode = m_SceneManager->getRootSceneNode();
        m_CeguiRootNode = sysu->createRootScene(name);
    }

    void Scene::addObjects(GameObject* t_GameObject)
    {
        // DEJARLO ASI O K SUDE Y SE CAMBIE POR SI ENTRA OTRO CON EL MISMO NOMBRE
        if (m_SceneGameObjects.find(t_GameObject->getName()) == m_SceneGameObjects.end())
        {
            m_SceneGameObjects.insert({t_GameObject->getName(), t_GameObject});
            if (mDebug)
                std::cout << "Object Name: " << t_GameObject->getName() << " Added\n";
        }
        else
        {
            std::cout << t_GameObject->getName() + "\n";
            t_GameObject->setAlive(false);
            throw std::exception("[ERROR loading the scene]");
        }
            
    }

    void Scene::delObject(std::string t_nameObject)
    {
        auto t_aux = m_SceneGameObjects.find(t_nameObject);
        if (t_aux != m_SceneGameObjects.end())
        {
            m_SceneGameObjects.erase(t_aux);
            if (mDebug)
                std::cout << "Object Name: " << t_nameObject << " Deleted\n";
        }
    }

    void Scene::setDebug(bool t_active)
    {
        mDebug = t_active;
    }

    void Scene::destroySceneObject(std::string t_n)
    {
        auto t_aux = m_SceneGameObjects.find(t_n);
        if (t_aux != m_SceneGameObjects.end())
            m_SceneGameObjects.erase(t_aux);
        
    }

    void Scene::destroySceneObjects()
    {
       

        m_initialized = false;

        for (auto obj : m_SceneGameObjects)
        {
            auto c = m_mngr->getComponent<Camera>(obj.second);
            if (c != nullptr)
            { // es necesario desasociar el viewport de la camara con la camra para k pare de renderizar
               c->desactive();
            }

            //auto ui = m_mngr->getComponent<UIElement>(obj.second);
            //if (ui != nullptr)
            //{

            //    //delete ui->getWindowElement();
            //    m_CeguiRootNode->removeChild(ui->getWindowElement());
            //    ;
            //}

         
            obj.second->setAlive(false);
        }

           while (m_CeguiRootNode->getChildCount() > 0)
        {
            CEGUI::Window* child = m_CeguiRootNode->getChildAtIdx(0);

            m_CeguiRootNode->removeChild(child);
        }


        m_SceneGameObjects.clear();
        m_mngr->reajustGroups();
        m_mngr->refresh();
    }

    void Scene::desactive()
    {
        m_active = false;
        m_OgreRootNode->setVisible(false);
        m_CeguiRootNode->setVisible(false);
        // acceder a objectos de la scene en la k esten y desactivarlos
        for (auto obj : m_SceneGameObjects)
        {   // TO DO : refactorizar para que la camara reciba el mensaje y se desactive sola
            obj.second->setActive(false);
            if (m_mngr->getComponent<Camera>(obj.second) != nullptr)
            { // es necesario desasociar el viewport de la camara con la camra para k pare de renderizar
                m_mngr->getComponent<Camera>(obj.second)->desactive();
            }
        }
        std::cout << "Scene Name: " << m_SceneManager->getName() << " Desactivated\n";
    }

    void Scene::active()
    {
        m_active = true;
        m_OgreRootNode->setVisible(true);
        m_CeguiRootNode->setVisible(true);
        for (auto it : m_SceneGameObjects)
        {
            it.second->setActive(true);
            
            if (m_mngr->getComponent<Camera>(it.second) != nullptr)
            {
                m_mngr->getComponent<Camera>(it.second)->active();
            }
        }
      
        std::cout << "Scene Name: " << m_SceneManager->getName() << " Activated\n";
    }

    void Scene::startScene()
    {
        if (!m_initialized)
        {
            m_initialized = true;
            ScriptManager::instance()->startComponents();
        }

    }

    bool Scene::isSceneActive()
    {
        return m_active;
    }

    GameObject* Scene::getObject(std::string t_name)
    {
        for (auto it : m_SceneGameObjects)
        {
            if (it.first == t_name)
                return it.second;
        }
        return nullptr;
    }

    std::string Scene::getName()
    {
        return (std::string)m_SceneManager->getName(); 
    }

    Ogre::SceneManager* Scene::getSceneManger()
    {
        return m_SceneManager;
    }

    Ogre::SceneNode* Scene::getSceneRoot()
    {
        return m_OgreRootNode;
    }

    CEGUI::Window* Scene::getCeguiRoot()
    {
        return m_CeguiRootNode;
    }

} // namespace Flamingo