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
#include <unordered_map>

namespace ecs
{
    /**
     *  Clase que representa una Entidad.
     */

    class GameObject
    {
      public:
        GameObject();
        GameObject(std::vector<groupId_type> t_gId);
        virtual ~GameObject();

        void setAlive(bool to);
        void setActive(bool to);

        std::string getName();

      private:
        friend class Manager;

        bool m_alive;
        bool m_active;
        std::unordered_map<std::string, Component*> m_current_comps;
        //std::array<Component*, maxComponentId> m_comps;
        std::vector<ecs::groupId_type> m_gIds;

        std::string m_name;
    };
} // namespace ecs

#endif
