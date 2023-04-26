#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__
#pragma once
#include <unordered_map>
#include "Scene.h"

namespace Flamingo
{
    class PhysicsSystem;
    class RenderSystem;
}

namespace Ogre
{
    class Root;
    class SceneManager;
}

namespace Flamingo{
    class SceneManager{
        friend Flamingo::PhysicsSystem;
        friend Flamingo::RenderSystem;
      public:
        SceneManager(std::string t_Name, ecs::Manager* m_mng);
        ~SceneManager();       

        Scene* createScene(std::string t_SceneName,bool setActive=false);
        void delScene(std::string t_SceneName);

        void setSceneActive(std::string t_SceneName);
        Scene* getSceneActive();
        Scene* getScene(std::string t_scene_name);

        void addScene(Scene* t_Scene);
      protected:
        void init(Ogre::Root* t_root);
        inline Ogre::Root* getRoot() { return m_root; }
        inline Ogre::SceneManager* getSceneManager() { return m_scene_manager; }

      private:
        ecs::Manager* m_mngr;
        Ogre::Root* m_root;
        Ogre::SceneManager* m_scene_manager = nullptr;
        std::unordered_map<std::string, Scene*> m_scenes;
        std::string mNameSceneActive = "";
        std::string mName;        
    };
} // namespace OgreScene
#endif