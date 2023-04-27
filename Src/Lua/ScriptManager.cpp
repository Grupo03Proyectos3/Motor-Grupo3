#include "ScriptManager.h"

#include "ECS/Manager.h"
#include "ECS/GameObject.h"

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
        return m_nameScripts[t_n];
    }

    void ScriptManager::addGameScript(std::string t_n, BehaviourScript* t_s)
    {
        if (m_scriptsIndex.count(t_n))
            return;

        m_nameScripts.emplace(t_n, t_s->GetScriptName());
        m_scriptsIndex.insert({t_s->GetScriptName(), m_scriptsIndex.size() + 1});
        m_gameScripts.emplace(t_s->GetScriptName(), t_s);
    }

    BehaviourScript* ScriptManager::addScript(std::string t_n, GameObject* t_gO)
    {
        deleteOtherScript(t_n, t_gO);

        return Manager::instance()->addScript(t_gO, getScript(t_n), t_n);
    }

    void ScriptManager::deleteOtherScript(std::string t_n, GameObject* t_gO)
    {
        // falta codigo defensivo ya que si se pide uno que no exite se la suda y lo crea
        int scriptIndex = m_scriptsIndex[t_n];

        auto it = t_gO->getCurrentComponents().begin();

        while (it != t_gO->getCurrentComponents().end())
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
} // namespace Flamingo