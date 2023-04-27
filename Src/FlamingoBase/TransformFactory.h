#pragma once
#ifndef __TRANSFORMFACTORY_H__
#define __TRANSFORMFACTORY_H__

#include "Factory.h"
/*Clase base para las diferentes factorías de componentes que tendremos en el proyecto.
 *Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecución
 */
namespace Flamingo
{
    class TransformFactory : public Factory
    {
      public:
        TransformFactory() = default;

        Component* createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;
    };
} // namespace Flamingo
#endif