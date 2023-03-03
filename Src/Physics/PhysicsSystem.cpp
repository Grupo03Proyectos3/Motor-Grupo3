#include "PhysicsSystem.h"

#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

#include "ECS/GameObject.h"
#include "ECS/Manager.h"
#include "RigidBody.h"

PhysicsSystem::PhysicsSystem()
{
    m_group = ecs::GROUP_PHYSICS;
}

PhysicsSystem::~PhysicsSystem()
{
    if (m_dispatcher != nullptr)
    {
        delete m_dispatcher;
    }
    if (m_collision_config != nullptr)
    {
        delete m_collision_config;
    }
    if (m_broadphase)
    {
        delete m_broadphase;
    }
    if (m_solver != nullptr)
    {
        delete m_solver;
    }
    if (m_world != nullptr)
    {
        delete m_world;
    }
}

void PhysicsSystem::recieve(const Message& t_message)
{
    switch (t_message.id)
    {
        default:
            // MESSAGE RECIEVED
            break;
    }
}

void PhysicsSystem::initSystem()
{
    m_collision_config = new btDefaultCollisionConfiguration();
    m_dispatcher = new btCollisionDispatcher(m_collision_config);
    m_broadphase = new btDbvtBroadphase();
    // Tipo por defecto de solver
    m_solver = new btSequentialImpulseConstraintSolver();

    m_world = new btDiscreteDynamicsWorld(m_dispatcher, m_broadphase, m_solver, m_collision_config);

    // Optional : set gravity to a certain value, plus other characteristics we need
    // m_world->setGravity();
}

void PhysicsSystem::update(float t_delta_time)
{
    // For each GameObject that has at least one Physics type component,
    // check for the components and update them
    for (auto game_object : m_mngr->getEntities(m_group))
    {
        if (auto rb = m_mngr->getComponent<RigidBody>(game_object))
        {
            // TODO actualise position with Transform values --> Check if its really necessary
            //rb->setPosition();
        }
    }

    // TO DO add forces with input/scripts

    if (m_world)
    {
        m_world->stepSimulation(t_delta_time);
    }
}

void PhysicsSystem::addRigidBody(btRigidBody* t_rb)
{
    m_world->addRigidBody(t_rb);
}

btRigidBody* PhysicsSystem::createRigidBody(btTransform* t_transform, btCollisionShape* t_shape, const float& t_mass)
{
    return nullptr;
}
