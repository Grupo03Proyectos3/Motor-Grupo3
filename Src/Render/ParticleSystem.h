#pragma once
#ifndef __PARTICLE_SYSTEM_H__
#define __PARTICLE_SYSTEM_H__

#include "ECS/Component.h"

#include <FlamingoUtils/SQuaternion.h>
#include <FlamingoUtils/SVector3.h>
#include <FlamingoUtils/Timer.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreParticleSystem.h>
#include <OgreTechnique.h>

#include <string>
namespace Flamingo
{
    struct ParticleSystem : public Component
    {
      public:
        __SYSTEM_ID_DECL__(_cpm_PARTICLE_SYSTEM)

        ParticleSystem();
        ParticleSystem(Ogre::SceneManager* t_mng, Ogre::SceneNode* t_node);
        ~ParticleSystem();
        void initComponent();
        void emit();

      private:
        Ogre::ParticleSystem* m_particle_system = nullptr;
        Ogre::SceneManager* m_scene_mngr;
        Ogre::SceneNode* m_node;
        Flamingo::Timer* m_time;

        std::string m_name;
        bool m_loop;
        float m_duration;
        int m_particles;
    };
} // namespace Flamingo
#endif