#include "ParticleSystem.h"
Flamingo::ParticleSystem::ParticleSystem()
{
}

Flamingo::ParticleSystem::ParticleSystem(std::string t_name, bool t_loop, float t_duration, int t_particles)
    : m_name(t_name)
    , m_loop(t_loop)
    , m_duration(t_duration)
    , m_particles(t_particles)
{
}

Flamingo::ParticleSystem::~ParticleSystem()
{
}

void Flamingo::ParticleSystem::initComponent()
{
    //m_particle_system = new Ogre::ParticleSystem();
}

void Flamingo::ParticleSystem::emit()
{

}
