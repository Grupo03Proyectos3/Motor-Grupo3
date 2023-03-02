#include "RigidBody.h"
#include <BulletDynamics/Dynamics/btRigidBody.h>
#include <LinearMath/btTransform.h>

#include "../FlamingoUtils/SVector3.h"
#include "../FlamingoUtils/SQuaternion.h"
#include "../FlamingoBase/Transform.h"

RigidBody::RigidBody()
{
}

RigidBody::RigidBody(float t_mass, bool t_trigger, bool t_static)
    : m_mass(t_mass), m_trigger(t_trigger), m_static(t_static)
{
}

RigidBody::~RigidBody()
{
    delete m_bullet_transform;
    delete m_rigid_body;
}

void RigidBody::initComponent()
{
    // Translate our location and rotation to bullet's language
    m_bullet_transform = new btTransform();
}

void RigidBody::setMass(const float& t_mass)
{
    m_mass = t_mass;
}

void RigidBody::setTrigger(bool t_trigger)
{
    m_trigger = t_trigger;
}

void RigidBody::setStatic(bool t_static)
{
    m_static = t_static;
}

//void RigidBody::setLinearVelocity(const SVector3& t_velocity)
//{
//    //m_rigid_body->setLinearVelocity(btVector3(t_velocity)); // conversor de SVector3 a btVector3
//}
//
//void RigidBody::setAngularVelocity(const SVector3& t_velocity)
//{
//   // m_rigid_body->setAngularVelocity(t_velocity); // conversor de SVector3 a btVector3
//}
//
//SVector3 RigidBody::getLinearVelocity() const
//{
//    //return m_rigid_body->getLinearVelocity(); // conversor de btVector3 a SVector3
//}
//
//SVector3 RigidBody::getAngularVelocity() const
//{
//    //return m_rigid_body->getAngularVelocity(); // conversor de btVector3 a SVector3
//}
