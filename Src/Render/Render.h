#pragma once
#ifndef __RENDER_H__
#define __RENDER_H__
#include "ECS/Component.h"
#include <OgreEntity.h>
#include <OgreSceneNode.h>
struct Render : public ecs::Component{
  public:
    __SYSTEM_ID_DECL__(ecs::_cpm_RENDER)
    Render();
    virtual ~Render(){};
    virtual void initComponent(Ogre::SceneNode* t_root, Ogre::Entity* t_entity, Ogre::String t_materialName = "");

  protected:
    Ogre::Entity* m_ent;
    Ogre::SceneNode* m_scene_node;
    std::string m_materialName;
};
#endif