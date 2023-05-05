#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "ECS/Component.h"
#include "FlamingoBase/Transform.h"
#include "FlamingoUtils/SColor.h"
#include "FlamingoUtils/SVector3.h"
#include "Render/Window.h"
#include <string>

namespace Ogre
{
    class Camera;
    class Viewport;
    class SceneNode;
} // namespace Ogre

namespace Flamingo
{
    struct Camera : Flamingo::Component
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
        virtual ~Camera();
        virtual void initValues(std::string t_name, float t_color_x, float t_color_y, float t_color_z);
        virtual void initComponent();

        FLAMINGOEXPORT_API void lookAt(SVector3 t_pos, STransformSpace t_trs);
        FLAMINGOEXPORT_API void translate(float t_x, float t_y, float t_z);

        FLAMINGOEXPORT_API void roll(float t_d);
        FLAMINGOEXPORT_API void yaw(float t_d);
        FLAMINGOEXPORT_API void pitch(float t_d);

        FLAMINGOEXPORT_API void setPolygonMode(polygonMode t_p);
        FLAMINGOEXPORT_API void setAutoAspectRatio(bool t_b);
        FLAMINGOEXPORT_API void setNearClipDistance(float t_clip);
        FLAMINGOEXPORT_API void setFarClipDistance(float t_clip);

        FLAMINGOEXPORT_API void setViewPortBackgroundColour(SColor t_vp_color);
        void desactiveViewport();
        void activeViewport();
        void desactive();
        void active();

        Ogre::SceneNode* getNode();

        FLAMINGOEXPORT_API void setTarget(GameObject* go);
        FLAMINGOEXPORT_API void setOffset(SVector3 offset);
        FLAMINGOEXPORT_API void FollowTarget();

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