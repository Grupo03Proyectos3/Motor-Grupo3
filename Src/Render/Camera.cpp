#include "Camera.h"

#include <OgreCamera.h>
#include <OgreRenderWindow.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreViewport.h>

Camera::Camera()
{
}

void Camera::initValues(Ogre::SceneManager* t_sceneMgr, Ogre::SceneNode* t_scene_node, Flamingo::Window* t_window, std::string t_name)
{
    m_scene_mngr =t_sceneMgr;
    m_cam = nullptr;
    m_vp = nullptr;
    m_window = t_window;
    m_cam_node = t_scene_node;
}

void Camera::initComponent()
{
    m_cam = m_scene_mngr->createCamera(m_name);
    // m_cam_node = m_scene_node->createChildSceneNode();
    m_cam_node->attachObject(m_cam);
    m_cam_node->setPosition(500, 500, 1000);

    m_vp = m_window->getRenderWindow()->addViewport(m_cam);
    m_vp->setDimensions(0, 0, 1, 1); // Tamaño completo de la ventana
}

void Camera::lookAt(Ogre::Vector3 t_pos, transformSpace t_trs)
{
    switch (t_trs)
    {
        case Camera::WORLD:
            m_cam_node->lookAt(t_pos, Ogre::Node::TransformSpace::TS_WORLD);
            break;
        case Camera::LOCAL:
            m_cam_node->lookAt(t_pos, Ogre::Node::TransformSpace::TS_LOCAL);
            break;
        case Camera::PARENT:
            m_cam_node->lookAt(t_pos, Ogre::Node::TransformSpace::TS_PARENT);
            break;
        default:
            break;
    }
}

void Camera::translate(float t_x, float t_y, float t_z)
{
    m_cam_node->translate(t_x, t_y, t_z);
}

void Camera::roll(float t_d)
{
    m_cam_node->roll(Ogre::Degree(t_d));
}

void Camera::yaw(float t_d)
{
    m_cam_node->yaw(Ogre::Degree(t_d));
}

void Camera::pitch(float t_d)
{
    m_cam_node->pitch(Ogre::Degree(t_d));
}

void Camera::setPolygonMode(polygonMode t_p)
{
    switch (t_p)
    {
        case Camera::POINTS:
            m_cam->setPolygonMode(Ogre::PM_POINTS);
            break;
        case Camera::SOLID:
            m_cam->setPolygonMode(Ogre::PM_SOLID);
            break;
        case Camera::WIREFRAME:
            m_cam->setPolygonMode(Ogre::PM_WIREFRAME);
            break;
        default:
            break;
    }
}

void Camera::setAutoAspectRatio(bool t_b)
{
    m_cam->setAspectRatio(t_b);
}

void Camera::setNearClipDistance(float t_clip)
{
    m_cam->setNearClipDistance(t_clip);
}

void Camera::setFarClipDistance(float t_clip)
{
    m_cam->setFarClipDistance(t_clip);
}

void Camera::setViewPortBackgroundColour(SColor t_vp_color)
{
    m_vp->setBackgroundColour(t_vp_color);
}

void Camera::desactiveViewport()
{
    m_vp->setVisibilityMask(0);
}

void Camera::activeViewport()
{
    m_vp->setVisibilityMask(1);
}

Ogre::SceneNode* Camera::getCamNode()
{
    return m_cam_node;
}