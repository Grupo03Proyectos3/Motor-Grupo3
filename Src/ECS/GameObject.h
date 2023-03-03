#pragma once

#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

class Manager;
// class Component;
#include "Component.h"
#include "ecs.h"
#include <array>
#include <cassert>
#include <string>
#include <vector>

namespace ecs
{
    /**
     *  Clase que representa una Entidad.
     */

    class GameObject
    {
      public:
        GameObject();
        GameObject(ecs::groupId_type t_gId);
        virtual ~GameObject();

        void setAlive(bool to);
        void setActive(bool to);

        std::string getName();

      private:
        friend class Manager;

        bool m_alive;
        bool m_active;
        std::vector<Component*> m_current_comps;
        std::array<Component*, maxComponentId> m_comps;
        ecs::groupId_type m_gId;

        std::string m_name;
    };
} // namespace ecs

#endif
