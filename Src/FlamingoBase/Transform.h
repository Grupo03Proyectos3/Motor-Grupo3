#pragma once
#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "ECS/Component.h"

#include <FlamingoUtils/SVector3.h>
#include <FlamingoUtils/SQuaternion.h>
#include <OgreSceneNode.h>

struct Transform : public ecs::Component {
  public:
    __SYSTEM_ID_DECL__(ecs::_cpm_TRANSFORM)

    Transform();
    Transform(Ogre::SceneNode* t_node, SVector3 t_position = SVector3(0.0, 0.0, 0.0), SQuaternion t_rotation = SQuaternion(0.0, 0.0, 0.0, 1.0), SVector3 t_scale = SVector3(1.0, 1.0, 1.0));
    virtual ~Transform(){};
    virtual void initComponent();

    SVector3 getPosition();
    SQuaternion getRotation();
    SVector3 getScale();

    void setPosition(SVector3 t_pos);
    void setRotation(SQuaternion t_rotation);
    void setScale(SVector3 t_scale);

    void setNode(Ogre::SceneNode* t_node);
    Ogre::SceneNode* getNode();

  private:
    SVector3 m_position;
    SQuaternion m_rotation;
    SVector3 m_scale;

    Ogre::SceneNode* m_transform;
};
#endif