#include "Component.h"

Flamingo::Component::Component()
    : m_ent()
    //,       //
    //m_mngr() //
{
}

Flamingo::Component::~Component()
{
}

void Flamingo::Component::setContext(GameObject* t_ent, Manager* t_mngr)
{
    m_ent = t_ent;
    m_mngr = t_mngr;
}

void Flamingo::Component::initComponent()
{
}

Flamingo::GameObject* Flamingo::Component::gameObject()
{
    return m_ent;
}
