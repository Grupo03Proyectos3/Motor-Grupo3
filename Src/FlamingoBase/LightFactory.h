#pragma once
#ifndef __LIGHTFACTORY_H__
#define __LIGHTFACTORY_H__

#include "Factory.h"
#include "Render/RenderSystem.h"
/*Clase base para las diferentes factorías de componentes que tendremos en el proyecto.
 *Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecución
 */
namespace Flamingo
{
    class LightFactory : public Factory
    {
      public:
        LightFactory(Flamingo::RenderSystem* t_renderSystem);

        Component* createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;

      private:
        Flamingo::RenderSystem* m_renderSystem;
    };
} // namespace Flamingo
#endif