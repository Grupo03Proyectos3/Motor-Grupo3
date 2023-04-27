#include "ScriptFactory.h"
namespace Flamingo
{
    ScriptFactory::ScriptFactory()
    {
    }

    Component* ScriptFactory::createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args)
    {
        try
        {
            std::string script = ScriptManager::instance()->getScriptName(args.at("t_scriptName"));

            ScriptManager::instance()->deleteOtherScript(script, gO);

            auto c = Manager::instance()->addScript<>(gO, ScriptManager::instance()->getScript(script), script);

            return c;
        }
        catch (...)
        {
            std::cerr << "[ERROR ScriptFactory Factory]: Key not found" << '\n';
            exit(1);
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