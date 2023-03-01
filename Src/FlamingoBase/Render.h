#pragma once
#ifndef __RENDER_H__
#define __RENDER_H__
#include "ECS/Component.h"
#include <OgreEntity.h>
#include <OgreSceneNode.h>
#include <FlamingoUtils/SVector3.h>
#include <FlamingoUtils/SQuaternion.h>

struct Render : public ecs::Component{
  public:
    __SYSTEM_ID_DECL__(ecs::_cpm_RENDER)
    Render(Ogre::SceneNode* t_root, Ogre::Entity* t_entity, Ogre::String t_materialName = "");
    virtual ~Render(){};
    virtual void initComponent();
    void setPosition(SVector3 t_pos);
    void setRotation(SQuaternion t_pos);
    void setScale(SVector3 t_pos);
    void changeMaterial(std::string t_materialName);
  protected:
    Ogre::Entity* m_ent_ogre;
    Ogre::SceneNode* m_scene_node;
    std::string m_materialName;
};
#endif