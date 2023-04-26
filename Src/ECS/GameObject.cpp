#include "GameObject.h"
#include "Manager.h"

ecs::GameObject::GameObject()
    : m_current_comps()
    , m_alive()
    , m_active(true)
    , m_gIds({GROUP_EXAMPLE})
{
    m_current_comps.reserve(ecs::maxComponentId);
}

ecs::GameObject::GameObject(std::vector<ecs::groupId_type> t_gId = {GROUP_EXAMPLE})
    : m_current_comps()
    , m_alive()
    , m_active(true)
    , m_gIds(t_gId)
{
    m_current_comps.reserve(ecs::maxComponentId);
}

ecs::GameObject::~GameObject()
{
    for (auto it = m_current_comps.begin(); it != m_current_comps.end(); ++it)
        if (it->second != nullptr) 
            delete it->second;

    m_current_comps.clear();
}

void ecs::GameObject::setAlive(bool to)
{
    m_alive = to;
}

void ecs::GameObject::setActive(bool to)
{
    m_active = to;
}

bool ecs::GameObject::getAlive()
{
    return m_alive;
}

bool ecs::GameObject::getActive()
{
    return m_active;
}

std::string ecs::GameObject::getName()
{
    return m_name;
}

void ecs::GameObject::setName(std::string t_name)
{
    m_name = t_name;
}
