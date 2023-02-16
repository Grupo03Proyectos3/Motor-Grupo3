#pragma once

#ifndef __COMPONENT_H__
#define __COMPONENT_H__

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
        inline void setContext(/*Entity* ent, Manager* mngr*/);

        // We assume that initComponent will be called when adding a
        // component to an entity, immediately after setContext.
        //
        virtual void initComponent();
        // A component has an update method, and by default it
        // does nothing -- some components will not override this
        // method.
        //
        virtual void update();

        // A component has a render method, and by default it
        // does nothing -- some components will not override this
        // method.
        //
        virtual void render();

      protected:
        // as mentions above, when using systems these fields are not
        // really needed, but we keep them for now from the same reason that
        // we keep update/render
        
        //Entity* ent_;   // a reference to the entity, should not be deleted on destruction
        //Manager* mngr_; //  a pointer to the manager, should not be deleted on destruction
    };
} // namespace ecs

#endif
