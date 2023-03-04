#include "Transform.h"

Transform::Transform(Ogre::SceneNode* t_node, SVector3 t_position, SQuaternion t_rotation, SVector3 t_scale)
    : m_transform(t_node)
    , m_position(t_position)
    , m_rotation(t_rotation)
    , m_scale(t_scale)
{
}
void Transform::initComponent(){
    m_transform->setPosition(m_position);
    m_transform->setOrientation(m_rotation);
    m_transform->setScale(m_scale);
}

SVector3 Transform::getPosition(){
    return m_position;
}

SQuaternion Transform::getRotation(){
    return m_rotation;
}

SVector3 Transform::getScale(){
    return m_scale;
}

void Transform::setPosition(SVector3 t_pos){
    m_position = t_pos;
    m_transform->setPosition(m_position);
}

void Transform::setRotation(SQuaternion t_rotation) {
    m_rotation = t_rotation;
    m_transform->setOrientation(m_rotation);
}

void Transform::setScale(SVector3 t_scale){
    m_scale = t_scale;
    m_transform->setScale(m_scale);
}

Ogre::SceneNode* Transform::getTransform() {
    return m_transform;
}