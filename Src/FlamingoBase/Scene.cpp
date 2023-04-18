#include "Scene.h"
#include "ECS/Manager.h"
#include "Render/Camera.h"
#include <UI/UIElement.h>
#include <iostream>

namespace Flamingo
{

    Scene::Scene()
    {
        mSceneManager = nullptr;
        mSceneGameObjects = std::unordered_map<Ogre::String, ecs::GameObject*>();
        mDebug = false;
    }

    Scene::~Scene()
    {
        mSceneGameObjects.clear();
        mSceneManager = nullptr;
        mRootNode = nullptr;
    }

    void Scene::initScene(Ogre::SceneManager* t_SceneManager, ecs::Manager* mng)
    {
        mSceneManager = t_SceneManager;
        mRootNode = mSceneManager->getRootSceneNode();
        m_mngr = mng;
    }

    void Scene::addObjects(ecs::GameObject* t_GameObject)
    {
        // DEJARLO ASI O K SUDE Y SE CAMBIE POR SI ENTRA OTRO CON EL MISMO NOMBRE
        if (mSceneGameObjects.find(t_GameObject->getName()) == mSceneGameObjects.end())
        {
            mSceneGameObjects.insert({t_GameObject->getName(), t_GameObject});
            if (mDebug)
                std::cout << "Object Name: " << t_GameObject->getName() << " Added\n";
        }
    }

    void Scene::delObject(std::string t_nameObject)
    {
        auto t_aux = mSceneGameObjects.find(t_nameObject);
        if (t_aux != mSceneGameObjects.end())
        {
            mSceneGameObjects.erase(t_aux);
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
        for (auto obj : mSceneGameObjects)
        {
            if (m_mngr->getComponent<Camera>(obj.second) != nullptr)
            { // es necesario desasociar el viewport de la camara con la camra para k pare de renderizar
                m_mngr->getComponent<Camera>(obj.second)->desactive();
            }

            obj.second->setAlive(false);
        }
    }

    void Scene::desactive()
    {
        mRootNode->setVisible(false);
        // acceder a objectos de la scene en la k esten y desactivarlos
        for (auto obj : mSceneGameObjects)
        {
            obj.second->setActive(false);
            if (m_mngr->getComponent<Camera>(obj.second) != nullptr)
            { // es necesario desasociar el viewport de la camara con la camra para k pare de renderizar
                m_mngr->getComponent<Camera>(obj.second)->desactive();
            }
        }
        std::cout << "Scene Name: " << mSceneManager->getName() << " Desactivated\n";
    }

    void Scene::active()
    {
        mRootNode->setVisible(true);
        for (auto it : mSceneGameObjects)
        {
            it.second->setActive(false);
            if (m_mngr->getComponent<Camera>(it.second) != nullptr)
            {
                m_mngr->getComponent<Camera>(it.second)->active();
            }
        }
        std::cout << "Scene name: " << mSceneManager->getName() << " Activated\n";
    }

} // namespace Flamingo