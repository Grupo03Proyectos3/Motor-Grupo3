#pragma once
#ifndef __MESH_RENDERER_H__
#define __MESH_RENDERER_H__
#include "ECS/Component.h"

#include <OgreEntity.h>
#include <OgreSceneNode.h>

struct MeshRenderer : public ecs::Component
{
  public:
    __SYSTEM_ID_DECL__(ecs::_cmp_MESH_RENDERER)

    MeshRenderer(){};
    MeshRenderer(Ogre::SceneNode* t_node, Ogre::Entity* t_entity, Ogre::String t_materialName = "");
    virtual ~MeshRenderer();
    virtual void initComponent();
    void changeMaterial(std::string t_materialName);

  protected:
    Ogre::Entity* m_ent_ogre;
    std::string m_material_name;
};
#endif