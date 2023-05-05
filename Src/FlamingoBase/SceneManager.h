#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__
#pragma once
#include "ECS/SingletonECS.h"
#include "Scene.h"
#include <unordered_map>

namespace Flamingo
{
    class PhysicsSystem;
    class RenderSystem;
    class UISystem;
} // namespace Flamingo
namespace Ogre
{
    class Root;
    class SceneManager;
} // namespace Ogre

namespace Flamingo
{
    class FLAMINGOEXPORT_API SceneManager : public SingletonECS<Flamingo::SceneManager>
    {
        friend PhysicsSystem;
        friend RenderSystem;
        friend UISystem;
        friend SingletonECS<SceneManager>;

      public:
        SceneManager();
        ~SceneManager();
        void initManager(std::string t_Name, Manager* m_mng);

        Scene* createScene(std::string t_SceneName, bool setActive = false);
        void delScene(std::string t_SceneName);

        void setSceneActive(std::string t_SceneName);
        Scene* getSceneActive();
        Scene* getScene(std::string t_scene_name);

        void addScene(Scene* t_Scene);

        void reloadScenePetition();

        void startScene(std::string t_sceneName);

         void reloadScene();

         Scene* getSceneToAttach();
         void setSceneToAttach(Scene* t_sceneToAttach);

      private:

        Manager* m_mngr;

        std::unordered_map<std::string, Scene*> m_scenes;
        std::string mNameSceneActive = "";
        std::string mName;

        bool m_reloadScene = false;
        Scene* m_sceneToReload;
        Scene* m_sceneToAsociated = nullptr;
    };
    // This macro defines a compact way for using the singleton
    //
    SceneManager& FlamingoSceneManager();
} // namespace Flamingo
#endif