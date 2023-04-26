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

// std::string ScriptManager::getScriptType(const BehaviourScript* t_s)
//{
//     std::string name = typeid(t_s).name();
//     auto p1 = name.find(' ');
//     name = name.substr(p1 + 1);
//     return name.substr(0, name.find(' '));
// }

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
