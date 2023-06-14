#include "Manager.h"

namespace Flamingo
{
    Manager* Manager::m_instance = nullptr;

    Manager::Manager()
    {
        init();
    };

    Manager::~Manager()
    {
        freeAllGameObjects();

        //Sistems are deleted in reverse order was created
        for (auto i = maxSystemId - 1; i >= 0; i--)
            if (m_systems[i] != nullptr)
            {
                delete m_systems[i];
                m_systems[i] = nullptr;
            }
    };

    void Manager::freeAllGameObjects()
    {
        std::vector<GameObject*> toDestroy;

        for (auto& ents : m_ents_by_group)
        {
            for (auto i = 0; i < ents.size(); i++)
            {
                if (gameObjectMarked(toDestroy, ents[i]))
                {
                    ents[i] = nullptr;
                }
                else if (ents[i] != nullptr)
                {
                    toDestroy.push_back(ents[i]);
                    ents[i] = nullptr;
                }
            }
        }

        for (auto i = 0; i < toDestroy.size(); i++)
            delete toDestroy[i];
    };

    void Manager::init()
    {
        m_handlers = std::array<GameObject*, maxHandlerId>();
        m_ents_by_group = std::array<std::vector<GameObject*>, maxGroupId>();
        m_systems = std::array<System*, maxSystemId>();

        m_msgs = std::vector<Message>();
        m_msgs_aux = std::vector<Message>();
    };

    void Manager::initComponents()
    {
        for (auto& ent : m_ents_by_group[GROUP_ALL])
        {
            for (auto& comp : ent->m_current_comps)
            {
                comp.second->initComponent();
            }
        }
    };

    GameObject* Manager::addGameObject(std::vector<groupId_type> t_vect_gId)
    {
        auto e = new GameObject(t_vect_gId);
        e->m_alive = true;

        for (auto grp : t_vect_gId)
        {
            // create and initialise the entity
            m_ents_by_group[grp].push_back(e);
        }
        m_ents_by_group[GROUP_ALL].push_back(e);

        return e;
    }

    void Manager::addGameObjectToGroups(GameObject* t_e, std::vector<groupId_type> t_vect_gId)
    {
        for (auto grp : t_vect_gId)
        {
            if (std::find(m_ents_by_group[grp].begin(), m_ents_by_group[grp].end(), t_e) == m_ents_by_group[grp].end())
            {
                m_ents_by_group[grp].push_back(t_e);
            }
        }
    }

    void Manager::setAlive(GameObject* t_e, bool t_alive){
        t_e->m_alive = t_alive;
    }

    bool Manager::isAlive(GameObject* t_e)
    {
        return t_e->m_alive;
    }

    void Manager::removeScript(GameObject* t_e, std::unordered_map<std::string, Component*>::iterator t_scriptIndex){
        delete t_scriptIndex->second;
        t_scriptIndex->second = nullptr;
        t_e->m_current_comps.erase(t_scriptIndex);
    }

    std::vector<groupId_type> Manager::groupId(GameObject* t_e){
        return t_e->m_gIds;
    }

    const std::vector<GameObject*>& Manager::getEntities(groupId_type t_gId)
    {
        return m_ents_by_group[t_gId];
    }

    void Manager::setHandler(handlerId_type t_hId, GameObject* t_e){
        assert(t_hId < maxHandlerId);
        m_handlers[t_hId] = t_e;
    }

    GameObject* Manager::getHandler(handlerId_type t_hId)
    {
        assert(t_hId < maxHandlerId);
        return m_handlers[t_hId];
    }

    std::array<System*, maxSystemId> Manager::getSystems()
    {
        return m_systems;
    }

    void Manager::reajustGroups()
    {
        reajustG = true;
    }

    void Manager::send(const Message& t_m, bool t_delay)
    {
        if (!t_delay)
        {
            for (System* s : m_systems)
            {
                if (s != nullptr)
                    s->recieve(t_m);
            }
        }
        else
        {
            m_msgs.emplace_back(t_m);
        }
    }

    void Manager::flushMessages()
    {
        // we traverse until msgs_.size(), so if new message
        // we added we don't send them now. If you wish to send
        // them as will you should write this loop in a different way
        // and maybe using std::list would be better.
        //
        auto size = m_msgs.size();
        for (auto i = 0u; i < size; i++)
        {
            auto& m = m_msgs[i];
            for (System* s : m_systems)
            {
                if (s != nullptr)
                    s->recieve(m);
            }
        }

        // delete all message that we have sent. This might be expensive
        // since it has to shift all remaining elements to the left. A better
        // solution would be to keep two vectors 'v1' and 'v2', when sending a
        // message we always add it to 'v1' and in flush we swap them and send
        // all messages in v2. After flush we simply clear v2
        //
        m_msgs.erase(m_msgs.begin(), m_msgs.begin() + size);
    }

    void Manager::refresh()
    {
        std::vector<GameObject*> toDestroy;

        for (auto& ents : m_ents_by_group)
        {
            for (auto i = 0; i < ents.size(); i++)
            {
                if (gameObjectMarked(toDestroy, ents[i]))
                    ents[i] = nullptr;

                else if (ents[i] != nullptr && ents[i]->m_alive == false)
                {
                    toDestroy.push_back(ents[i]);
                    ents[i] = nullptr;
                }
            }
        }

        for (auto i = 0; i < toDestroy.size(); i++)
            delete toDestroy[i];

        if (reajustG)
        {
            reajustG = false;
            reajustSizeGroups();
        }
    }

     bool Manager::gameObjectMarked(const std::vector<GameObject*>& v, GameObject* gO)
     {
        for (auto i = 0; i < v.size(); i++)
        {
            if (v[i] == gO)
                return true;
        }

        return false;
     }

     Manager* Manager::instance()
     {
        if (m_instance == nullptr)
        {
            m_instance = new Manager();
        }
        return m_instance;
     }

     void Manager::close()
     {
        if (m_instance != nullptr)
        {
            delete m_instance;
        }
     }

     void Manager::reajustSizeGroups()
     {
        for (auto j = 0; j < m_ents_by_group.size(); j++)
        {
            auto i = m_ents_by_group[j].begin();
            while (i != m_ents_by_group[j].end())
            {
                if (*i == nullptr)
                    i = m_ents_by_group[j].erase(i);
                else
                    ++i;
            }
        }
     }
}
