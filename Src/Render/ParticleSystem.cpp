#include "ParticleSystem.h"
ParticleSystem::ParticleSystem()
{
}

ParticleSystem::ParticleSystem(std::string t_name, bool t_loop, float t_duration, int t_particles)
    : m_name(t_name)
    , m_loop(t_loop)
    , m_duration(t_duration)
    , m_particles(t_particles)
{
}

ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::initComponent()
{
}
