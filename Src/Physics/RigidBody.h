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

    struct RigidBody : public Component
    {
      public:
        __SYSTEM_ID_DECL__(_cmp_RIGID_BODY)

        RigidBody();
        virtual ~RigidBody();
        FLAMINGOEXPORT_API virtual void initValues(float t_mass, bool t_trigger, bool t_static);
        FLAMINGOEXPORT_API virtual void initComponent();

        FLAMINGOEXPORT_API void setMass(const float& t_mass);
        FLAMINGOEXPORT_API void setScale(const SVector3 t_scale);
        FLAMINGOEXPORT_API void setTrigger(bool t_trigger);
        FLAMINGOEXPORT_API void setStatic(bool t_static);
        FLAMINGOEXPORT_API void setKinematic(bool t_kinematic);
        FLAMINGOEXPORT_API void setPosition(SVector3 t_pos);
        FLAMINGOEXPORT_API void setRotation(SQuaternion t_rot);
        FLAMINGOEXPORT_API void setLinearVelocity(const SVector3& t_velocity);
        FLAMINGOEXPORT_API void setAngularVelocity(const SVector3& t_velocity);

        btRigidBody* getBtRigidBody() const;
        FLAMINGOEXPORT_API float getMass() const;
        FLAMINGOEXPORT_API bool isTrigger() const;
        FLAMINGOEXPORT_API bool isStatic() const;
        FLAMINGOEXPORT_API bool isKinematic() const;
        FLAMINGOEXPORT_API SVector3 getPosition() const;
        FLAMINGOEXPORT_API SQuaternion getRotation() const;
        FLAMINGOEXPORT_API SVector3 getLinearVelocity() const;
        FLAMINGOEXPORT_API SVector3 getAngularVelocity() const;

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
