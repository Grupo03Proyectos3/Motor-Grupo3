#include "ScriptFactory.h"

ScriptFactory::ScriptFactory()
{
}

ecs::Component* ScriptFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        std::string script = (args.at("t_scriptName"));

        deleteOtherScript(m_scriptsIndex[typeid( m_gameScripts[script]).name()], gO);

        auto c = ecs::Manager::instance()->addScript<>(gO, m_gameScripts[script]->clone());

        //c->initValues();
        ecs::Manager::instance()->addGameObjectToGroups(gO, {ecs::GROUP_SCRIPTING});
        // compsCreated.push_back(c);
        return c;
    }
    catch (...)
    {
        std::cerr << "[ERROR ScriptFactory Factory]: Key not found" << '\n';
        exit(1);
    }
}

void ScriptFactory::deleteOtherScript(int t_scriptIndex, ecs::GameObject* t_gO)
{
    auto it = t_gO->m_current_comps.begin();

    while (it != t_gO->m_current_comps.end())
    {
        BehaviourScript* other = dynamic_cast<BehaviourScript*>(it->second);

        if (other != nullptr && m_scriptsIndex[typeid(other).name()] == t_scriptIndex)
        {
                ecs::Manager::instance()->removeScript(t_gO, it);
                break;
        }
        else
            it++;
    }
}
