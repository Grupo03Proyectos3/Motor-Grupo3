#include "GameObject.h"
#include "Manager.h"

ecs::GameObject::GameObject()
    : m_current_comps()
    , m_alive()
    , m_active(true)
    , m_gIds({_grp_GENERAL})
{
    m_current_comps.reserve(ecs::maxComponentId);
}

ecs::GameObject::GameObject(std::vector<ecs::groupId_type> t_gId = {_grp_GENERAL})
    : m_current_comps()
    , m_alive()
    , m_active(true)
    , m_gIds(t_gId)
{
    m_current_comps.reserve(ecs::maxComponentId);
}

ecs::GameObject::~GameObject()
{
    setAlive(false);

    for (auto c : m_current_comps)
        if (c.second != nullptr)
            delete c.second;
}

void ecs::GameObject::setAlive(bool to)
{
    m_alive = to;
}

void ecs::GameObject::setActive(bool to)
{
    m_active = to;
}

std::string ecs::GameObject::getName()
{
    return m_name;
}

void ecs::GameObject::setName(std::string t_name)
{
    m_name = t_name;
}
