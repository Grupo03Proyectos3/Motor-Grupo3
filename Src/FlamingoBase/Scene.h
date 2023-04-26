#ifndef __SCENE_H__
#define __SCENE_H__
#pragma once

#include <unordered_map>
#include "Ecs/GameObject.h"

namespace Ogre
{
    class SceneManager;
    class SceneNode;
}

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
        ecs::GameObject* getObject(std::string t_name);

        std::string getName();
        Ogre::SceneManager* getSceneManger();
        Ogre::SceneNode* getSceneRoot();      
      private:
        ecs::Manager* m_mngr;
        Ogre::SceneNode* mRootNode;
        Ogre::SceneManager* mSceneManager;
        std::unordered_map<std::string, ecs::GameObject*> mSceneGameObjects;
        bool mDebug;
    }; 
} // namespace OgreScene
#endif