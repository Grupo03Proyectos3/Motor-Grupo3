#include "Camera.h"

#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreSceneNode.h>

Camera::Camera(Ogre::SceneManager* t_sceneMgr, Ogre::SceneNode* t_scene_node)
    : m_scene_node(t_scene_node)
    , m_sceneMgr(t_sceneMgr)
{
}

void Camera::initComponent(OgreWindow::Window* t_window)
{
    m_cam = m_sceneMgr->createCamera("myCamera");
    Ogre::SceneNode* cam_node = m_scene_node->createChildSceneNode();
    cam_node->translate(0, 1000, -10);
    cam_node->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TransformSpace::TS_WORLD);
    cam_node->attachObject(m_cam);

    m_vp = t_window->getRenderWindow()->addViewport(m_cam);
    m_vp->setBackgroundColour(Ogre::ColourValue(0.3, 0.2, 0.6));
    m_vp->setDimensions(0, 0, 1, 1); // Tamaño completo de la ventana
}