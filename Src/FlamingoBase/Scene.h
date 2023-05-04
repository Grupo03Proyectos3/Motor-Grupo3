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
        FLAMINGOEXPORT_API Scene();
        FLAMINGOEXPORT_API  ~Scene();
        FLAMINGOEXPORT_API void initScene(std::string name);
        FLAMINGOEXPORT_API void addObjects(GameObject* t_GameObject);
        FLAMINGOEXPORT_API void delObject(std::string t_nameObject);
        FLAMINGOEXPORT_API void setDebug(bool t_active);

        FLAMINGOEXPORT_API void destroySceneObjects();
        FLAMINGOEXPORT_API void desactive();
        FLAMINGOEXPORT_API void active();
        FLAMINGOEXPORT_API GameObject* getObject(std::string t_name);

        FLAMINGOEXPORT_API std::string getName();
        Ogre::SceneManager* getSceneManger();//NO EXPORTAR
        Ogre::SceneNode* getSceneRoot();     //NO EXPORTAR 
        CEGUI::Window* getCeguiRoot();       //NO EXPORTAR
      private:
        Manager* m_mngr;
        Ogre::SceneNode* m_OgreRootNode;
        CEGUI::Window* m_CeguiRootNode;
        Ogre::SceneManager* m_SceneManager;
        std::unordered_map<std::string, GameObject*> m_SceneGameObjects;
        std::string m_name;
        bool mDebug;
    }; 
} // namespace OgreScene
#endif