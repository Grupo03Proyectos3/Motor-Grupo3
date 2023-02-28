#include "Scene.h"
#include <iostream>


namespace OgreScene{

    Scene::Scene(){
        mSceneManager = nullptr;
        mSceneGameObjects = std::unordered_map<Ogre::String, GameObject*>();
        mDebug = false;
    }

    Scene::~Scene(){
        for (auto it : mSceneGameObjects){
            delete it.second;
        }
        mSceneGameObjects.clear();
        std::cout << "Scene " << mSceneManager->getName() << " deleted\n";
    }

    void Scene::initScene(Ogre::SceneManager* t_SceneManager){
        mSceneManager = t_SceneManager;    
        mRootNode = mSceneManager->getRootSceneNode();
    }
    
    void Scene::addObjects(GameObject* t_GameObject){
        // DEJARLO ASI O K SUDE Y SE CAMBIE POR SI ENTRA OTRO CON EL MISMO NOMBRE
        if (mSceneGameObjects.find(t_GameObject->getName()) != mSceneGameObjects.end()){ 
            mSceneGameObjects.insert({t_GameObject->getName(), t_GameObject});
            if(mDebug)std::cout << "OBJECT NAME: " << t_GameObject->getName() << " ADDED\n";
        }
    }

    void Scene::delObject(std::string t_nameObject){
        auto t_aux = mSceneGameObjects.find(t_nameObject);
        if (t_aux != mSceneGameObjects.end()){
            mSceneGameObjects.erase(t_aux);
            if (mDebug) std::cout << "OBJECT NAME: " << t_nameObject << " DELETED\n";
        }
    }

    void Scene::setDebug(bool t_active){
        mDebug = t_active;
    }

    void Scene::desactive(){       
        mRootNode->setVisible(false);
        for (auto it : mSceneGameObjects){
            //if (it.second->hasComponent<Camera>()){
            //    //it.second->getComponent<Camera>()->desactiveViewport();
            //}
        }
        std::cout << "SCENE NAME: " << mSceneManager->getName() << " DESACTIVATED\n";
    }

    void Scene::active(){
        mRootNode->setVisible(true);
        for (auto it : mSceneGameObjects){
            //if (it.second->hasComponent<Camera>()){
            //    //it.second->getComponent<Camera>()->desactiveViewport();
            //}
        }
        std::cout << "SCENE NAME: " << mSceneManager->getName() << " ACTIVATED\n";
    }   

} // namespace OgreScene