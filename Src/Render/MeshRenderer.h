#pragma once
#ifndef __RENDER_H__
#define __RENDER_H__
#include "ECS/Component.h"
#include <OgreEntity.h>
#include <OgreSceneNode.h>
#include <FlamingoUtils/SVector3.h>
#include <FlamingoUtils/SQuaternion.h>

struct MeshRenderer : public ecs::Component
{
  public:
    __SYSTEM_ID_DECL__(ecs::_cmp_MESH_RENDERER)

    MeshRenderer(){};
    MeshRenderer(Ogre::Entity* t_entity, Ogre::String t_materialName = "");
    virtual ~MeshRenderer(){};
    virtual void initComponent();
    void changeMaterial(std::string t_materialName);

  protected:
    Ogre::Entity* m_ent_ogre;
    std::string m_materialName;
};
#endif