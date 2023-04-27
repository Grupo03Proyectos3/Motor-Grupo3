#pragma once
#ifndef __UIELEMENTFACTORY_H__
#define __UIELEMENTFACTORY_H__

#include "Factory.h"
/*Clase base para las diferentes factorías de componentes que tendremos en el proyecto.
 *Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecución
 */
namespace Flamingo
{
    class UIElementFactory : public Factory
    {
      public:
        UIElementFactory() = default;

        Component* createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;
    };
} // namespace Flamingo
#endif