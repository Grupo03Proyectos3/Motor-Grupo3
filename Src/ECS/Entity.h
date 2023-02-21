#pragma once

#ifndef __ENTITY_H__
#define __ENTITY_H__

// class Manager;
// class Component;
#include <array>
#include "Component.h"
#include "ecs.h"
#include <cassert>
#include <vector>

namespace ecs
{
    /**
     *  Clase que representa una Entidad.
     */

    class Entity
    {
      public:
        Entity(ecs::groupId_type t_gId);
        virtual ~Entity();

      private:
        friend Manager;

        bool m_alive;
        std::vector<Component*> m_current_comps;
        std::array<Component*, maxComponentId> m_comps;
        ecs::groupId_type m_gId;
    };
} // namespace ecs

#endif
