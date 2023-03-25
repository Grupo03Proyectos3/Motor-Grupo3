#include "Scene.h"
#include <iostream>
#include "SceneManager.h"
#include <OgreSceneManagerEnumerator.h>
#include <OgreRoot.h>
namespace Flamingo{
    SceneManager::SceneManager(Ogre::String t_Name){
        m_scenes = std::unordered_map<std::string, Scene*>();
        mName = t_Name;
    }

    SceneManager::~SceneManager(){
        for (auto it = m_scenes.begin(); it != m_scenes.end(); it = m_scenes.erase(it))
        {
            // TO DO Por qu� falla aqui
            m_root->destroySceneManager(it->second->getSceneManger());
            delete it->second;
        }
        m_scenes.clear();

       // delete m_scene_manager;
        m_scene_manager = nullptr;
        m_root = nullptr;
    }

    void SceneManager::init(Ogre::Root* t_root){
        m_root = t_root;
        createScene("DefaultScene", true);
    }

    Scene* SceneManager::createScene(Ogre::String t_SceneName, bool setActive)
    {
        Scene* scene = new Scene();
        m_scene_manager = m_root->createSceneManager(Ogre::DefaultSceneManagerFactory::FACTORY_TYPE_NAME, t_SceneName);
        scene->initScene(m_scene_manager);
        addScene(scene);
        if (setActive){
            setSceneActive(t_SceneName);
        }
        else scene->desactive();
        
        return scene;
    }

    void SceneManager::addScene(Scene* t_SceneName){
        // DEJARLO ASI O K SUDE Y SE CAMBIE POR SI ENTRA OTRO CON EL MISMO NOMBRE
        if (m_scenes.find(t_SceneName->getName()) == m_scenes.end()){
            m_scenes.insert({t_SceneName->getName(), t_SceneName});
            t_SceneName->getSceneManger();
            std::cout <<"Scene " << t_SceneName->getName() << " Added\n ";
        }
    }

    void SceneManager::delScene(Ogre::String t_SceneName){
        auto t_aux = m_scenes.find(t_SceneName);
        if (t_aux != m_scenes.end()){
            m_scenes.erase(t_aux);
            std::cout <<mName << "Scene " << t_SceneName << " Deleted\n ";
        }
    }

    void SceneManager::setSceneActive(Ogre::String t_SceneName){
        auto t_aux = m_scenes.find(t_SceneName);
        if (t_aux != m_scenes.end()){
            if (mNameSceneActive != ""){
                (*m_scenes.find(mNameSceneActive)).second->desactive();
            }
            (*t_aux).second->active();
            mNameSceneActive = t_SceneName;        
        }       
    }

    Scene* SceneManager::getSceneActive(){
        if (m_scenes.empty()){
            std::cout << "ERROR: NO HAY ESCENAS ACTIVAS EN "<<mName<<"\n";
            exit(1);
        }
        return (*m_scenes.find(mNameSceneActive)).second;
    }

} // namespace OgreScene