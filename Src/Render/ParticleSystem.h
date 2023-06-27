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
} // namespace Ogre

#include <string>
namespace Flamingo
{
    /**
     * @brief Componente del sistema de partículas.
     * Para utilizar sistemas existentes, debes leerlos a través del archivo LUA,
     * proporcionando el nombre que deseas asignarle y la plantilla que deseas usar como parámetros.
     * Para crear una nueva plantilla, es necesario definirlo en el archivo SistemasParticulas.material.
     * Los nombres asignados a los sistemas de partículas deben ser distintos
     **/
    struct FLAMINGOEXPORT_API ParticleSystem : public Component
    {
      public:
        __SYSTEM_ID_DECL__(_cpm_PARTICLE_SYSTEM)

        ParticleSystem();

        ~ParticleSystem();
        void initComponent() override;
        void initValues(const std::string& t_name, const std::string& t_template, bool t_static);

        void emit(bool t_state);
        void updatePosition();

      private:
        Ogre::ParticleSystem* m_particle_system;
        Ogre::SceneManager* m_scene_mngr;
        Ogre::SceneNode* m_node;

        std::string m_name;
        bool m_static;

        bool m_active;
    };
} // namespace Flamingo
#endif