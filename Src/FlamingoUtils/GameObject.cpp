#include "GameObject.h"
#include "Transform.h"

GameObject::GameObject(ecs::Manager* t_mgr, SVector3 t_position, SQuaternion t_rotation, SVector3 t_scale)
    : name("")
    , m_active(true)
{
    m_manager = t_mgr;
    m_entity = m_manager->addEntity();
    addComponent<Transform>(t_position, t_rotation, t_scale);
}

GameObject::GameObject(ecs::Manager* t_mgr, std::string t_name, SVector3 t_position, SQuaternion t_rotation, SVector3 t_scale)
    : name(t_name)
    , m_active(true)
{
    m_manager = t_mgr;
    m_entity = m_manager->addEntity();
    addComponent<Transform>(t_position, t_rotation, t_scale);
}

GameObject::GameObject(ecs::Manager* t_mgr, ecs::groupId t_group, std::string t_name, SVector3 t_position, SQuaternion t_rotation, SVector3 t_scale)
    : name(t_name)
    , m_active(true)
{
    m_manager = t_mgr;
    m_entity = m_manager->addEntity(t_group);
    addComponent<Transform>(t_position, t_rotation, t_scale);
}

GameObject::~GameObject()
{
    m_manager->setAlive(m_entity, false);
    //no se si hay que borrar la entidad aqui o se encarga el manager, diría que lo segundo
    m_entity = nullptr;
}

bool GameObject::isAlive()
{
    return m_manager->isAlive(m_entity);
}

bool GameObject::isActive()
{
    return m_active;
}

void GameObject::setAlive(bool to)
{
   m_manager->setAlive(m_entity, to);
}

void GameObject::setActive(bool to)
{
    m_active = to;
}

GameObject::operator Ogre::String() const
{
    return Ogre::String(name);

}

ecs::Manager* GameObject::m_manager;


SVector3 GameObject::getPosition(){
    
    return getComponent<Transform>()->getPosition();
}

SQuaternion GameObject::getRotation(){
    return getComponent<Transform>()->getRotation();
}

SVector3 GameObject::getScale(){
    return getComponent<Transform>()->getScale();
}

void GameObject::setManager(ecs::Manager* t_manager){
    m_manager = t_manager;
}
