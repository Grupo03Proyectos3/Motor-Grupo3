// This file is part of the course TPV2@UCM - Samir Genaim
#pragma once

#ifndef __MESSAGES_DEFS_H__
#define __MESSAGES_DEFS_H__
//
//#include "FlamingoUtils/SQuaternion.h"
//#include "FlamingoUtils/SVector3.h"
#include "ecs.h"
#include <cstdint>
#include <array>
using msgId_type = uint8_t;
enum msgId : msgId_type
{
    MSG_TRANSFORM_MOVE,
    MSG_TRANSFORM_ROTATE,
    MSG_TRANSFORM_SCALING,
    MSG_WINDOW_RESIZED,
    MSG_COLLISION_STAY,
    MSG_COLLISION_ENTER,
    MSG_COLLIISION_EXIT,
    MSG_MOUSE_CLICK,
    MSG_MOUSE_MOVE
};


/**
 * @brief Estructura Message con el tipo de mensaje y datos
 * msgId_type id: Identifica el mensaje unívocamente
 */
struct Message
{
    msgId_type id;
    ecs::GameObject* entity_affected;

    union{
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
            ecs::GameObject* obj1;
            ecs::GameObject* obj2;
        }collision;

        struct
        {
            std::array<bool, 3> mouse_states;
        }ui_input;

        struct 
        {
            float x;
            float y;
        } moveMouse;
    };
};

#endif