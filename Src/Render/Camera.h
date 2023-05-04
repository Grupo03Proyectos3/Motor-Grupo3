#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "ECS/Component.h"
#include "Render/Window.h"
#include "FlamingoUtils/SColor.h"
#include "FlamingoUtils/SVector3.h"
#include "FlamingoBase/Transform.h"
#include <string>

namespace Ogre
{
    class Camera;
    class Viewport;
    class SceneNode;
}

namespace Flamingo
{
    struct FLAMINGOEXPORT_API Camera : Flamingo::Component
    {
      public:
        __SYSTEM_ID_DECL__(Flamingo::_cpm_CAMERA)

        enum polygonMode
        {
            POINTS,
            SOLID,
            WIREFRAME
        };

        Camera();
        virtual ~Camera(){};
        virtual void initValues(std::string t_name, float t_color_x, float t_color_y, float t_color_z);
        virtual void initComponent();

        void lookAt(SVector3 t_pos, STransformSpace t_trs);
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

        Ogre::SceneNode* getNode(); // NO EXPORTAR

        void setTarget(GameObject* go);
        void setOffset(SVector3 offset);
        void FollowTarget();
      private:
        Ogre::Camera* m_cam;
        Ogre::Viewport* m_vp;
        Ogre::SceneManager* m_scene_mngr;
        Ogre::SceneNode* m_cam_node;
        Flamingo::Window* m_window;

        GameObject* m_target;
        SVector3 m_offset;
        SColor m_color;
        std::string m_name;
    };
} // namespace Flamingo
#endif