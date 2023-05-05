#ifndef __SCENE_H__
#define __SCENE_H__
#pragma once

#include <unordered_map>
#include "Ecs/GameObject.h"
#include "FlamingoExport/FlamingoAPI.h"
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
    class Scene
    {
      public:
        Scene();
         ~Scene();
        FLAMINGOEXPORT_API void initScene(std::string name);
        FLAMINGOEXPORT_API void addObjects(GameObject* t_GameObject);
        FLAMINGOEXPORT_API void delObject(std::string t_nameObject);
        FLAMINGOEXPORT_API void setDebug(bool t_active);

        void destroySceneObject(std::string t_n);
        void destroySceneObjects();
        void desactive();
        void active();
        void startScene();


        bool isSceneActive();
        FLAMINGOEXPORT_API GameObject* getObject(std::string t_name);

        FLAMINGOEXPORT_API std::string getName();
        Ogre::SceneManager* getSceneManger();
        Ogre::SceneNode* getSceneRoot();     
        CEGUI::Window* getCeguiRoot();       
      private:
        Manager* m_mngr;
        Ogre::SceneNode* m_OgreRootNode;
        CEGUI::Window* m_CeguiRootNode;
        Ogre::SceneManager* m_SceneManager;
        std::unordered_map<std::string, GameObject*> m_SceneGameObjects;
        std::string m_name;
        bool mDebug;
        bool m_initialized = false;
        bool m_active = false;
    }; 
} // namespace OgreScene
#endif