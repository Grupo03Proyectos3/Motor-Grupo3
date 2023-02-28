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

    enum polygonMode
    {
        POINTS,
        SOLID, 
        WIREFRAME
    };

    enum transformSpace
    {
        WORLD,
        LOCAL,
        PARENT
    };

    Camera(Ogre::SceneManager* t_sceneMgr, Ogre::SceneNode* t_scene_node);
    virtual ~Camera(){};

    virtual void initComponent(OgreWindow::Window* t_window, std::string t_name);

    void lookAt(float t_x, float t_y, float t_z, transformSpace t_trs = WORLD);
    void translate(float t_x, float t_y, float t_z);

    void roll(float t_d);
    void yaw(float t_d);
    void pitch(float t_d);

    void setPolygonMode(polygonMode t_p);
    void setAutoAspectRatio(bool t_b);
    void setNearClipDistance(float t_clip);
    void setFarClipDistance(float t_clip);

    void setViewPortBackgroundColour(Ogre::ColourValue t_vp_color);
    void desactiveViewport();
    void activeViewport();
  private:
    Ogre::Camera* m_cam = nullptr;
    Ogre::Viewport* m_vp = nullptr;
    Ogre::SceneManager* m_sceneMgr = nullptr;
    Ogre::SceneNode* m_scene_node = nullptr;
    Ogre::SceneNode* m_cam_node = nullptr;
};

#endif