#include "Animator.h"
#include <OgreSceneManager.h>
#include <OgreAnimation.h>
#include <OgreKeyFrame.h>

#include "ECS/Manager.h"
namespace Flamingo{
    Animator::Animator(Ogre::SceneManager* t_mng): 
        m_scene_mngr(t_mng), m_num_animations_active(0){       
    }

    void Animator::initComponent(){      
        m_transform = m_mngr->getComponent<Transform>(m_ent);
        if (m_transform == nullptr){
            std::cout << m_ent->getName() << "ADD TRANSFORM COMPONENT TO SET ANIMATOR COMPONENT\n";
            exit(1);
        }
        m_meshRenderer = m_mngr->getComponent<MeshRenderer>(m_ent);
        if (m_meshRenderer == nullptr){
            std::cout << m_ent->getName() << "ADD MESHRENDERER COMPONENT TO SET ANIMATOR COMPONENT\n";
            exit(1);
        }

        m_animations = std::unordered_map<Ogre::String, Ogre::AnimationState*>();
        Ogre::AnimationStateMap mapa = m_meshRenderer->getEntity()->getAllAnimationStates()->getAnimationStates();
        for (auto it = mapa.begin();it!=mapa.end();it++){
            m_animations.insert({it->first, it->second}); 
            std::cout << it->first << "\n";
        }
    }

    void Animator::createAnimation(Ogre::String t_name, double t_duration){
        Ogre::Animation* animation = m_scene_mngr->createAnimation(t_name, t_duration);
        Ogre::NodeAnimationTrack* track = animation->createNodeTrack(0);
        track->setAssociatedNode(m_transform->getNode());

        auto aux = m_scene_mngr->createAnimationState(t_name);
        m_animations.insert({ t_name, aux});
        setAnimation(t_name, false,false);
    }

    void Animator::setFrameAnimation(Ogre::String t_nameAnimation, double t_duration,
                                     SVector3 t_translate, SQuaternion t_rotacion, SVector3 t_scale){

        Ogre::Animation* animation = m_scene_mngr->getAnimation(t_nameAnimation);
        Ogre::NodeAnimationTrack* track = animation->getNodeTrack(0);

        Ogre::TransformKeyFrame* kf = track->createNodeKeyFrame(t_duration);
        kf->setTranslate(t_translate);
        kf->setRotation(t_rotacion);
        kf->setScale(t_scale);
    }

    void Animator::AllAnimations(bool t_active){
        m_num_animations_active = t_active==true? m_animations.size(): 0;
        for (auto it = m_animations.begin(); it != m_animations.end(); it++){
            it->second->setEnabled(t_active);
            it->second->setLoop(t_active);
        }
    }

    void Animator::setAnimation(Ogre::String t_name,bool t_active, bool t_loop){
        auto it = m_animations.find(t_name);
        if (it != m_animations.end()){
            it->second->setEnabled(t_active);
            it->second->setLoop(t_loop);
        }
        m_num_animations_active++;
    }

    void Animator::updateAnimations(double time){
        int num = 0;
        time *= 0.001;//POR LA CARA SI NO VA RAPISIDISIMO
        auto it = m_animations.begin();
        while (num != m_num_animations_active){
            if (it->second->getEnabled()){
                it->second->addTime(time);
                num++;
            }
            it++;
        }
    }
} // namespace Flamingo