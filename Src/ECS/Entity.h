#pragma once

#ifndef __ENTITY_H__
#define __ENTITY_H__

//class Manager;
//class Component;
#include <cassert>
#include <vector>
#include "Component.h"
#include "ecs.h"

namespace ecs
{
    /**
     *  Clase que representa una Entidad.
     */

    class Entity
    {
      public:
        Entity();
        virtual ~Entity();
        bool m_alive;

      private:
        friend Manager;

        std::vector<Component*> m_current_cmps;
        // std::array<Component*, maxComponentId> m_cmps;
        // ecs::grpId_type m_gId;
    };
}

#endif
