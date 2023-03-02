#pragma once
#ifndef __PLAYER_CONTROLLER_H__
#define __PLAYER_CONTROLLER_H__

#include "../ECS/Component.h"
#include "../ECS/Entity.h"
#include "../ECS/Manager.h"



struct PlayerController : public ecs::Component
{
  public:
    __SYSTEM_ID_DECL__(ecs::_cmp_PLAYER_CONTROLLER)

    PlayerController();

    virtual ~PlayerController();

    virtual void initComponent();

  private:
};

#endif
