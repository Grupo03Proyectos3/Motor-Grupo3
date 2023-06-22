#include "SceneManager.h"
#include "ECS/Manager.h"
#include "Render/RenderSystem.h"
#include "Scene.h"
#include "Scripting/ScriptManager.h"
#include "Scripting/ScriptingSystem.h"
#include "UI/UISystem.h"

#include <OgreRoot.h>
#include <OgreSceneManagerEnumerator.h>

#include <iostream>

namespace Flamingo
{
    SceneManager::SceneManager()
    {
        m_scenes = std::unordered_map<std::string, Scene*>();
    }

    SceneManager::~SceneManager()
    {
        for (auto it = m_scenes.begin(); it != m_scenes.end(); it = m_scenes.erase(it))
        {
            delete it->second;
        }
        m_scenes.clear();
    }

    void SceneManager::initManager(std::string t_Name, Manager* m_mng)
    {
        mName = t_Name;
        m_mngr = m_mng;
        auto syse = m_mngr->getSystem<RenderSystem>();

        //createScene("DefaultScene", true);
    }

    Scene* SceneManager::createScene(std::string t_SceneName, bool setActive)
    {
        Scene* scene = new Scene();
        scene->initScene(t_SceneName);
        addScene(scene);
        if (setActive)
        {
            setSceneActive(t_SceneName);
        }
        else
        {
            scene->desactive();
        }

        return scene;
    }

    void SceneManager::addScene(Scene* t_SceneName)
    {
        if (m_scenes.find(t_SceneName->getName()) == m_scenes.end())
        {
            m_scenes.insert({t_SceneName->getName(), t_SceneName});
            t_SceneName->getSceneManger();
        }
        else
        {
            throw std::runtime_error("Already exists a Scene with Name: " + t_SceneName->getName());
        }
    }

    void SceneManager::reloadScenePetition()
    {
        if (getSceneActive() != nullptr)
        {
            m_reloadScene = true;
            m_sceneToReload = getSceneActive();
        }
    }

    void SceneManager::reloadScene()
    {
        if (!m_reloadScene)
            return;

        m_reloadScene = false;

        std::string name = m_sceneToReload->getName();
        m_sceneToReload->destroySceneObjects();
        m_sceneToAsociated = m_sceneToReload;
        m_mngr->getSystem<ScriptingSystem>()->loadObjects(name);

        setSceneActive(m_sceneToReload->getName());
        m_sceneToReload->startScene();
    }

    Scene* SceneManager::getSceneToAttach()
    {
        return m_sceneToAsociated;
    }

    void SceneManager::setSceneToAttach(Scene* t_sceneToAttach)
    {
        m_sceneToAsociated = t_sceneToAttach;
    }

    void SceneManager::startScene(std::string t_sceneName)
    {
        // Cambio convocatoria extraordinaria : no cambiar la escena al instante:

        auto t_aux = m_scenes.find(t_sceneName);
        if (t_aux != m_scenes.end())
        {
            m_reloadScene = true;

            m_sceneToReload = (*t_aux).second;

            //setSceneActive(t_sceneName);
            //t_aux->second->startScene();
        }
    }

    void SceneManager::delScene(std::string t_SceneName)
    {
        auto t_aux = m_scenes.find(t_SceneName);
        if (t_aux != m_scenes.end())
        {
            m_scenes.erase(t_aux);
        }
    }

    void SceneManager::setSceneActive(std::string t_SceneName)
    {
        if (m_activeScene == nullptr)
        {
            if (m_scenes.count(t_SceneName))
            {
                m_activeScene = (*m_scenes.find(t_SceneName)).second;
                m_activeScene->active();
            }
        }
        else if (m_activeScene->getName() != t_SceneName)
        {
            auto t_aux = m_scenes.find(t_SceneName);
            if (t_aux != m_scenes.end())
            {
                //Desactivate previous Scene if exists
                m_activeScene->desactive();
                m_activeScene = (*t_aux).second;
                m_activeScene->active();
            }
        }
    }

    Scene* SceneManager::getSceneActive()
    {
        if (m_scenes.empty())
        {
            throw std::runtime_error("ERROR: There is not any Scenes Active");
        }
        return m_activeScene;
    }

    Scene* SceneManager::getScene(std::string t_scene_name)
    {
        return (*m_scenes.find(t_scene_name)).second;
    }

    SceneManager& FlamingoSceneManager()
    {
        return *SceneManager::instance();
    }

} // namespace Flamingo
