#include "RenderSystem.h"

#include "Camera.h"
#include "Light.h"

void RenderSystem::recieve(const Message&)
{
}

void RenderSystem::initSystem()
{
   /* m_window = new OgreWindow::Window("Motor");
    m_window->initApp();
    m_scene_mgr = m_window->getSceneManger();
    m_scene_node = m_scene_mgr->getRootSceneNode();*/


}

void RenderSystem::update(float t_delta_time)
{
}

RenderSystem::~RenderSystem()
{
    delete m_window;
    m_window = nullptr;
    delete m_scene_mgr;
    m_scene_mgr = nullptr;
    delete m_scene_node;
    m_scene_node = nullptr;
}