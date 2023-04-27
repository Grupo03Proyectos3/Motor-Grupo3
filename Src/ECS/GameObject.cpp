#include "GameObject.h"
#include "Manager.h"
namespace Flamingo
{

    GameObject::GameObject()
        : m_current_comps()
        , m_alive()
        , m_active(true)
        , m_gIds({GROUP_EXAMPLE})
    {
        m_current_comps.reserve(maxComponentId);
    }

    GameObject::GameObject(std::vector<Flamingo::groupId_type> t_gId = {GROUP_EXAMPLE})
        : m_current_comps()
        , m_alive()
        , m_active(true)
        , m_gIds(t_gId)
    {
        m_current_comps.reserve(maxComponentId);
    }

    GameObject::~GameObject()
    {
        for (auto it = m_current_comps.begin(); it != m_current_comps.end(); ++it)
            if (it->second != nullptr)
                delete it->second;

        m_current_comps.clear();
    }

    void GameObject::setAlive(bool to)
    {
        m_alive = to;
    }

    void GameObject::setActive(bool to)
    {
        m_active = to;
    }

    bool GameObject::getAlive()
    {
        return m_alive;
    }

    bool GameObject::getActive()
    {
        return m_active;
    }

    std::string GameObject::getName()
    {
        return m_name;
    }

    void GameObject::setName(std::string t_name)
    {
        m_name = t_name;
    }
} // namespace Flamingo