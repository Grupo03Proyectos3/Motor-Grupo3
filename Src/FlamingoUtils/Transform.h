#pragma once
#ifndef __RENDER_H__
#define __RENDER_H__
#include "ECS/Component.h"
#include <FlamingoUtils/SVector3.h>
#include <FlamingoUtils/SQuaternion.h>

struct Transform : public ecs::Component{
  public:
    __SYSTEM_ID_DECL__(ecs::_cpm_TRANSFORM)
    Transform(SVector3 t_position, SQuaternion t_rotation, SVector3 t_scale);
    virtual ~Transform(){};
    virtual void initComponent();
    SVector3 getPosition();
    SQuaternion getRotation();
    SVector3 getScale();
  protected:
    SVector3 m_position;
    SQuaternion m_rotation;
    SVector3 m_scale;
};
#endif