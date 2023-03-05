#pragma once
#include "ECS/component.h"
#include <OgreAnimationState.h>
#include "FlamingoUtils/SVector3.h"
#include "FlamingoUtils/SQuaternion.h"
#include "MeshRenderer.h"
#include "FlamingoBase/Transform.h"
#ifndef __ANIMATOR_H__
#define __ANIMATOR_H__
namespace Flamingo{
    struct Animator : public ecs::Component{
      public:
        __SYSTEM_ID_DECL__(ecs::_cmp_ANIMATOR)
        Animator(Ogre::SceneManager* t_mng);
        virtual ~Animator(){};
        virtual void initComponent();

        void createAnimation(Ogre::String t_name, double t_duration);
        void setFrameAnimation(Ogre::String t_nameAnimation, double t_duration, 
            SVector3 t_translate, SQuaternion t_rotacion, SVector3 t_scale);

        void setAnimation(Ogre::String t_name, bool t_active, bool t_loop=false);      
        void AllAnimations(bool t_active);

        int getAnimationsActive() { return m_num_animations_active; };

        void updateAnimations(double time);
      private:
        std::unordered_map<Ogre::String, Ogre::AnimationState*> m_animations;
        Ogre::SceneManager* m_scene_mngr;
        Transform* m_transform;
        MeshRenderer* m_meshRenderer;
        int m_num_animations_active;
    };
}
#endif