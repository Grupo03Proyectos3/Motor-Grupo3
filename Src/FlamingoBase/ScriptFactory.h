#pragma once
#ifndef __SCRIPTFACTORY_H__
#define __SCRIPTFACTORY_H__

#include "Factory.h"
#include "Scripting/ScriptManager.h"
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

} // namespace Flamingo
#endif