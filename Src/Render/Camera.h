#pragma once
#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "../ECS/Component.h"
#include "../ECS/Entity.h"
#include "../ECS/Manager.h"

#include <OgreCamera.h>
#include <OgreViewport.h>

struct Camera : public ecs::Component
{
  public:
    __SYSTEM_ID_DECL__(ecs::_cpm_CAMERA)

    Camera();
    virtual ~Camera();

    virtual void initComponent();

  private:
    Ogre::Camera* m_cam = nullptr;
    Ogre::Viewport* m_vp = nullptr;

};

#endif