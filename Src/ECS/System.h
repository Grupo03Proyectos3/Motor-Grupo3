#pragma once

#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include "ecs.h"
#include "messages_defs.h"

namespace Flamingo
{
    /**
     *  Clase que representa un Sistema.
     */

    class System
    {
      public:
        System();
        virtual ~System();

        /**
         * @brief Asocia un Manager (manejador) para que gestione al sistema
         *
         * @param[in] t_mngr Manager Manager (manejador) del sistema
         * @return
         */
        void setContext(Manager* t_mngr);

        /**
         * @brief Inicialización del sistema
         */
        virtual void initSystem();

        /**
         * @brief Actualiza el sistema utilizando el tiempo transcurrido desde el anterior frame
         *
         * @param[in] t_delta_time float Tiempo transcurrido desde el anterior frame
         */
        virtual void update(float t_delta_time);

        /**
         * @brief Método que recibe los mensajes enviados desde cualquier sistema
         *
         * @param[in] t_audioName Message Mensaje a recibir
         */
        virtual void recieve(const Message&);

        /**
         * @brief Devuelve el identificador de grupo asociado al Sistema
         *
         * @return Identificador del grupo al que pertenece este Sistema
         */
        inline groupId_type getGroup() { return m_group; };

      protected:
        Manager* m_mngr;
        groupId_type m_group;
    };
}

#endif
