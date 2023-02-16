#pragma once

#ifndef __SYSTEM_H__
#define __SYSTEM_H__

class Manager;
namespace ecs
{
    /**
     *  Clase que representa un Sistema.
     */

    class System
    {
      public:
        System();
        virtual ~System();
        void setContext(Manager* t_mngr);
        virtual void initSystem();
        virtual void update();
        virtual void recieve(/*const Message&*/);

      protected:
        Manager* m_mngr;
    };
}

#endif
