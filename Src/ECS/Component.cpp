#include "Component.h"

ecs::Component::Component()
    : m_ent()
    //,       //
    //m_mngr() //
{
}

ecs::Component::~Component()
{
}

void ecs::Component::setContext(GameObject* t_ent, Manager* t_mngr)
{
    m_ent = t_ent;
    m_mngr = t_mngr;
}

void ecs::Component::initComponent()
{
}

ecs::GameObject* ecs::Component::gameObject()
{
    return m_ent;
}
