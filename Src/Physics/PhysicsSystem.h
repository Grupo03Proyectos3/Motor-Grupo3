#pragma once
#ifndef __PHYSICS_SYSTEM_H__
#define __PHYSICS_SYSTEM_H__

#include "../ECS/System.h"

namespace Physics
{
    class PhysicsSystem : public ecs::System
    {
      public:
        __SYSTEM_ID_DECL__(ecs::_sys_PHYSICS)

        PhysicsSystem();
        virtual ~PhysicsSystem();

        void recieve(const Message&) override;
        void initSystem() override;
        void update(float t_delta_time) override;

      private:

    };

} // namespace Physics

#endif
