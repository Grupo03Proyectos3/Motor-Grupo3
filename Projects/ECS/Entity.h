// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once

#ifndef __ENTITY_H__
#define __ENTITY_H__
#include <array>
#include <bitset>
#include <cassert>
#include <vector>

#include "Component.h"
//#include "ecs.h"

namespace ecs
{
    class Entity
    {
      public:
        Entity(/*ecs::grpId_type gId*/);
        // we delete the copy constructor/assignment because it is
        // not clear how to copy the components
        

        Entity(const Entity&) = delete;
        Entity& operator=(const Entity&) = delete;


        // Exercise: define move constructor/assignment for class Entity

        // Destroys the entity
        //
        virtual ~Entity();
        // Updating  an entity simply calls the update of all
        // components
        //
        void update();

        // Rendering an entity simply calls the render of all
        // components
        //
        void render();

      private:
        //friend Manager;

        // the list of components is not really needed when using systems,
        // but for now we keep it just in case
        //
        /*std::vector<Component*> currCmps_;
        std::array<Component*, maxComponentId> cmps_;
        bool alive_;
        ecs::grpId_type gId_;*/
    };

} // namespace ecs
#endif
