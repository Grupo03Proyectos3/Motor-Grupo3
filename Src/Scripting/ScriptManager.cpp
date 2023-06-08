#include "ScriptManager.h"
#include "BehaviourScript.h"
#include "ECS/GameObject.h"
#include "ECS/Manager.h"

namespace Flamingo
{
    ScriptManager::ScriptManager()
    {
    }
    ScriptManager::~ScriptManager()
    {
    }
    BehaviourScript* ScriptManager::getScript(std::string t_n)
    {
        return m_gameScripts[t_n]->clone();
    }

    std::string ScriptManager::getScriptName(std::string t_n)
    {
        if (m_nameScripts.find(t_n) == m_nameScripts.end())
            throw std::exception();

        return m_nameScripts[t_n];
    }

    bool ScriptManager::addGameScript(std::string t_n, BehaviourScript* t_s)
    {
        if (m_scriptsIndex.count(t_n))
            return false;

        m_nameScripts.emplace(t_n, t_s->GetScriptName());
        m_scriptsIndex.insert({t_s->GetScriptName(), m_scriptsIndex.size() + 1});
        m_gameScripts.emplace(t_s->GetScriptName(), t_s);

        return true;
    }

    BehaviourScript* ScriptManager::addScript(std::string t_n, GameObject* t_gO)
    {
        removeScript(t_n, t_gO);

        return Manager::instance()->addScript(t_gO, getScript(t_n), t_n);
    }

    BehaviourScript* ScriptManager::getScript(std::string t_n, GameObject* t_gO)
    {
        BehaviourScript* script;

        for (const auto& c : t_gO->m_current_comps)
        {
            script = dynamic_cast<BehaviourScript*>(c.second);
            if (script != nullptr && script->GetScriptName() == t_n)
            {
                return dynamic_cast<BehaviourScript*>(c.second);
            }
        }

        return nullptr;
    }

    void ScriptManager::removeScript(std::string t_n, GameObject* t_gO)
    {
        // falta codigo defensivo ya que si se pide uno que no exite se la suda y lo crea
        int scriptIndex = m_scriptsIndex[t_n];

        auto it = t_gO->m_current_comps.begin();

        while (it != t_gO->m_current_comps.end())
        {
            BehaviourScript* other = dynamic_cast<BehaviourScript*>(it->second);

            if (other != nullptr && m_scriptsIndex[other->GetScriptName()] == scriptIndex)
            {
                Manager::instance()->removeScript(t_gO, it);
                break;
            }
            else
                it++;
        }
    }

    bool ScriptManager::hasScript(std::string t_n, GameObject* t_gO)
    {
        BehaviourScript* script;

        for (const auto& c : t_gO->m_current_comps)
        {
            script = dynamic_cast<BehaviourScript*>(c.second);
            if (script != nullptr && script->GetScriptName() == t_n)
            {
                return true;
            }
        }

        return false;
    }

    void ScriptManager::startComponents()
    {
        for (auto gO : Manager::instance()->getEntities(GROUP_SCRIPTING))
        {
            if (gO == nullptr)
                continue;

            for (auto c : gO->getCurrentComponents())
            {
                auto s = dynamic_cast<BehaviourScript*>(c.second);
                if (s != nullptr && s->gameObject()->getActive() && s->gameObject()->getAlive())
                {
                    s->start();
                }
            }
        }
    }
    void ScriptManager::deleteScriptsTemplates()
    {
        for (auto it = m_gameScripts.begin(); it != m_gameScripts.end(); it++)
        {
            delete it->second;
            it->second = nullptr;
        }
        m_gameScripts.clear();
    }
} // namespace Flamingo