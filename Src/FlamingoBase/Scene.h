#ifndef __SCENE_H__
#define __SCENE_H__
#pragma once
#include <OgreSceneManager.h>
#include <unordered_map>
#include "Ecs/GameObject.h"

namespace Flamingo{
    class Scene{
      public:
        Scene();
        ~Scene();
        void initScene(Ogre::SceneManager* t_SceneManager, ecs::Manager* mng);
        void addObjects(ecs::GameObject* t_GameObject);
        void delObject(std::string t_nameObject);
        void setDebug(bool t_active);

        void destroySceneObjects();
        void desactive();
        void active();

        inline Ogre::String getName() { return mSceneManager->getName(); };
        inline Ogre::SceneManager* getSceneManger() { return mSceneManager; };
        inline Ogre::SceneNode* getSceneRoot() { return mRootNode; };      
      private:
        ecs::Manager* m_mngr;
        Ogre::SceneNode* mRootNode;
        Ogre::SceneManager* mSceneManager;
        std::unordered_map<std::string, ecs::GameObject*> mSceneGameObjects;
        bool mDebug;
    }; 
} // namespace OgreScene
#endif