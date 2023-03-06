#include "Transform.h"
Transform::Transform()
{
}

Transform::Transform(Ogre::SceneNode* t_node, SVector3 t_position, SQuaternion t_rotation, SVector3 t_scale)
    : m_transform(t_node)
    , m_position(t_position)
    , m_rotation(t_rotation)
    , m_scale(t_scale)
{
}

void Transform::setNode(Ogre::SceneNode* t_node)
{
    m_transform = t_node;
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
    m_transform->setPosition(t_pos);
}

void Transform::setRotation(SQuaternion t_rotation)
{
    m_transform->setOrientation(t_rotation);
}

void Transform::setScale(SVector3 t_scale)
{
    m_transform->setScale(t_scale);
}

void Transform::translate(SVector3 t_translate){
    m_transform->translate(t_translate.getX(), t_translate.getY(), t_translate.getZ());
}

Ogre::SceneNode* Transform::getNode()
{
    return m_transform;
}