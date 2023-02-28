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

/// DEFINICIONES DE LOS MÉTODOS INLINE: SE HAN MOVIDO AL .H
//template <typename T>
//void GameObject::addComponent(T t_component)
//{
//    return m_manager->addComponent<t_component>(m_entity);
//}
//
//template <typename T>
//void GameObject::removeComponent(T t_component)
//{
//    return m_manager->removeComponent<t_component>(m_entity);
//}
//
//template <typename T>
//T* GameObject::getComponent(T t_component)
//{
//    return m_manager->getComponent<t_component>(m_entity);
//}
//
//template <typename T>
//bool GameObject::hasComponent(T t_component)
//{
//    return m_manager->hasComponent<t_component>(m_entity);
//}


void GameObject::setManager(ecs::Manager* t_manager)
{
    m_manager = t_manager;
}


SVector3::SVector3()
    : m_x(0)
    , m_y(0)
    , m_z(0)
{
    m_vector3 = Ogre::Vector3(m_x, m_y, m_z);
}

SVector3::SVector3(double t_x, double t_y, double t_z)
    : m_x(t_x)
    , m_y(t_y)
    , m_z(t_z)
{
    m_vector3 = Ogre::Vector3(m_x, m_y, m_z);
}

void SVector3::setVector3(double t_x, double t_y, double t_z)
{
    m_x = t_x;
    m_y = t_y;
    m_z = t_z;
    m_vector3 = Ogre::Vector3(m_x, m_y, m_z);
}

double SVector3::getX()
{
    return m_x;
}

double SVector3::getY()
{
    return m_y;
}

double SVector3::getZ()
{
    return m_z;
}

SQuaternion::SQuaternion()
    : m_x(0)
    , m_y(0)
    , m_z(0)
    , m_w(1)
{
    m_quaternion = Ogre::Quaternion(m_x, m_y, m_z, m_w);
}

SQuaternion::SQuaternion(double t_x, double t_y, double t_z, double t_w)
    : m_x(t_x)
    , m_y(t_y)
    , m_z(t_z)
    , m_w(t_w)
{
    m_quaternion = Ogre::Quaternion(m_x, m_y, m_z, m_w);
}

void SQuaternion::setQuaternion(double t_x, double t_y, double t_z, double t_w)
{
    m_x = t_x;
    m_y = t_y;
    m_z = t_z;
    m_w = t_w;

    m_quaternion = Ogre::Quaternion(m_x, m_y, m_z, m_w);
}

double SQuaternion::getX()
{
    return m_x;
}

double SQuaternion::getY()
{
    return m_y;
}

double SQuaternion::getZ()
{
    return m_z;
}

double SQuaternion::getW()
{
    return m_w;
}
