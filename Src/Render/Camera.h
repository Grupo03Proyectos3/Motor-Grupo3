#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "ECS/Component.h"
#include "Render/Window.h"
#include "FlamingoUtils/SColor.h"
#include "FlamingoUtils/SVector3.h"

#include <string>

struct Camera : ecs::Component
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
    Camera();
    virtual ~Camera(){};
    virtual void initValues(Ogre::SceneManager* t_sceneMgr, Ogre::SceneNode* t_scene_node, Flamingo::Window* t_window, std::string t_name);
    virtual void initComponent();

    //void lookAt(SVector3 t_pos, transformSpace t_trs = WORLD);
    void lookAt(SVector3 t_pos, transformSpace t_trs);
    void translate(float t_x, float t_y, float t_z);

    void roll(float t_d);
    void yaw(float t_d);
    void pitch(float t_d);

    void setPolygonMode(polygonMode t_p);
    void setAutoAspectRatio(bool t_b);
    void setNearClipDistance(float t_clip);
    void setFarClipDistance(float t_clip);

    void setViewPortBackgroundColour(SColor t_vp_color);
    void desactiveViewport();
    void activeViewport();
    void desactive();
    void active();
    Ogre::SceneNode* getCamNode();

  private:
    Ogre::Camera* m_cam;
    Ogre::Viewport* m_vp;
    Ogre::SceneManager* m_scene_mngr;
    // Ogre::SceneNode* m_scene_node;
    Ogre::SceneNode* m_cam_node;
    Flamingo::Window* m_window;

    std::string m_name;
};

#endif