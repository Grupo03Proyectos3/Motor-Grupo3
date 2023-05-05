#pragma once
#ifndef __CAMERAFACTORY_H__
#define __CAMERAFACTORY_H__

#include "Factory.h"

namespace Flamingo
{
    class RenderSystem;
}
namespace Ogre
{
    class SceneNode;
}
/*Clase base para las diferentes factorías de componentes que tendremos en el proyecto.
 *Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecución
 */
namespace Flamingo
{
    class CameraFactory : public Factory
    {
      public:
        CameraFactory(Flamingo::RenderSystem* t_renderSystem);

        Flamingo::Component* createComponent(Flamingo::GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;

      private:
        RenderSystem* m_renderSystem;
    };
} // namespace Flamingo
#endif