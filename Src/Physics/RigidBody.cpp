#include "RigidBody.h"
#include <BulletCollision/CollisionShapes/btBoxShape.h>
#include <BulletDynamics/Dynamics/btRigidBody.h>
#include <LinearMath/btTransform.h>

#include "PhysicsSystem.h"

#include "FlamingoBase/Transform.h"
#include "FlamingoUtils/SQuaternion.h"
#include "FlamingoUtils/SVector3.h"
#include "Ogre.h"
#include "Render/MeshRenderer.h"

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

        delete m_shape;
        m_shape = nullptr;
    }

    void RigidBody::initValues(float t_mass, bool t_trigger, bool t_static)
    {
        m_trigger = (t_trigger);
        m_static = (t_static);
        if (t_static)
            m_mass = 0.0f;
        else
            m_mass = (t_mass);

        //  auto transform = m_mngr->getComponent<Transform>(m_ent);

        m_shape = new btBoxShape({1.0f, 1.0f, 1.0f});

        m_bullet_transform = new btTransform({0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f});

        m_rigid_body = m_mngr->getSystem<Flamingo::PhysicsSystem>()->createRigidBody(m_bullet_transform, m_shape, m_mass);

        // Guardamosla referencia en un void* de bullet para recuperarlo en el callback de colisiones
        m_rigid_body->setUserPointer(this);

        if (m_static)
        {
            m_rigid_body->setCollisionFlags(btCollisionObject::CF_STATIC_OBJECT);
            m_rigid_body->setGravity(btVector3(0.0, 0.0, 0.0));
            //m_rigid_body->setActivationState(DISABLE_DEACTIVATION);
        }
        else
        {
            m_rigid_body->setCollisionFlags(btCollisionObject::CF_DYNAMIC_OBJECT);
            m_rigid_body->setGravity(btVector3(0.0, -9.8, 0.0));
        }

        // m_mngr->getSystem<Flamingo::PhysicsSystem>()->addRigidBody(m_rigid_body);
    }

    void RigidBody::initComponent()
    {
        // TO DO a�adir control por si no tiene transform
        auto transform = m_mngr->getComponent<Transform>(m_ent);
        auto phys_sys = m_mngr->getSystem<PhysicsSystem>();

        m_bullet_transform->setOrigin(transform->getPosition());
        m_bullet_transform->setRotation(transform->getRotation());

        if (auto mr = m_mngr->getComponent<MeshRenderer>(m_ent))
        {
            delete m_rigid_body->getMotionState();
            phys_sys->removeRigidBody(m_rigid_body);
            delete m_rigid_body;

            //delete m_shape; // already done
            const Ogre::AxisAlignedBox& meshBoundingBox = mr->getBoundingBox();
            // Calculate the dimensions of the box collider
            btVector3 halfExtents(meshBoundingBox.getSize().x * 0.5f, meshBoundingBox.getSize().y * 0.5f, meshBoundingBox.getSize().z * 0.5f);
            halfExtents *= transform->getScale();
            //m_shape = new btBoxShape(halfExtents);
            m_shape->setLocalScaling(halfExtents);

            m_rigid_body = m_mngr->getSystem<Flamingo::PhysicsSystem>()->createRigidBody(m_bullet_transform, m_shape, m_mass);

            // Guardamosla referencia en un void* de bullet para recuperarlo en el callback de colisiones
            m_rigid_body->setUserPointer(this);
        }
        else
        {
            btVector3 halfExtents = transform->getScale();
            m_shape->setLocalScaling(halfExtents);
        }

        m_mngr->getSystem<Flamingo::PhysicsSystem>()->addRigidBody(m_rigid_body);
    }

    void RigidBody::setMass(const float& t_mass)
    {
        m_mass = t_mass;
    }

    void RigidBody::setScale(const SVector3 t_scale)
    {
        if (m_shape == nullptr)
            return;

        m_shape->setLocalScaling(m_shape->getLocalScaling() * t_scale);
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
        if (m_rigid_body == nullptr)
            return;

        btTransform transform = m_rigid_body->getWorldTransform();
        transform.setOrigin(btVector3(t_pos));
        m_rigid_body->setWorldTransform(transform);

        // m_bullet_transform->setOrigin(btVector3(t_pos));
    }

    void RigidBody::setRotation(SQuaternion t_rot)
    {
        if (m_rigid_body == nullptr)
            return;

        btTransform transform = m_rigid_body->getWorldTransform();
        transform.setRotation(btQuaternion(t_rot));
        m_rigid_body->setWorldTransform(transform);
        // m_bullet_transform->setRotation(btQuaternion(t_rot));
    }

    void RigidBody::setLinearVelocity(const SVector3& t_velocity)
    {
        m_rigid_body->setLinearVelocity(btVector3(t_velocity));
    }

    void RigidBody::setAngularVelocity(const SVector3& t_velocity)
    {
        m_rigid_body->setAngularVelocity(t_velocity);
    }

    btRigidBody* RigidBody::getBtRigidBody() const
    {
        return m_rigid_body;
    }

    float RigidBody::getMass() const
    {
        return 0.0f;
    }

    bool RigidBody::isTrigger() const
    {
        return m_trigger;
    }

    bool RigidBody::isStatic() const
    {
        return m_static;
    }

    bool RigidBody::isKinematic() const
    {
        return m_kinematic;
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