#include "Camera.h"
#include "RenderSystem.h"
#include "ECS/ManagerFunctions.h"

#include <OgreCamera.h>
#include <OgreRenderWindow.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreViewport.h>

#include "ECS/Manager.h"

namespace Flamingo
{
    Camera::Camera() {}

    void Camera::initValues(std::string t_name)
    {
        auto sys = m_mngr->getSystem<RenderSystem>();
        m_scene_mngr = FlamingoSceneManager().getSceneActive()->getSceneManger();
        m_cam = nullptr;
        m_vp = nullptr;
        m_target = nullptr;
        m_window = sys->getWindow();
        m_cam_node = FlamingoSceneManager().getSceneActive()->getSceneRoot()->createChildSceneNode();
        m_name = t_name;
    }

    void Camera::initComponent()
    {
        auto t = getComponent<Transform>(m_ent);
        if (t == nullptr)
        {
            throw std::exception("Transform is missing");
        }
        m_cam = m_scene_mngr->createCamera(m_name);
        m_cam_node->setScale(t->getScale());
        m_cam_node->setPosition(t->getPosition());
        m_cam_node->attachObject(m_cam);
        //m_cam_node->setPosition(100, 500, 100);
        //m_cam_node->setPosition(0, 48000, 0);
        //m_cam_node->setDirection(-1, 0, 0);
        m_vp = m_window->getRenderWindow()->addViewport(m_cam, -m_window->getRenderWindow()->getNumViewports());
        m_vp->setDimensions(0, 0, 1, 1); // Tamaño completo de la ventana
    }

     void Camera::lookAt(SVector3 t_pos, STransformSpace t_trs)
     {
        switch (t_trs)
        {
            case WORLD:
                m_cam_node->lookAt(t_pos, Ogre::Node::TransformSpace::TS_WORLD);
                break;
            case LOCAL:
                m_cam_node->lookAt(t_pos, Ogre::Node::TransformSpace::TS_LOCAL);
                break;
            case PARENT:
                m_cam_node->lookAt(t_pos, Ogre::Node::TransformSpace::TS_PARENT);
                break;
            default:
                break;
        }
    }

    void Camera::translate(float t_x, float t_y, float t_z)
    {
        m_cam_node->translate(t_x, t_y, t_z, Ogre::Node::TransformSpace::TS_LOCAL);
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
    void Camera::desactive()
    {
        m_vp->setCamera(nullptr);
    }

    Ogre::SceneNode* Camera::getNode()
    {
        return m_cam_node;
    }
    void Camera::active()
    {
        m_vp->setCamera(m_cam);
    }

    void Camera::setTarget(GameObject* go){
        m_target = go;
    }
    void Camera::setOffset(SVector3 offset)
    {
        m_offset = offset;
    }
    void Camera::FollowTarget(){
        if (m_target != nullptr){
            auto trpTarget = m_mngr->getComponent<Transform>(m_target);
            auto mtrp = m_mngr->getComponent<Transform>(m_ent);

            SVector3 newOffset = trpTarget->getRotation().Rotate(m_offset);
            mtrp->setPosition(trpTarget->getPosition() - newOffset);                     
            mtrp->setRotation(trpTarget->getRotation(),WORLD);

            lookAt({trpTarget->getPosition().getX(), trpTarget->getPosition().getY(), trpTarget->getPosition().getZ()}, WORLD);
            roll(180);
            //std::cout << trpTarget->getPosition() << "\n";
        }
    }
} // namespace Flamingo