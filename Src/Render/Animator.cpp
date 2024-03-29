#include "Animator.h"

#include <OgreAnimation.h>
#include <OgreKeyFrame.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>

#include "ECS/Manager.h"
#include "RenderSystem.h"

namespace Flamingo
{

    Animator::Animator() {}

    void Animator::initValues(std::string name)
    {
        m_scene_mngr = Flamingo::FlamingoSceneManager().getSceneToAttach()->getSceneManger();
        m_name = name;
        m_num_animations_active = (0);
        m_transform = nullptr;
        m_meshRenderer = nullptr;
    }

    void Animator::initComponent()
    {
        m_transform = m_mngr->getComponent<Transform>(m_ent);
    
        if (m_transform == nullptr)
        {
            throw std::exception("Transform is missing");
        }

        m_meshRenderer = m_mngr->getComponent<MeshRenderer>(m_ent);
 
        if (m_meshRenderer == nullptr)
        {
            throw std::exception("MeshRenderer is missing");
        }
       
        m_animations = std::unordered_map<std::string, Ogre::AnimationState*>();
        if (m_meshRenderer->getEntity()->getAllAnimationStates() != nullptr)
        {
            Ogre::AnimationStateMap mapa = m_meshRenderer->getEntity()->getAllAnimationStates()->getAnimationStates();
            std::cout << m_name << " My Animations: ";
            for (auto it = mapa.begin(); it != mapa.end(); it++)
            {
                m_animations.insert({it->first, it->second});
                std::cout << it->first << "\n";
            }
            std::cout << "\n";
        }
    }

    void Animator::createAnimation(std::string t_name, double t_duration)
    {
        Ogre::Animation* animation = m_scene_mngr->createAnimation(t_name, Ogre::Real(t_duration));
        Ogre::NodeAnimationTrack* track = animation->createNodeTrack(0);
        track->setAssociatedNode(m_meshRenderer->getNode());

        auto aux = m_scene_mngr->createAnimationState(t_name);
        m_animations.insert({t_name, aux});
        setAnimation(t_name, false, false);
    }

    void Animator::setFrameAnimation(std::string t_nameAnimation, double t_duration,
                                     SVector3 t_translate, SQuaternion t_rotacion, SVector3 t_scale)
    {
        Ogre::Animation* animation = m_scene_mngr->getAnimation(t_nameAnimation);
        Ogre::NodeAnimationTrack* track = animation->getNodeTrack(0);

        Ogre::TransformKeyFrame* kf = track->createNodeKeyFrame(Ogre::Real(t_duration));
        kf->setTranslate(t_translate);
        kf->setRotation(t_rotacion);
        kf->setScale(t_scale);
    }

    void Animator::allAnimations(bool t_active)
    {
        m_num_animations_active = t_active == true ? m_animations.size() : 0;
        for (auto it = m_animations.begin(); it != m_animations.end(); it++)
        {
            it->second->setEnabled(t_active);
            it->second->setLoop(t_active);
        }
    }

    void Animator::setAnimation(std::string t_name, bool t_active, bool t_loop)
    {
        auto it = m_animations.find(t_name);
        if (it != m_animations.end())
        {
            it->second->setEnabled(t_active);
            it->second->setLoop(t_loop);
            m_num_animations_active += t_active ? +1 : -1;
        }
       
    }

    void Animator::updateAnimations(double time)
    {
        int num = 0;
        auto it = m_animations.begin();
        while (num != m_num_animations_active)
        {
            if (it->second->getEnabled())
            {
                it->second->addTime(Ogre::Real(time));
                num++;
            }
            it++;
        }
    }
} // namespace Flamingo