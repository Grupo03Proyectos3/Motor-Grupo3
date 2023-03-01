#include "Scene.h"
#include <iostream>
#include "SceneManager.h"
#include <OgreSceneManagerEnumerator.h>
#include <OgreRoot.h>
namespace OgreScene{
    SceneManager::SceneManager(Ogre::String t_Name){
        mScenes = std::unordered_map<std::string, Scene*>();
        mName = t_Name;
    }

    SceneManager::~SceneManager(){
        for (auto it : mScenes){
            delete it.second;
        }
        mScenes.clear();
    }

    void SceneManager::init(Ogre::Root* t_root){
        mRoot = t_root;
        createScene("DefaultScene", true);
    }

    Scene* SceneManager::createScene(Ogre::String t_SceneName, bool setActive)
    {
        Scene* scene = new Scene();
        auto newSceneManager = mRoot->createSceneManager(Ogre::DefaultSceneManagerFactory::FACTORY_TYPE_NAME, t_SceneName);
        scene->initScene(newSceneManager);
        addScene(scene);
        if (setActive){
            setSceneActive(t_SceneName);
        }
        else scene->desactive();
        
        return scene;
    }

    void SceneManager::addScene(Scene* t_SceneName){
        // DEJARLO ASI O K SUDE Y SE CAMBIE POR SI ENTRA OTRO CON EL MISMO NOMBRE
        if (mScenes.find(t_SceneName->getName()) == mScenes.end()){
            mScenes.insert({t_SceneName->getName(), t_SceneName});
            t_SceneName->getSceneManger();
            std::cout <<"Scene " << t_SceneName->getName() << " Added\n ";
        }
    }

    void SceneManager::delScene(Ogre::String t_SceneName){
        auto t_aux = mScenes.find(t_SceneName);
        if (t_aux != mScenes.end()){
            mScenes.erase(t_aux);
            std::cout <<mName << "Scene " << t_SceneName << " Deleted\n ";
        }
    }

    void SceneManager::setSceneActive(Ogre::String t_SceneName){
        auto t_aux = mScenes.find(t_SceneName);
        if (t_aux != mScenes.end()){
            if (mNameSceneActive != ""){
                (*mScenes.find(mNameSceneActive)).second->desactive();
            }
            (*t_aux).second->active();
            mNameSceneActive = t_SceneName;        
        }       
    }

    Scene* SceneManager::getSceneActive(){
        if (mScenes.empty()){
            std::cout << "ERROR: NO HAY ESCENAS ACTIVAS EN "<<mName<<"\n";
            exit(1);
        }
        return (*mScenes.find(mNameSceneActive)).second;
    }

} // namespace OgreScene