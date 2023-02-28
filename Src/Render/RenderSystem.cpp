#include "RenderSystem.h"
#include "Camera.h"
#include "Light.h"

#include "FlamingoUtils/GameObject.h"

void RenderSystem::initSystem() {
    m_window = new OgreWindow::Window("Motor");
    m_window->initApp();
    m_scene_mgr = m_window->getSceneManger();
    m_scene_node = m_scene_mgr->getRootSceneNode();

     // Cubo
   /* Ogre::Entity* entity = m_scene_mgr->createEntity("myEntity", "cube.mesh");
    entity->setMaterialName("Prueba/españa");
    Ogre::SceneNode* node = m_scene_node->createChildSceneNode();
    node->attachObject(entity);
    node->setPosition(Ogre::Vector3(0, 0, 0));*/

    // Luz
   /* GameObject* light_go = new GameObject(m_mngr);
    Light* cmp_light = light_go->addComponent<Light>(m_mngr, m_scene_node);
    cmp_light->initComponent("myLight");
    cmp_light->setType(Light::DIRECTIONAL);
    cmp_light->setSpecularColour();
    cmp_light->setDiffuseColour();*/

    // Camara
    /*GameObject* cam_go = new GameObject(m_mngr, SVector3(0, 500, -10));
    Camera* cmp_cam = cam_go->addComponent<Camera>(m_scene_mgr, m_scene_node);
    cmp_cam->initComponent(m_window, "myCamera");
    cmp_cam->setViewPortBackgroundColour(Ogre::ColourValue(0.3, 0.2, 0.6));
    cmp_cam->translate(0, 1000, -10);
    cmp_cam->lookAt(0, 0, 0, Camera::WORLD);*/
}

 RenderSystem::~RenderSystem() {
     delete m_window; 
     m_window = nullptr;
     delete m_scene_mgr;
     m_scene_mgr = nullptr;
     delete m_scene_node;
     m_scene_node = nullptr;
 }
