#ifndef __SCENE_H__
#define __SCENE_H__
#pragma once
#include <OgreSceneManager.h>
#include <unordered_map>
#include "FlamingoUtils/GameObject.h"

namespace OgreScene{
    class Scene{
      public:
        Scene();
        void initScene(Ogre::SceneManager* t_SceneManager);
        void addObjects(GameObject* t_GameObject);
        void delObject(std::string t_nameObject);
        void setDebug(bool t_active);

        void desactive();
        void active();

        inline Ogre::String getName() { return mSceneManager->getName(); };
        inline Ogre::SceneManager* getSceneManger() { return mSceneManager; };

      private:
        Ogre::SceneNode* mRootNode;
        Ogre::SceneManager* mSceneManager;
        std::unordered_map<std::string, GameObject*> mSceneGameObjects;
        bool mDebug;
    };
} // namespace OgreScene
#endif