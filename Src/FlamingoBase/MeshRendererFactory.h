#pragma once
#ifndef __MESHRENDERERFACTORY_H__
#define __MESHRENDERERFACTORY_H__

#include "Factory.h"
#include "Render/RenderSystem.h"

/*Clase base para las diferentes factorías de componentes que tendremos en el proyecto.
 *Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecución
 */
namespace Flamingo
{

    class MeshRendererFactory : public Factory
    {
      public:
        MeshRendererFactory(Flamingo::RenderSystem* t_renderSystem);

        Component* createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;

      private:
        Flamingo::RenderSystem* m_renderSystem;
        Ogre::SceneNode* root;
    };
} // namespace Flamingo
#endif