#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__
#pragma once
#include <unordered_map>
#include "Scene.h"
namespace Flamingo{
    class SceneManager{
      public:
        SceneManager(Ogre::String t_Name);
        ~SceneManager();
        void init(Ogre::Root* t_root);

        Scene* createScene(Ogre::String t_SceneName,bool setActive=false);
        void delScene(Ogre::String t_SceneName);

        void setSceneActive(Ogre::String t_SceneName);
        Scene* getSceneActive();

        inline Ogre::Root* getRoot() { return m_root; }
        inline Ogre::SceneManager* getSceneManager() { return m_scene_manager; }

      private:
        Ogre::Root* m_root;
        Ogre::SceneManager* m_scene_manager = nullptr;
        std::unordered_map<Ogre::String, Scene*> m_scenes;
        Ogre::String mNameSceneActive = "";
        Ogre::String mName;

        void addScene(Scene* t_Scene);
    };
} // namespace OgreScene
#endif