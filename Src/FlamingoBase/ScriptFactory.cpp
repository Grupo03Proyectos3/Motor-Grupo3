#include "ScriptFactory.h" 
#include <iostream>

namespace Flamingo
{
    ScriptFactory::ScriptFactory()
    {
    }

    Component* ScriptFactory::createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args)
    {
        try
        {
            std::string scriptN = ScriptManager::instance()->getScriptName(args.at("t_scriptName"));

            auto script = ScriptManager::instance()->addScript(scriptN, gO);
            script->initValues();

            return script;
        }
        catch (...)
        {
            throw std::exception("[ERROR BehaviourScript Factory]: Key not found");
        }
    }
    //
    // void ScriptFactory::deleteOtherScript(int t_scriptIndex, ecs::GameObject* t_gO)
    //{
    //    auto it = t_gO->m_current_comps.begin();
    //
    //    while (it != t_gO->m_current_comps.end())
    //    {
    //        BehaviourScript* other = dynamic_cast<BehaviourScript*>(it->second);
    //
    //        if (other != nullptr && m_scriptsIndex[typeid(other).name()] == t_scriptIndex)
    //        {
    //                ecs::Manager::instance()->removeScript(t_gO, it);
    //                break;
    //        }
    //        else
    //            it++;
    //    }
    //}
} // namespace Flamingo