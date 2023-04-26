#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__
#pragma once
#include "ECS/SingletonECS.h"
#include <unordered_map>
#include "Scene.h"

namespace Flamingo
{
    class PhysicsSystem;
    class RenderSystem;
    class UISystem;
} 
namespace Ogre
{
    class Root;
    class SceneManager;
}

namespace Flamingo{
    class SceneManager : public SingletonECS<Flamingo::SceneManager>
    {
        friend PhysicsSystem;
        friend RenderSystem;
        friend UISystem;
        friend SingletonECS<SceneManager>;
      public:
        SceneManager();
        ~SceneManager();       
        void initManager(std::string t_Name, ecs::Manager* m_mng);

        Scene* createScene(std::string t_SceneName,bool setActive=false);
        void delScene(std::string t_SceneName);

        void setSceneActive(std::string t_SceneName);
        Scene* getSceneActive();

        void addScene(Scene* t_Scene);
      protected:
        inline Ogre::Root* getOgreRoot() { return m_OgreRoot; }

      private:
        ecs::Manager* m_mngr;
        Ogre::Root* m_OgreRoot;
      
        std::unordered_map<std::string, Scene*> m_scenes;
        std::string mNameSceneActive = "";
        std::string mName;        
    };
    // This macro defines a compact way for using the singleton
    //
    SceneManager& SceneMngr();
} // namespace OgreScene
#endif