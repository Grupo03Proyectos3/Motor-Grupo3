#pragma once
#ifndef __LIGHTFACTORY_H__
#define __LIGHTFACTORY_H__

#include "Factory.h"
#include "Render/RenderSystem.h"
/*Clase base para las diferentes factor�as de componentes que tendremos en el proyecto.
 *Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecuci�n
 */
class LightFactory : public Factory
{
  public:
    LightFactory();

   ecs::Component* createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;

   private:
   RenderSystem* m_render;
    
    
};
#endif