#pragma once
#ifndef __ANIMATORFACTORY_H__
#define __ANIMATORFACTORY_H__

#include "Factory.h"
#include "Render/RenderSystem.h"
/*Clase base para las diferentes factorías de componentes que tendremos en el proyecto.
 *Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecución
 */
class AnimatorFactory : public Factory
{
  public:
    AnimatorFactory(RenderSystem* t_renderSystem);

   ecs::Component* createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;

   private:
   Ogre::SceneNode* root;
   RenderSystem* m_renderSystem;
};
#endif