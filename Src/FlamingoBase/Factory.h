#pragma once
#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "ECS/Component.h"
#include "ECS/ManagerFunctions.h"
#include "ECS/GameObject.h"
#include "ECS/Manager.h"
#include <map>
#include <string>
#include <vector>

/*
 * Clase base para las diferentes factorías de componentes que tendremos en el proyecto.
 * Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecución
 * 
 */
namespace Flamingo
{
    class Factory
    {
      public:
        Factory() = default;
        virtual ~Factory();

          /**
         * @brief Crea el component y comprueba que los datos que se pasan en este sean los 
         * correctos
         *         * @param[in] GameObject* gO gO al que se va a meter la propiedad
         * @param[in] unordered_map<std::string, std::string>& args donde se guardan los valores y el nombre de estos para
         * poder mandarlos en el initValues del dicho componente
         * 
         * @return void
         */
        virtual Flamingo::Component* createComponent(Flamingo::GameObject* gO, const std::unordered_map<std::string, std::string>& args);
    };
} // namespace Flamingo
#endif