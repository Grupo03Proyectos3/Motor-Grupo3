#ifndef __ANIMATOR_H__
#define __ANIMATOR_H__

#include "ECS/component.h"
#include "FlamingoUtils/SQuaternion.h"
#include "FlamingoUtils/SVector3.h"
#include "FlamingoBase/Transform.h"
#include "MeshRenderer.h"
#include <unordered_map>

namespace Ogre
{
    class AnimationState;
    class SceneManager;
}

namespace Flamingo
{
    __declspec(dllexport) class Animator : public Flamingo::Component
    {
      public:
        __SYSTEM_ID_DECL__(Flamingo::_cmp_ANIMATOR)
        Animator();
        virtual ~Animator(){};
        virtual void initValues(std::string name);
        virtual void initComponent();

        void createAnimation(std::string t_name, double t_duration);
        void setFrameAnimation(std::string t_nameAnimation, double t_duration,
                               SVector3 t_translate, SQuaternion t_rotacion, SVector3 t_scale);

        void setAnimation(std::string t_name, bool t_active, bool t_loop = false);
        void allAnimations(bool t_active);

        int getAnimationsActive() { return m_num_animations_active; };

        void updateAnimations(double time);

      private:
        std::unordered_map<std::string, Ogre::AnimationState*> m_animations;
        Ogre::SceneManager* m_scene_mngr;
        Transform* m_transform;
        MeshRenderer* m_meshRenderer;
        int m_num_animations_active;
        std::string m_name;
    };
} // namespace Flamingo
#endif