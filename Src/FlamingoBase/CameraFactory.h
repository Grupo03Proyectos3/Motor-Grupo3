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
class CameraFactory : public Factory
{
  public:
    CameraFactory(Flamingo::RenderSystem* t_renderSystem);

   ecs::Component* createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;

   private:
   Ogre::SceneNode* root;
   Flamingo::RenderSystem* m_renderSystem;
};
#endif