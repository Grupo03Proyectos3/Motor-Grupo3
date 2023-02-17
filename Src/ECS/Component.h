#pragma once

#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "ecs.h"

namespace ecs
{
    struct Component
    {
      public:
        Component();

        // Destroys the component.
        // Careful! ent_ and mngr_ should not be destroyed
        //
        virtual ~Component();
        // This method is used to set the context, which is a
        // reference to the entity in which the component is
        // installed and a reference to the manager. It will
        // be called by Entity when adding a component.
        //
         void setContext(Entity* t_ent, Manager* t_mngr);
        // We assume that initComponent will be called when adding a
        // component to an entity, immediately after setContext.
        //
        virtual void initComponent();

      protected:
        // as mentions above, when using systems these fields are not
        // really needed, but we keep them for now from the same reason that
        // we keep update/render
        
        Entity* m_ent;   // a reference to the entity, should not be deleted on destruction
        Manager* m_mngr; //  a pointer to the manager, should not be deleted on destruction
    };
} // namespace ecs

#endif
