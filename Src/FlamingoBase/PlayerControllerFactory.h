#pragma once
#ifndef __PLAYERCONTROLLERFACTORY_H__
#define __PLAYERCONTROLLERFACTORY_H__

#include "Factory.h"
/*Clase base para las diferentes factorías de componentes que tendremos en el proyecto.
 *Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecución
 */
class PlayerControllerFactory : public Factory
{
  public:
    PlayerControllerFactory() = default;

   ecs::Component* createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;
};
#endif