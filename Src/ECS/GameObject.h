#pragma once

#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

// class Component;
#include "Component.h"
#include "ecs.h"
#include <array>
#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

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
        /**
         * @brief Establece si el GameObject está vivo o no
         *
         * @param[in] to bool estado de vida
         */
        void setAlive(bool to);
        /**
         * @brief  Establece si el GameObject está activo o no
         *
         * @param[in] to bool estado de actividad
         */
        void setActive(bool to);
        /**
         * @brief Devuelve si el GameObject está vivo
         *
         * @return bool
         */
        bool getAlive();
        /**
         * @brief Devuelve si el GameObject está activo
         *
         * @return bool
         */
        bool getActive();
        /**
         * @brief Devuelve el nombre GameObject
         *
         * @return std::string
         */
        std::string getName();
        /**
         * @brief Otorga nombre al GameObject
         *
         * @param[in] t_name std::string nombre a recibir
         */
        void setName(std::string t_name);
        /**
         * @brief Devuelve los componentes actuales que están asociados al GameObject
         *
         * @return std::unordered_map<std::string, Component*>
         */
        std::unordered_map<std::string, Component*> getCurrentComponents();

      private:
        friend class Manager;
        friend class ScriptManager;

        bool m_alive;
        bool m_active;
        std::unordered_map<std::string, Component*> m_current_comps;
        
        std::vector<groupId_type> m_gIds;

        std::string m_name;
        std::string m_sceneName;
    };
} // namespace Flamingo

#endif
