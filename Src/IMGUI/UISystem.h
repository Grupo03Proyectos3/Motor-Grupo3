#pragma once
#ifndef __UISYSTEM_H__
#define __UISYSTEM_H__

#include "ECS/System.h"

namespace Flamingo{
    class UISystem : public ecs::System{
      public:
        UISystem();
        ~UISystem();
        void initSystem() override;
        void update(float t_delta_time) override;
      private:
        int x;

    };
}
#endif
