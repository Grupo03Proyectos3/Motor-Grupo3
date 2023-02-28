#include "GameObject.h"

GameObject::GameObject()
    : name()
    , position()
    , rotation()
    , scale()
    , m_active(true)
{
}

GameObject::GameObject(ecs::Manager* t_mgr)
    : name()
    , position()
    , rotation()
    , scale()
    , m_active(true)
{
    m_manager = t_mgr;
    m_entity = m_manager->addEntity();
}
GameObject::GameObject(ecs::Manager* t_mgr, SVector3 t_position)
    : name("")
    , position(t_position)
    , rotation()
    , scale()
    , m_active(true)
{
    m_manager = t_mgr;
    m_entity = m_manager->addEntity();
}
GameObject::GameObject(ecs::Manager* t_mgr, SVector3 t_position, SQuaternion t_rotation)
    : name("")
    , position(t_position)
    , rotation(t_rotation)
    , scale()
    , m_active(true)
{
    m_manager = t_mgr;
    m_entity = m_manager->addEntity();
}
GameObject::GameObject(ecs::Manager* t_mgr, SVector3 t_position, SQuaternion t_rotation, SVector3 t_scale)
    : name("")
    , position(t_position)
    , rotation(t_rotation)
    , scale(t_scale)
    , m_active(true)
{
    m_manager = t_mgr;
    m_entity = m_manager->addEntity();
}
GameObject::GameObject(ecs::Manager* t_mgr, std::string t_name, SVector3 t_position, SQuaternion t_rotation, SVector3 t_scale)
    : name(t_name)
    , position(t_position)
    , rotation(t_rotation)
    , scale(t_scale)
    , m_active(true)
{
    m_manager = t_mgr;
    m_entity = m_manager->addEntity();
}
GameObject::GameObject(ecs::Manager* t_mgr, ecs::groupId t_group, std::string t_name, SVector3 t_position, SQuaternion t_rotation, SVector3 t_scale)
    : name(t_name)
    , position(t_position)
    , rotation(t_rotation)
    , scale(t_scale)
    , m_active(true)
{
    m_manager = t_mgr;
    m_entity = m_manager->addEntity(t_group);
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

ecs::Manager* GameObject::m_manager;


void GameObject::setManager(ecs::Manager* t_manager)
{
    m_manager = t_manager;
}
