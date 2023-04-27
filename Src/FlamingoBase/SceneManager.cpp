#include "Scene.h"
#include <iostream>
#include "SceneManager.h"
#include <OgreSceneManagerEnumerator.h>
#include <OgreRoot.h>
#include "ECS/Manager.h"
#include "Render/RenderSystem.h"
#include "UI/UISystem.h"
namespace Flamingo
{
    SceneManager::SceneManager(){
            m_scenes = std::unordered_map<std::string, Scene*>();
    }

    SceneManager::~SceneManager(){
        for (auto it = m_scenes.begin(); it != m_scenes.end(); it = m_scenes.erase(it)){
            delete it->second;
        }
        m_scenes.clear();

        m_OgreRoot = nullptr;
    }

    void SceneManager::initManager(std::string t_Name, Manager* m_mng){
        mName = t_Name;
        m_mngr = m_mng;
        auto syse = m_mngr->getSystem<RenderSystem>();
        m_OgreRoot = syse->getOgreRoot();

        createScene("DefaultScene", true);
    }

    Scene* SceneManager::createScene(std::string t_SceneName, bool setActive)
    {
        Scene* scene = new Scene();
       auto m_scene_manager = m_OgreRoot->createSceneManager(Ogre::DefaultSceneManagerFactory::FACTORY_TYPE_NAME, t_SceneName);
        auto sysu = m_mngr->getSystem<UISystem>();
        scene->initScene(m_scene_manager, sysu->createRootScene(t_SceneName), m_mngr);
        addScene(scene);
        if (setActive){
            setSceneActive(t_SceneName);
        }
        else{
            scene->desactive();
        }
        
        return scene;
    }

    void SceneManager::addScene(Scene* t_SceneName){
        
        if (m_scenes.find(t_SceneName->getName()) == m_scenes.end()){
            m_scenes.insert({t_SceneName->getName(), t_SceneName});
            t_SceneName->getSceneManger();
            std::cout <<"Scene " << t_SceneName->getName() << " Added\n ";
        }
        else{
            std::cout << "Already exists a Scene with Name: "<<t_SceneName<<"\n";
            exit(1);
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
            std::cout << "ERROR: There isnt any Scenes Active "<<mName<<"\n";
            exit(1);
        }
        return (*m_scenes.find(mNameSceneActive)).second;
    }

    SceneManager& SceneMngr() {
        return *SceneManager::instance();
    }

} // namespace Flamingo
