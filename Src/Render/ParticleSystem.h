#pragma once
#ifndef __PARTICLE_SYSTEM_H__
#define __PARTICLE_SYSTEM_H__

#include "ECS/Component.h"

#include <FlamingoUtils/SQuaternion.h>
#include <FlamingoUtils/SVector3.h>
#include <FlamingoUtils/Timer.h>

namespace Ogre
{
    class ParticleSystem;
    class SceneManager;
    class SceneNode;
}

#include <string>
namespace Flamingo
{
    struct FLAMINGOEXPORT_API ParticleSystem : public Component
    {
      public:
        __SYSTEM_ID_DECL__(_cpm_PARTICLE_SYSTEM)

        ParticleSystem();
       
        ~ParticleSystem();
        void initComponent() override;
        void initValues(const std::string& t_name, const std::string& t_template);
        void emit(bool t_state);

      private:
        Ogre::ParticleSystem* m_particle_system = nullptr;
        Ogre::SceneManager* m_scene_mngr;
        Ogre::SceneNode* m_node;
       

        std::string m_name;
        bool m_loop;
       

        bool m_active;
    };
} // namespace Flamingo
#endif