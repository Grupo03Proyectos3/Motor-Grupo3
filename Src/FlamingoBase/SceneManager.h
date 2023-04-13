#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__
#pragma once
#include <unordered_map>
#include "Scene.h"
class PhysicsSystem;
class RenderSystem;
namespace Flamingo{
    class SceneManager{
        friend PhysicsSystem;
        friend RenderSystem;
      public:
        SceneManager(std::string t_Name, ecs::Manager* m_mng);
        ~SceneManager();       

        Scene* createScene(std::string t_SceneName,bool setActive=false);
        void delScene(std::string t_SceneName);

        void setSceneActive(std::string t_SceneName);
        Scene* getSceneActive();

        void addScene(Scene* t_Scene);
      protected:
        void init(Ogre::Root* t_root);
        inline Ogre::Root* getRoot() { return m_root; }
        inline Ogre::SceneManager* getSceneManager() { return m_scene_manager; }

      private:
        ecs::Manager* m_mngr;
        Ogre::Root* m_root;
        Ogre::SceneManager* m_scene_manager = nullptr;
        std::unordered_map<Ogre::String, Scene*> m_scenes;
        Ogre::String mNameSceneActive = "";
        Ogre::String mName;        
    };
} // namespace OgreScene
#endif