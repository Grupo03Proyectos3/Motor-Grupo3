#include "RigidBody.h"
#include <BulletDynamics/Dynamics/btRigidBody.h>
#include <LinearMath/btTransform.h>
#include <BulletCollision/CollisionShapes/btBoxShape.h>

#include "PhysicsSystem.h"

#include "FlamingoBase/Transform.h"
#include "../FlamingoUtils/SQuaternion.h"
#include "../FlamingoUtils/SVector3.h"

#include "Ogre.h"

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
    // THE SYSTEM DELETES EVERYTHING
}

void RigidBody::initComponent()
{
    // TODO inicializar transform como primer componente SIEMPRE
    auto transform = m_mngr->getComponent<Transform>(m_ent);

    // Get the mesh data from the Ogre scene node --> REVISAR
    Ogre::Entity* entity = (Ogre::Entity*)transform->getNode()->getAttachedObject(0);
    Ogre::MeshPtr mesh = entity->getMesh();
    const Ogre::AxisAlignedBox& meshBoundingBox = mesh->getBounds();

    // Calculate the dimensions of the box collider --> REVISAR
    btVector3 halfExtents(meshBoundingBox.getSize().x * 0.5f, meshBoundingBox.getSize().y * 0.5f, meshBoundingBox.getSize().z * 0.5f);
    halfExtents *= transform->getScale();

    // Create a Bullet box shape using the calculated dimensions
    m_shape = new btBoxShape(halfExtents);

    m_bullet_transform = new btTransform(transform->getRotation(), transform->getPosition());
    // TODO meter diferentes formas para el RB
 //   m_shape = new btBoxShape(transform->getScale());
    m_rigid_body = m_mngr->getSystem<PhysicsSystem>()->createRigidBody(m_bullet_transform, m_shape, m_mass);
    m_mngr->getSystem<PhysicsSystem>()->addRigidBody(m_rigid_body);
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
