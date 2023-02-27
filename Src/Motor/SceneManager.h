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
        void initScene(Ogre::Root* t_root);
        void addScene(Scene* t_Scene);
        void delScene(Ogre::String t_SceneName);
        void setDebug(bool t_active);
        void setSceneActive(Ogre::String t_SceneName);
        Scene* getSceneActive();

      private:
        Ogre::Root* mRoot;
        std::unordered_map<Ogre::String, Scene*> mScenes;
        bool mDebug;
        Ogre::String mNameSceneActive;
        Ogre::String mName;
    };
} // namespace OgreScene
#endif