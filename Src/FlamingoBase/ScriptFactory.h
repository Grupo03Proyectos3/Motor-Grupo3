#pragma once
#ifndef __SCRIPTFACTORY_H__
#define __SCRIPTFACTORY_H__

#include "Factory.h"
#include "Lua/ScriptManager.h"
#include <map>
/*Factoria para crear todos los scripts del proyecto.
 *Factoria que genera script que hereden de Behaviour script mediante el Manager y el ScriptManager
 * Para añadir tipos de scripts:
 *   <PunteroAInstanciaDeEstaClase>->addGameScript("NombreRelacionado", new ScriptHeredaBehaviourScript());
 */
namespace Flamingo
{
    class ScriptFactory : public Factory
    {
      public:
        ScriptFactory();

        Component* createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;

      private:
        const std::string m_baseNameScript = "struct ";
    };

    /*Para realizar pruebas:
    *   auto sF = new ScriptFactory();
            ScriptManager::instance()->addGameScript("PruebaScript", new PruebaScript());
            ecs::GameObject* g = m_mngr->addGameObject();
            ecs::AddComponent<Transform>(g);
            ecs::AddComponent<BehaviourScript>(g);
            std::unordered_map<std::string, std::string> m;
            m.insert({"t_scriptName", "PruebaScript"});
            auto v = sF->createComponent(g, m);
    */
} // namespace Flamingo
#endif