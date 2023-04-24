#include "EnemyAI.h"

#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

#include "ECS/Manager.h"

EnemyAI::EnemyAI() {}
//
//void EnemyAI::initValues(Ogre::SceneManager* t_sceneMgr, Ogre::SceneNode* t_scene_node, Flamingo::Window* t_window, std::string t_name)
//{
//    m_scene_mngr =t_sceneMgr;
//    m_cam = nullptr;
//    m_vp = nullptr;
//    m_window = t_window;
//    m_cam_node = t_scene_node;
//    m_name = t_name;
//}

void EnemyAI::initComponent()
{
    //m_cam = m_scene_mngr->createCamera(m_name);
    //// m_cam_node = m_scene_node->createChildSceneNode();
    //m_cam_node->attachObject(m_cam);
    //m_cam_node->setPosition(500, 500, 1000);

    //m_vp = m_window->getRenderWindow()->addViewport(m_cam,-m_window->getRenderWindow()->getNumViewports());
    //m_vp->setDimensions(0, 0, 1, 1); // Tamaño completo de la ventana
}
