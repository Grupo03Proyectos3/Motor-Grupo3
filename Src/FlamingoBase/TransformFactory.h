#pragma once
#ifndef __TRANSFORMFACTORY_H__
#define __TRANSFORMFACTORY_H__

#include "Factory.h"
#include "Transform.h"
/*Clase base para las diferentes factorías de componentes que tendremos en el proyecto.
 *Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecución
 */
class TransformFactory : public Factory
{
  public:
    TransformFactory() = default;

   ecs::Component* createComponent(const std::map<std::string, std::string>& args) override;

   private:
   std::vector<ecs::Component*> compsCreated;
};
#endif