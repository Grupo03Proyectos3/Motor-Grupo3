#pragma once
#ifndef __RIGIDBODYFACTORY_H__
#define __RIGIDBODYFACTORY_H__

#include "Factory.h"
/*Clase base para las diferentes factorías de componentes que tendremos en el proyecto.
 *Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecución
 */
class RigidBodyFactory : public Factory
{
  public:
    RigidBodyFactory() = default;

   ecs::Component* createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;
};
#endif