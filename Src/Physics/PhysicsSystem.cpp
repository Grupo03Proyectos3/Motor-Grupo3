#include "PhysicsSystem.h"
#include <btBulletDynamicsCommon.h>
#include <BulletDynamics/Dynamics/btRigidBody.h>

PhysicsSystem::PhysicsSystem()
{
}

PhysicsSystem::~PhysicsSystem()
{
    delete m_dispatcher;
    delete m_collision_config;
    delete m_broadphase;
    delete m_solver;
    delete m_world;
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
    m_solver = new btSequentialImpulseConstraintSolver;

    m_world = new btDiscreteDynamicsWorld(m_dispatcher, m_broadphase, m_solver, m_collision_config);

    // Optional : set gravity to a certain value, plus other characteristics we need
    // m_world->setGravity();
}

void PhysicsSystem::update(float t_delta_time)
{
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
