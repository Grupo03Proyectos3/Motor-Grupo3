#include "Scene.h"
#include <iostream>
#include "SceneManager.h"
namespace OgreScene{
    SceneManager::SceneManager(Ogre::String t_Name){
        mDebug = false;
        mScenes = std::unordered_map<std::string, Scene*>();
        mName = t_Name;
    }

    void SceneManager::initScene(Ogre::Root* t_root){
        mRoot = t_root;
    }

    void SceneManager::addScene(Scene* t_Scene){
        // DEJARLO ASI O K SUDE Y SE CAMBIE POR SI ENTRA OTRO CON EL MISMO NOMBRE
        if (mScenes.find(t_Scene->getName()) != mScenes.end()){
            mScenes.insert({t_Scene->getName(), t_Scene});
            t_Scene->getSceneManger();
            if (mDebug)std::cout << "SCENE NAME: " << t_Scene->getName() << " ADDED\n";
        }
    }

    void SceneManager::delScene(Ogre::String t_sceneName){
        auto t_aux = mScenes.find(t_sceneName);
        if (t_aux != mScenes.end()){
            mScenes.erase(t_aux);
            if (mDebug)std::cout << "SCENE NAME: " << t_sceneName << " DELETED\n";
        }
    }

    void SceneManager::setDebug(bool t_active){
        mDebug = t_active;
    }

    void SceneManager::setSceneActive(Ogre::String t_SceneName){
        auto t_aux = mScenes.find(t_SceneName);
        if (t_aux != mScenes.end()){
            (*mScenes.find(mNameSceneActive)).second->desactive();
            (*t_aux).second->active();
        }
    }

    Scene* SceneManager::getSceneActive(){
        if (mScenes.empty()){
            std::cout << "ERROR: NO HAY ESCENAS ACTIVAS EN"<<mName<<"\n";
            exit(1);
        }
        return (*mScenes.find(mNameSceneActive)).second;
    }

} // namespace OgreScene