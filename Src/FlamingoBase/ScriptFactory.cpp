#include "ScriptFactory.h"

ScriptFactory::ScriptFactory()
{
}

ecs::Component* ScriptFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        std::string script = (args.at("t_scriptName"));

        /*
         * 1-Obligar a que en un archivo del juego se incluya en un map del motor todos los scripts
         * 2-Mediante el map obtenemos la referencia base del script que hereda de BehaviourScript 
         */
        auto t = m_gameScripts.at(script);
        auto c = ecs::AddComponent<decltype(t)>(gO);
        c->initValues();
        c->initComponent();

        ecs::Manager::instance()->addGameObjectToGroups(gO, {ecs::GROUP_SCRIPTING});
        // compsCreated.push_back(c);
        return c;
    }
    catch (const std::exception&)
    {
        throw new std::exception("Invalids or incompletes params");
    }
}

void ScriptFactory::addGameScript(BehaviourScript b)
{
    m_gameScripts.emplace((std::string) typeid(b).name(), b);
}
