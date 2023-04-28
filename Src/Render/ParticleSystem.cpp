#include "ParticleSystem.h"

#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreParticleSystem.h>
#include <OgreTechnique.h>

Flamingo::ParticleSystem::ParticleSystem()
{
}

Flamingo::ParticleSystem::ParticleSystem(Ogre::SceneManager* t_mng,Ogre::SceneNode* t_node)

    : m_scene_mngr(t_mng)
    , m_node(t_node)
   /* , m_name(t_name)
    , m_loop(t_loop)
    , m_duration(t_duration)
    , m_particles(t_particles)*/
{
}

Flamingo::ParticleSystem::~ParticleSystem()
{
}

void Flamingo::ParticleSystem::initComponent()
{
    // m_particle_system = new Ogre::ParticleSystem();
    m_particle_system = m_scene_mngr->createParticleSystem("psBomba", "PsPrueba/Smoke");
    m_particle_system->setEmitting(true);
    m_node->attachObject(m_particle_system);
    m_node->setPosition({0, 60, 0});

    //// Obtener el material de partículas utilizado por el sistema
    //Ogre::MaterialPtr material = m_particle_system->getMaterial();

    //// Obtener el estado del color del material de partículas
    //Ogre::Pass* pass = material->getTechnique(0)->getPass(0);
    //Ogre::ColourValue color = pass->getDiffuse();

    //// Modificar el color del material de partículas
    //color.r = 1.0f; // Red
    //color.g = 0.0f; // Green
    //color.b = 0.0f; // Blue
    //pass->setDiffuse(color);

    //// Actualizar el material de partículas utilizado por el sistema
    //m_particle_system->setMaterial(material->getName());
}

void Flamingo::ParticleSystem::emit()
{
}
