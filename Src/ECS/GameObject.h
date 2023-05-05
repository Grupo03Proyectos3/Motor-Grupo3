#pragma once

#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

// class Component;
#include "Component.h"
#include "ecs.h"
#include <array>
#include <cassert>
#include <string>
#include <vector>
#include <unordered_map>

namespace Flamingo
{
    class Manager;
    class ScriptManager;
    /**
     *  Clase que representa una Entidad.
     */

     class __declspec(dllexport) GameObject
    {
      public:
        GameObject();
        GameObject(std::vector<groupId_type> t_gId);
        virtual ~GameObject();

        void setAlive(bool to);
        void setActive(bool to);

        bool getAlive();
        bool getActive();

        std::string getName();
        void setName(std::string t_name);
        
        std::unordered_map<std::string, Component*> getCurrentComponents();

      private:
        friend class Manager;
        friend class ScriptManager;

        bool m_alive;
        bool m_active;
        std::unordered_map<std::string, Component*> m_current_comps;
        //std::array<Component*, maxComponentId> m_comps;
        std::vector<groupId_type> m_gIds;

        std::string m_name;
        std::string m_sceneName;
    };
} // namespace ecs

#endif
