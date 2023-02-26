#pragma once
#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "../ECS/Component.h"
#include "../ECS/Entity.h"
#include "../ECS/Manager.h"

#include <OgreCamera.h>
#include <OgreViewport.h>
#include <string>

#include "Window.h"

struct Camera : public ecs::Component
{
  public:
    __SYSTEM_ID_DECL__(ecs::_cpm_CAMERA)

    enum polygon
    {
        POINTS,SOLID, WIREFRAME
    };

    Camera(Ogre::SceneManager* t_sceneMgr, Ogre::SceneNode* t_scene_node, Ogre::ColourValue t_vp_color = Ogre::ColourValue::Black);
    virtual ~Camera(){};

    virtual void initComponent(OgreWindow::Window* t_window, std::string t_name);

    void roll(float t_d);
    void yaw(float t_d);
    void pitch(float t_d);

    void setPolygonMode(polygon t_p);
    void setAutoAspectRatio(bool t_b);
    void setNearClipDistance(float t_clip);
    void setFarClipDistance(float t_clip);

  private:
    Ogre::Camera* m_cam = nullptr;
    Ogre::Viewport* m_vp = nullptr;
    Ogre::SceneManager* m_sceneMgr = nullptr;
    Ogre::SceneNode* m_scene_node = nullptr;
    Ogre::SceneNode* m_cam_node = nullptr;

    Ogre::ColourValue m_vp_color;
};

#endif