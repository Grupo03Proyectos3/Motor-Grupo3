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
namespace CEGUI
{
    class Window;
}
namespace Flamingo{
    class Scene{
      public:
        Scene();
        ~Scene();
        void initScene(Ogre::SceneManager* t_SceneManager, CEGUI::Window* root, ecs::Manager* mng);
        void addObjects(ecs::GameObject* t_GameObject);
        void delObject(std::string t_nameObject);
        void setDebug(bool t_active);

        void destroySceneObjects();
        void desactive();
        void active();
        ecs::GameObject* getObject(std::string t_name);

        std::string getName();
        Ogre::SceneManager* getSceneManger();//NO EXPORTAR
        Ogre::SceneNode* getSceneRoot();     //NO EXPORTAR 
        CEGUI::Window* getCeguiRoot();       //NO EXPORTAR
      private:
        ecs::Manager* m_mngr;
        Ogre::SceneNode* m_OgreRootNode;
        CEGUI::Window* m_CeguiRootNode;
        Ogre::SceneManager* m_SceneManager;
        std::unordered_map<std::string, ecs::GameObject*> m_SceneGameObjects;
        bool mDebug;
    }; 
} // namespace OgreScene
#endif