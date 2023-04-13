#include "Scene.h"
#include <iostream>
#include "SceneManager.h"
#include <OgreSceneManagerEnumerator.h>
#include <OgreRoot.h>
namespace Flamingo{
    SceneManager::SceneManager(std::string t_Name){
        m_scenes = std::unordered_map<std::string, Scene*>();
        mName = t_Name;
    }

    SceneManager::~SceneManager(){
        for (auto it = m_scenes.begin(); it != m_scenes.end(); it = m_scenes.erase(it)){
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

    Scene* SceneManager::createScene(std::string t_SceneName, bool setActive)
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
        
        if (m_scenes.find(t_SceneName->getName()) == m_scenes.end()){
            m_scenes.insert({t_SceneName->getName(), t_SceneName});
            t_SceneName->getSceneManger();
            std::cout <<"Scene " << t_SceneName->getName() << " Added\n ";
        }
    }

    void SceneManager::delScene(std::string t_SceneName){
        auto t_aux = m_scenes.find(t_SceneName);
        if (t_aux != m_scenes.end()){
            m_scenes.erase(t_aux);
            std::cout <<mName << "Scene " << t_SceneName << " Deleted\n ";
        }
    }

    void SceneManager::setSceneActive(std::string t_SceneName){
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