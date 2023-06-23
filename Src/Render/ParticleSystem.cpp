#include "ParticleSystem.h"

#include <FlamingoBase/SceneManager.h>
#include <OgreParticleSystem.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreTechnique.h>
//#include <FlamingoBase/Transform.h>
#include "ECS/ManagerFunctions.h"

Flamingo::ParticleSystem::ParticleSystem()
{
}

Flamingo::ParticleSystem::~ParticleSystem()
{
    m_scene_mngr->destroyParticleSystem(m_particle_system);
    m_scene_mngr->destroySceneNode(m_node);
}

void Flamingo::ParticleSystem::initComponent()
{
    // m_particle_system = new Ogre::ParticleSystem();
    /*  m_particle_system = m_scene_mngr->createParticleSystem("psBomba", "PsPrueba/Smoke");
      m_particle_system->setEmitting(true);
      m_node->attachObject(m_particle_system);
      m_node->setPosition({0, 60, 0});*/
    auto t = getComponent<Transform>(m_ent);
    if (t == nullptr)
    {
        throw std::exception("Transform is missing");
    }

    m_node->setScale(t->getScale());
    m_node->setPosition(t->getPosition());
    m_node->attachObject(m_particle_system);
}

void Flamingo::ParticleSystem::initValues(const std::string& t_name, const std::string& t_template)
{
    m_scene_mngr = FlamingoSceneManager().getSceneToAttach()->getSceneManger();
    m_particle_system = m_scene_mngr->createParticleSystem(t_name, t_template);
    m_node = FlamingoSceneManager().getSceneToAttach()->getSceneRoot()->createChildSceneNode();

    emit(true);
}

void Flamingo::ParticleSystem::emit(bool t_state)
{
    m_particle_system->setEmitting(t_state);
}
