#include "RigidBody.h"
#include <BulletDynamics/Dynamics/btRigidBody.h>
#include <LinearMath/btTransform.h>

#include "FlamingoBase/Transform.h"
#include "../FlamingoUtils/SQuaternion.h"
#include "../FlamingoUtils/SVector3.h"

RigidBody::RigidBody()
{
}

RigidBody::RigidBody(float t_mass, bool t_trigger, bool t_static)
    : m_mass(t_mass)
    , m_trigger(t_trigger)
    , m_static(t_static)
{
}

RigidBody::~RigidBody()
{
    delete m_bullet_transform;
    delete m_rigid_body;
}

void RigidBody::initComponent()
{
    // TODO Se deben pasar a la constructora los valores del Transform
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

void RigidBody::setKinematic(bool t_kinematic)
{
    m_kinematic = t_kinematic;
}

void RigidBody::setPosition(SVector3 t_pos)
{
    btTransform transform = m_rigid_body->getWorldTransform();
    transform.setOrigin(btVector3(t_pos));
    m_rigid_body->setWorldTransform(transform);
}

void RigidBody::setRotation(SQuaternion t_rot)
{
    btTransform transform = m_rigid_body->getWorldTransform();
    transform.setRotation(btQuaternion(t_rot));
    m_rigid_body->setWorldTransform(transform);
}

void RigidBody::setLinearVelocity(const SVector3& t_velocity)
{
    m_rigid_body->setLinearVelocity(btVector3(t_velocity));
}

void RigidBody::setAngularVelocity(const SVector3& t_velocity)
{
    m_rigid_body->setAngularVelocity(t_velocity);
}

SVector3 RigidBody::getPosition() const
{
    return SVector3::bulletToSVector3(m_rigid_body->getWorldTransform().getOrigin());
}

SQuaternion RigidBody::getRotation() const
{
    return SQuaternion::bulletToQuaternion(m_rigid_body->getWorldTransform().getRotation());
}

SVector3 RigidBody::getLinearVelocity() const
{
    return SVector3::bulletToSVector3(m_rigid_body->getLinearVelocity());
}

SVector3 RigidBody::getAngularVelocity() const
{
    return SVector3::bulletToSVector3(m_rigid_body->getAngularVelocity());
}
