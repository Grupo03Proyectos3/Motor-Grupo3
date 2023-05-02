#pragma once
#ifndef __RIGID_BODY_H__
#define __RIGID_BODY_H__

#include "ECS/Component.h"
#include "ECS/GameObject.h"
#include "ECS/Manager.h"

class btVector3;
class btQuaternion;
class btTransform;
class btRigidBody;
class btGhostObject;
class btCollisionShape;
class btCollisionObject;


namespace Flamingo{

    class SVector3;
    class SQuaternion;

    struct FLAMINGOEXPORT_API RigidBody : public Component
    {
      public:
        __SYSTEM_ID_DECL__(_cmp_RIGID_BODY)

        RigidBody();
        virtual ~RigidBody();
        virtual void initValues(float t_mass, bool t_trigger, bool t_static);
        virtual void initComponent();

        void setMass(const float& t_mass);
        void setScale(const SVector3 t_scale);
        void setTrigger(bool t_trigger);
        void setStatic(bool t_static);
        void setKinematic(bool t_kinematic);
        void setPosition(SVector3 t_pos);
        void setRotation(SQuaternion t_rot);
        void setLinearVelocity(const SVector3& t_velocity);
        void setAngularVelocity(const SVector3& t_velocity);

        btRigidBody* getBtRigidBody() const;
        float getMass() const;
        bool isTrigger() const;
        bool isStatic() const;
        bool isKinematic() const;
        SVector3 getPosition() const;
        SQuaternion getRotation() const;
        SVector3 getLinearVelocity() const;
        SVector3 getAngularVelocity() const;

      private:
        btRigidBody* m_rigid_body = nullptr;       // rigidbody de Bullet
        btTransform* m_bullet_transform = nullptr; // transform de bullet
        btCollisionShape* m_shape = nullptr;

        float m_mass = 1.0f;
        bool m_trigger = false;
        bool m_static = false;

        // la velocidad va en el btRigidBody

        bool m_kinematic = false;
    };
} // namespace Flamingo
#endif
