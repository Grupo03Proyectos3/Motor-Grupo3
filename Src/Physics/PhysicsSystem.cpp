#include "PhysicsSystem.h"

PhysicsSystem::PhysicsSystem()
{
}

PhysicsSystem::~PhysicsSystem()
{
}

void PhysicsSystem::recieve(const Message& t_message)
{
    switch (t_message.id)
    {
        default:
            // MESSAGE RECIEVED
            break;
    }
}

void PhysicsSystem::initSystem()
{
}

void PhysicsSystem::update(float t_delta_time)
{
}