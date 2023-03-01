#include "GameObject.h"
#include "Render.h"

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
    m_transform=addComponent<Transform>(t_position, t_rotation, t_scale);
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
    
    return m_transform->getPosition();
}

SQuaternion GameObject::getRotation(){
    return m_transform->getRotation();
}

SVector3 GameObject::getScale(){
    return m_transform->getScale();
}

void GameObject::setPosition(SVector3 t_pos){
    m_transform->setPosition(t_pos);
    auto rndr = getComponent<Render>();
    if (rndr != nullptr) rndr->setPosition(t_pos);
}

void GameObject::setRotation(SQuaternion t_rotation){
    m_transform->setRotation(t_rotation);
    auto rndr = getComponent<Render>();
    if (rndr != nullptr)rndr->setRotation(t_rotation);
}

void GameObject::setScale(SVector3 t_scale){
    m_transform->setScale(t_scale);
    auto rndr = getComponent<Render>();
    if (rndr != nullptr)rndr->setScale(t_scale);
}

void GameObject::setManager(ecs::Manager* t_manager){
    m_manager = t_manager;
}
