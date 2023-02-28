#include "Scene.h"
#include <iostream>
namespace OgreScene{

    Scene::Scene(){
        mSceneManager = nullptr;
        mSceneGameObjects = std::unordered_map<Ogre::String, GameObject*>();
        mDebug = false;
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
        std::cout << "SCENE NAME: " << mSceneManager->getName() << " DESACTIVATED\n";
    }

    void Scene::active(){
        mRootNode->setVisible(true);
        std::cout << "SCENE NAME: " << mSceneManager->getName() << " ACTIVATED\n";
    }   

} // namespace OgreScene