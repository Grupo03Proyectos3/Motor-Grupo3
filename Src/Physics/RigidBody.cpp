#include "RigidBody.h"
#include <BulletCollision/CollisionShapes/btBoxShape.h>
#include <BulletDynamics/Dynamics/btRigidBody.h>
#include <LinearMath/btTransform.h>

#include "PhysicsSystem.h"

#include "FlamingoUtils/SQuaternion.h"
#include "FlamingoUtils/SVector3.h"
#include "Render/MeshRenderer.h"
#include "FlamingoBase/Transform.h"
#include "FlamingoUtils/SQuaternion.h"
#include "FlamingoUtils/SVector3.h"
#include "Ogre.h"
namespace Flamingo
{
    RigidBody::RigidBody()
    {
    }

    RigidBody::~RigidBody()
    {
        delete m_rigid_body->getMotionState();
        // delete m_rigid_body->getCollisionShape(); // lo hace el sistema
        m_rigid_body->setUserPointer(nullptr);

        m_mngr->getSystem<Flamingo::PhysicsSystem>()->removeRigidBody(m_rigid_body);

        delete m_bullet_transform;
        m_bullet_transform = nullptr;

        m_rigid_body->setUserPointer(nullptr);

        delete m_rigid_body;
        m_rigid_body = nullptr;
    }

    void RigidBody::initValues(float t_mass, bool t_trigger, bool t_static)
    {
        m_trigger = (t_trigger);
        m_static = (t_static);
        if (t_static)
            m_mass = 0.0f;
        else
            m_mass = (t_mass);
    }

    void RigidBody::initComponent()
    {
        // TO DO a�adir try catch por si no tiene transform

        auto transform = m_mngr->getComponent<Transform>(m_ent);

        if (auto mr = m_mngr->getComponent<MeshRenderer>(m_ent))
        {
            const Ogre::AxisAlignedBox& meshBoundingBox = mr->getBoundingBox();
            // Calculate the dimensions of the box collider
            btVector3 halfExtents(meshBoundingBox.getSize().x * 0.5f, meshBoundingBox.getSize().y * 0.5f, meshBoundingBox.getSize().z * 0.5f);
            halfExtents *= transform->getScale();
            m_shape = new btBoxShape(halfExtents);
        }
        else // TODO a�adir else: collider a un tama�o por defecto
        {
            m_shape = new btBoxShape({1.0f, 1.0f, 1.0f});
        }

        m_bullet_transform = new btTransform(transform->getRotation(), transform->getPosition());

        // TODO meter diferentes formas para el RB
        //   m_shape = new btBoxShape(transform->getScale());

        //   m_state = new FlamingoMotionState(*m_bullet_transform, transform);

        m_rigid_body = m_mngr->getSystem<Flamingo::PhysicsSystem>()->createRigidBody(m_bullet_transform, m_shape, m_mass);

        // Guardamosla referencia en un void* de bullet para recuperarlo en el callback de colisiones
        m_rigid_body->setUserPointer(this);

        if (m_static)
        {
            m_rigid_body->setCollisionFlags(btCollisionObject::CF_STATIC_OBJECT);
            m_rigid_body->setGravity(btVector3(0.0, 0.0, 0.0));
            //    m_rigid_body->setActivationState(DISABLE_DEACTIVATION);
        }

        m_mngr->getSystem<Flamingo::PhysicsSystem>()->addRigidBody(m_rigid_body);
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
} // namespace Flamingo