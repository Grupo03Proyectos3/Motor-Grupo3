#include "SceneManager.h"
#include "Scene.h"
#include "ECS/Manager.h"
#include "Render/RenderSystem.h"
#include "UI/UISystem.h"
#include "Lua/ScriptManager.h"

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

        createScene("DefaultScene", true);
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
            std::cout << "Scene " << t_SceneName->getName() << " Added\n ";
        }
        else
        {
            throw std::runtime_error("Already exists a Scene with Name: " + t_SceneName->getName());
        }
    }

    void SceneManager::delScene(std::string t_SceneName)
    {
        auto t_aux = m_scenes.find(t_SceneName);
        if (t_aux != m_scenes.end())
        {
            m_scenes.erase(t_aux);
            std::cout << mName << "Scene " << t_SceneName << " Deleted\n ";
        }
    }

    void SceneManager::setSceneActive(std::string t_SceneName)
    {
        if (mNameSceneActive != t_SceneName)
        {
            auto t_aux = m_scenes.find(t_SceneName);
            if (t_aux != m_scenes.end())
            {
                if (mNameSceneActive != "")
                {
                    (*m_scenes.find(mNameSceneActive)).second->desactive();
                }
                (*t_aux).second->active();
                mNameSceneActive = t_SceneName;
               // Flamingo::ScriptManager::instance()->startComponents();
            }
        }
    }

    Scene* SceneManager::getSceneActive()
    {
        if (m_scenes.empty())
        {
            throw std::runtime_error("ERROR: There is not any Scenes Active");
        }
        return (*m_scenes.find(mNameSceneActive)).second;
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
