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

            if(!script->initValues(args))
                throw std::exception("[ERROR BehaviourScript Factory]: Scripts values not valid");

            return script;
        }
        catch (...)
        {
            throw std::exception("[ERROR BehaviourScript Factory]: Key not found or valid");
        }
    }
  
} // namespace Flamingo