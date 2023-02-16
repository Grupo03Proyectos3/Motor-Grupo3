#pragma once

#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "Manager.h"

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

      private:
        friend Manager;

        std::vector<Component*> m_current_cmps;
        // std::array<Component*, maxComponentId> cmps_;
        bool m_alive;
        // ecs::grpId_type gId_;
    };
}

#endif
