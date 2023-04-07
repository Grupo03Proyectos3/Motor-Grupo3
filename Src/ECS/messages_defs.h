// This file is part of the course TPV2@UCM - Samir Genaim
#pragma once

#ifndef __MESSAGES_DEFS_H__
#define __MESSAGES_DEFS_H__
//
//#include "FlamingoUtils/SQuaternion.h"
//#include "FlamingoUtils/SVector3.h"
#include "ecs.h"
#include <cstdint>

class GameObject;

using msgId_type = uint8_t;
enum msgId : msgId_type
{
    MSG_TRANSFORM_MOVE,
    MSG_TRANSFORM_ROTATE,
    MSG_TRANSFORM_SCALING,
    MSG_WINDOW_RESIZED,
    MSG_COLLISION_STAY
};

struct Message
{
    msgId_type id;

    union
    {
        ecs::GameObject* entity_affected;

        struct
        {
            double x;
            double y;
            double z;
        } vector;

        struct
        {
            double x;
            double y;
            double z;
            double w;
        } quaternion;

        struct
        {
            GameObject* obj1;
            GameObject* obj2;
        }collision;
    };
};

#endif