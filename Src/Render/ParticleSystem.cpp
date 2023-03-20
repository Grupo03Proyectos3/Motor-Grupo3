#include "ParticleSystem.h"

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
}

void Flamingo::ParticleSystem::emit()
{
}
