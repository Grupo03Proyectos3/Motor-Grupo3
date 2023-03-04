#pragma once
#include "ECS/component.h"
#include <OgreAnimationState.h>
#ifndef __ANIMATOR_H__
#define __ANIMATOR_H__
struct Animator : public ecs::Component{
  public:
    __SYSTEM_ID_DECL__(ecs::_cmp_ANIMATOR)
    Animator();
    virtual ~Animator(){};
    virtual void initComponent();

  private:
    Ogre::AnimationStateSet* m_anmation_state_set;

};
#endif