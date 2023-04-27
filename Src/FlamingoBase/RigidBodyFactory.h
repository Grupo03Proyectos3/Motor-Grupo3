#pragma once
#ifndef __RIGIDBODYFACTORY_H__
#define __RIGIDBODYFACTORY_H__

#include "Factory.h"
/*Clase base para las diferentes factor�as de componentes que tendremos en el proyecto.
 *Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecuci�n
 */
namespace Flamingo
{

    class RigidBodyFactory : public Factory
    {
      public:
        RigidBodyFactory() = default;

        Component* createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;
    };
} // namespace Flamingo
#endif