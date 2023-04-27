#pragma once
#ifndef __PLAYERCONTROLLERFACTORY_H__
#define __PLAYERCONTROLLERFACTORY_H__

#include "Factory.h"
/*Clase base para las diferentes factor�as de componentes que tendremos en el proyecto.
 *Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecuci�n
 */
namespace Flamingo
{
    class PlayerControllerFactory : public Factory
    {
      public:
        PlayerControllerFactory() = default;

        Component* createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;
    };
} // namespace Flamingo
#endif