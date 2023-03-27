#pragma once
#ifndef __TRANSFORMFACTORY_H__
#define __TRANSFORMFACTORY_H__

#include "Factory.h"
/*Clase base para las diferentes factor�as de componentes que tendremos en el proyecto.
 *Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecuci�n
 */
class TransformFactory : public Factory
{
  public:
    TransformFactory() = default;

   ecs::Component* createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;
};
#endif