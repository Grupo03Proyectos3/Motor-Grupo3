#pragma once
#ifndef __RENDER_H__
#define __RENDER_H__

#include "ECS/Component.h"
#include "../ECS/Entity.h"
#include "../ECS/Manager.h"

#include <OgreEntity.h>
#include <OgreSceneNode.h>

/*
 * Este componente contiene los materiales, iluminacion y todo lo relacionado con el renderizado de una malla
 * 
 */

struct MeshRenderer : public ecs::Component
{
  public:
    __SYSTEM_ID_DECL__(ecs::_cmp_MESH_RENDERER)

    MeshRenderer();
    virtual ~MeshRenderer();
    virtual void initComponent(Ogre::SceneNode* t_root, Ogre::Entity* t_entity, Ogre::String t_materialName);

  protected:
   
};
#endif