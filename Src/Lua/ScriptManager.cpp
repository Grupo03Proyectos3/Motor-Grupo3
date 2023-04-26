#include "ScriptManager.h"

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

void ScriptManager::deleteOtherScript(std::string t_n, ecs::GameObject* t_gO)
{
    // falta codigo defensivo ya que si se pide uno que no exite se la suda y lo crea
    int scriptIndex = m_scriptsIndex[t_n];

    auto it = t_gO->m_current_comps.begin();

    while (it != t_gO->m_current_comps.end())
    {
        BehaviourScript* other = dynamic_cast<BehaviourScript*>(it->second);

        if (other != nullptr && m_scriptsIndex[other->GetScriptName()] == scriptIndex)
        {
            ecs::Manager::instance()->removeScript(t_gO, it);
            break;
        }
        else
            it++;
    }
}
