#include "Component.h"

Flamingo::Component::Component()
    : m_ent()
{
}

void Flamingo::Component::setContext(GameObject* t_ent, Manager* t_mngr)
{
    m_ent = t_ent;
    m_mngr = t_mngr;
}

Flamingo::GameObject* Flamingo::Component::gameObject()
{
    return m_ent;
}
