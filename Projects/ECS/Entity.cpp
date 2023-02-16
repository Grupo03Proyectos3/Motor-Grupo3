#include "Entity.h"

ecs::Entity::Entity(/*ecs::grpId_type gId*/)
//: currCmps_()
//, cmps_()
//, //
// alive_()
//,         //
// gId_(gId) //
{
    // We reserve the a space for the maximum number of
    // components. This way we avoid resizing the vector.

    // currCmps_.reserve(ecs::maxComponentId);
}

ecs::Entity::~Entity()
{
    // we delete all available components
    //
    /*for (auto c : cmps_)
        if (c != nullptr)
            delete c;*/
}


void ecs::Entity::update()
{
    /*auto n = currCmps_.size();
    for (auto i = 0u; i < n; i++)
        currCmps_[i]->update();*/
}

void ecs::Entity::render()

{
    /*auto n = currCmps_.size();
    for (auto i = 0u; i < n; i++)
        currCmps_[i]->render();*/
}
