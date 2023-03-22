#pragma once
#ifndef __UISYSTEM_H__
#define __UISYSTEM_H__

#include <CEGUI/Cegui.h>
#include "ECS/System.h"

namespace Flamingo{
    class UISystem : public ecs::System{
      public:
        __SYSTEM_ID_DECL__(ecs::_sys_UI)
        UISystem();
        virtual ~UISystem();
        void recieve(const Message&) override;
        void initSystem() override;
        void update(float t_delta_time) override;
    };
} // namespace Flamingo
#endif