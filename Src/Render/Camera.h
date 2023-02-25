#pragma once
#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "../ECS/Component.h"
#include "../ECS/Entity.h"
#include "../ECS/Manager.h"

#include <OgreCamera.h>
#include <OgreViewport.h>

#include "Window.h"

struct Camera : public ecs::Component
{
  public:
    __SYSTEM_ID_DECL__(ecs::_cpm_CAMERA)

    Camera(Ogre::SceneManager* t_sceneMgr, Ogre::SceneNode* t_scene_node);
    virtual ~Camera(){};

    virtual void initComponent(OgreWindow::Window* t_window);

  private:
    Ogre::Camera* m_cam = nullptr;
    Ogre::Viewport* m_vp = nullptr;
    Ogre::SceneManager* m_sceneMgr = nullptr;
    Ogre::SceneNode* m_scene_node = nullptr;
};

#endif