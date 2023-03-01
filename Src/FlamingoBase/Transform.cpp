#include "Transform.h"

Transform::Transform(SVector3 t_position, SQuaternion t_rotation, SVector3 t_scale){
    m_position = t_position;
    m_rotation = t_rotation;
    m_scale = t_scale;
}
void Transform::initComponent(){  
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
}

void Transform::setRotation(SQuaternion t_rotation)
{
    m_rotation = t_rotation;
}

void Transform::setScale(SVector3 t_scale){
    m_scale = t_scale;
}
