#pragma once
#ifndef __SCRIPTFACTORY_H__
#define __SCRIPTFACTORY_H__

#include "Factory.h"
#include "Lua/BehaviourScript.h"
#include <map>
/*Clase base para las diferentes factorías de componentes que tendremos en el proyecto.
 *Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecución
 */
class ScriptFactory : public Factory
{
  public:
    ScriptFactory();

   ecs::Component* createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;

   void addGameScript(BehaviourScript b);

 
   private:
   std::map<std::string, BehaviourScript> m_gameScripts;
};

#endif