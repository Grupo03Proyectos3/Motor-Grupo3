#include "Transform.h"
#include "ECS/Manager.h"
#include "FlamingoUtils/SVector3.h"
#include "Render/RenderSystem.h"
#include <OgreSceneNode.h>
namespace Flamingo
{
    Transform::Transform()
    {
    }

    void Transform::initValues(SVector3 t_position, SQuaternion t_rotation, SVector3 t_scale)
    {
        m_position = t_position;
        m_rotation = t_rotation;
        m_scale = t_scale;
    }

    void Transform::initComponent()
    {
        setPosition(m_position);
        setRotation(m_rotation);
        setScale(m_scale);
    }

    SVector3 Transform::getPosition()
    {
        return m_position;
    }

    SQuaternion Transform::getRotation()
    {
        return m_rotation;
    }

    SVector3 Transform::getScale()
    {
        return m_scale;
    }

    void Transform::setPosition(SVector3 t_pos)
    {
        m_position = t_pos;
        Message m;
        m.id = MSG_TRANSFORM_MOVE;
        m.entity_affected = m_ent;
        // m.v = &m_position;
        m.vector.x = m_position.getX();
        m.vector.y = m_position.getY();
        m.vector.z = m_position.getZ();
        m_mngr->send(m);
    }

    void Transform::setRotation(SQuaternion t_rotation, STransformSpace t_trs)
    {
        m_rotation = t_rotation;
        Message m;
        m.id = MSG_TRANSFORM_ROTATE;
        m.entity_affected = m_ent;
        m.quaternion.x = m_rotation.getX();
        m.quaternion.y = m_rotation.getY();
        m.quaternion.z = m_rotation.getZ();
        m.quaternion.w = m_rotation.getW();
        m.tr_space = t_trs;
        m_mngr->send(m);
    }

    void Transform::setPositionPerPhysics(SVector3 t_pos)
    {
        m_position = t_pos;
        Message m;
        m.id = MSG_TRANSFORM_MOVE;
        m.entity_affected = m_ent;
        // m.v = &m_position;
        m.vector.x = m_position.getX();
        m.vector.y = m_position.getY();
        m.vector.z = m_position.getZ();
        m_mngr->send(m);

        m_mngr->getSystem<Flamingo::RenderSystem>()->recieve(m);
    }

    void Transform::setRotationPerPhysics(SQuaternion t_rotation)
    {
        m_rotation = t_rotation;
        Message m;
        m.id = MSG_TRANSFORM_ROTATE;
        m.entity_affected = m_ent;
        m.quaternion.x = m_rotation.getX();
        m.quaternion.y = m_rotation.getY();
        m.quaternion.z = m_rotation.getZ();
        m.quaternion.w = m_rotation.getW();
        // m.v = &m_scale;
        m_mngr->getSystem<Flamingo::RenderSystem>()->recieve(m);
    }

    void Transform::setScale(SVector3 t_scale)
    {
        m_scale = t_scale;
        Message m;
        m.id = MSG_TRANSFORM_SCALING;
        m.entity_affected = m_ent;
        m.vector.x = m_scale.getX();
        m.vector.y = m_scale.getY();
        m.vector.z = m_scale.getZ();
        // m.v = &m_scale;
        m_mngr->send(m);
    }

    void Transform::translate(SVector3 distance, STransformSpace t_trs)
    {
        m_position += distance;
        Message m;
        m.id = MSG_TRANSFORM_TRANSLATE;
        m.entity_affected = m_ent;
        m.vector.x = distance.getX();
        m.vector.y = distance.getY();
        m.vector.z = distance.getZ();
        m.tr_space = t_trs;
        m_mngr->send(m);
    }
} // namespace Flamingo