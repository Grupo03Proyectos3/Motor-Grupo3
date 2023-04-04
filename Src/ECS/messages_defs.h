// This file is part of the course TPV2@UCM - Samir Genaim
#pragma once

#ifndef __MESSAGES_DEFS_H__
#define __MESSAGES_DEFS_H__
//
//#include "FlamingoUtils/SQuaternion.h"
//#include "FlamingoUtils/SVector3.h"
#include "ecs.h"
#include <cstdint>

using msgId_type = uint8_t;
enum msgId : msgId_type
{
    MSG_TRANSFORM_MOVE,
    MSG_TRANSFORM_ROTATE,
    MSG_TRANSFORM_SCALING,
    MSG_WINDOW_RESIZED
};

struct Message
{
    msgId_type id;
    ecs::GameObject* entity_affected;

    union
    {
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

        // const SQuaternion* q;
    };
};

#endif