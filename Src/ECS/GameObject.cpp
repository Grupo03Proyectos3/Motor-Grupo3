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

    GameObject::GameObject(std::vector<Flamingo::groupId_type> t_gId)
        : m_current_comps()
        , m_alive()
        , m_active(true)
        , m_gIds(t_gId)
    {
        m_current_comps.reserve(maxComponentId);
    }

    GameObject::~GameObject()
    {
        if (m_current_comps.size() > 0)
        {
            for (auto it = m_current_comps.begin(); it != m_current_comps.end(); ++it)
                if (it->second != nullptr)
                    delete it->second;

            m_current_comps.clear();
        }
    }

    void GameObject::setAlive(bool to)
    {
        m_alive = to;
    }

    void GameObject::setActive(bool to)
    {
        m_active = to;

        Message m;
        m.id = MSG_GAME_OBJECT_ACTIVE_CHANGED;
        m.gameObejctChangeActive.object_changed = this;
        m.gameObejctChangeActive.mode = to;
        auto mngr = Manager::instance();
        mngr->send(m);
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

    std::unordered_map<std::string, Component*> GameObject::getCurrentComponents() {
        return m_current_comps;
    }
} // namespace Flamingo