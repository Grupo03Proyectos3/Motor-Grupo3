#include "Scene.h"
#include "ECS/Manager.h"
#include "Render/Camera.h"
#include <UI/UIElement.h>
#include <iostream>
#include <OgreSceneManager.h>

namespace Flamingo{
    Scene::Scene()
    {
        m_SceneManager = nullptr;
        m_OgreRootNode = nullptr;
        m_CeguiRootNode = nullptr;
        m_SceneGameObjects = std::unordered_map<Ogre::String, ecs::GameObject*>();
        mDebug = false;
    }

    Scene::~Scene()
    {
        m_SceneGameObjects.clear();
        m_SceneManager = nullptr;
        m_OgreRootNode = nullptr;
    }

    void Scene::initScene(Ogre::SceneManager* t_SceneManager,CEGUI::Window* root ,ecs::Manager* mng)
    {
        m_SceneManager = t_SceneManager;
        m_OgreRootNode = m_SceneManager->getRootSceneNode();
        m_CeguiRootNode = root;
        m_mngr = mng;
    }

    void Scene::addObjects(ecs::GameObject* t_GameObject)
    {
        // DEJARLO ASI O K SUDE Y SE CAMBIE POR SI ENTRA OTRO CON EL MISMO NOMBRE
        if (m_SceneGameObjects.find(t_GameObject->getName()) == m_SceneGameObjects.end())
        {
            m_SceneGameObjects.insert({t_GameObject->getName(), t_GameObject});
            if (mDebug)
                std::cout << "Object Name: " << t_GameObject->getName() << " Added\n";
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

    void Scene::destroySceneObjects()
    {
        for (auto obj : m_SceneGameObjects)
        {
            if (m_mngr->getComponent<Camera>(obj.second) != nullptr)
            { // es necesario desasociar el viewport de la camara con la camra para k pare de renderizar
                m_mngr->getComponent<Camera>(obj.second)->desactive();
            }

            obj.second->setAlive(false);
        }
        m_mngr->reajustGroups();
    }

    void Scene::desactive()
    {
        m_OgreRootNode->setVisible(false);
        m_CeguiRootNode->setVisible(false);
        // acceder a objectos de la scene en la k esten y desactivarlos
        for (auto obj : m_SceneGameObjects)
        {
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
        m_OgreRootNode->setVisible(true);
        m_CeguiRootNode->setVisible(true);
        for (auto it : m_SceneGameObjects)
        {
            it.second->setActive(false);
            if (m_mngr->getComponent<Camera>(it.second) != nullptr)
            {
                m_mngr->getComponent<Camera>(it.second)->active();
            }
        }
        std::cout << "Scene Name: " << m_SceneManager->getName() << " Activated\n";
    }

    ecs::GameObject* Scene::getObject(std::string t_name)
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