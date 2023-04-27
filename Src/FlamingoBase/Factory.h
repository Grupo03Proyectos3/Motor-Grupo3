#pragma once
#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "ECS/Component.h"
#include "ECS/Components.h"
#include "ECS/GameObject.h"
#include <map>
#include <string>
#include <vector>

/*Clase base para las diferentes factorías de componentes que tendremos en el proyecto.
 *Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecución
 */
namespace Flamingo
{
    class Factory
    {
      public:
        Factory() = default;
        ~Factory();

        virtual Flamingo::Component* createComponent(Flamingo::GameObject* gO, const std::unordered_map<std::string, std::string>& args);

        void deleteComponents();

      protected:
        // std::vector<ecs::Component*> compsCreated;
    };
} // namespace Flamingo
#endif