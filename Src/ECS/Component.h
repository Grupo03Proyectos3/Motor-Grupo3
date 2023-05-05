#pragma once

#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "ecs.h"

namespace Flamingo
{
    struct __declspec(dllexport) Component
    {
      public:
        Component();

        
        virtual ~Component() {};
        
        /**
         * @brief M�todo que otorga contexto a la entidad
         *
         * @param[in] t_ent GameObject entidad
         * @param[in] t_mngr Manager 
         */
        void setContext(GameObject* t_ent, Manager* t_mngr);
        /**
         * @brief M�todo que se llama al a�adir un Compnente a un GameObject para inicializarlo
         *
         */
        virtual void initComponent(){};

        GameObject* gameObject();

      protected:

        GameObject* m_ent; // referencia a la entidad
        Manager* m_mngr;   // puntero al manager
    };
} // namespace Flamingo

#endif
