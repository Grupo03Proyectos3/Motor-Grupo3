#pragma once
#ifndef __PARTICLE_SYSTEM_H__
#define __PARTICLE_SYSTEM_H__

#include "ECS/Component.h"

#include <FlamingoUtils/SQuaternion.h>
#include <FlamingoUtils/SVector3.h>
#include <FlamingoUtils/Timer.h>
#include <OgreSceneNode.h>
#include <string>
namespace Flamingo
{

    struct ParticleSystem : public ecs::Component
    {
      public:
        __SYSTEM_ID_DECL__(ecs::_cpm_PARTICLE_SYSTEM)

        ParticleSystem();
        ParticleSystem(std::string t_name, bool t_loop, float t_duration, int t_particles);
        ~ParticleSystem();
        void initComponent();
        void emit();

      private:
        Ogre::ParticleSystem* m_particle_system = nullptr;
        Flamingo::Timer* m_time;

        std::string m_name;
        bool m_loop;
        float m_duration;
        int m_particles;
    };
} // namespace Flamingo
#endif