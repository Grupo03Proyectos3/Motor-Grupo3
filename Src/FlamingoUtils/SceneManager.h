#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__
#pragma once
#include <OgreSceneManager.h>
#include <unordered_map>
#include "Scene.h"
namespace OgreScene{
    class SceneManager{
      public:
        SceneManager(Ogre::String t_Name);
        ~SceneManager();
        void init(Ogre::Root* t_root);
        Scene* createScene(Ogre::String t_SceneName,bool setActive=false);
        void addScene(Scene* t_Scene);
        void delScene(Ogre::String t_SceneName);
        void setSceneActive(Ogre::String t_SceneName);
        Scene* getSceneActive();

      private:
        Ogre::Root* mRoot;
        std::unordered_map<Ogre::String, Scene*> mScenes;
        Ogre::String mNameSceneActive = "";
        Ogre::String mName;
    };
} // namespace OgreScene
#endif