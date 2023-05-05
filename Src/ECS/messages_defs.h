#pragma once

#ifndef __MESSAGES_DEFS_H__
#define __MESSAGES_DEFS_H__
//
//#include "FlamingoUtils/SQuaternion.h"
//#include "FlamingoUtils/SVector3.h"
#include "ecs.h"
#include <cstdint>
#include <array>
#include "FlamingoBase/Transform.h"

namespace Flamingo
{
    using msgId_type = uint8_t;
    enum msgId : msgId_type
    {
        MSG_TRANSFORM_MOVE,
        MSG_TRANSFORM_TRANSLATE,
        MSG_TRANSFORM_ROTATE,
        MSG_TRANSFORM_SCALING,
        MSG_WINDOW_RESIZED,
        MSG_COLLISION_STAY,
        MSG_COLLISION_ENTER,
        MSG_COLLIISION_EXIT,
        MSG_MOUSE_CLICK,
        MSG_MOUSE_MOVE,
        MSG_GAME_OBJECT_ACTIVE_CHANGED
    };

    /**
     * @brief Estructura Message con el tipo de mensaje y datos
     * msgId_type id: Identifica el mensaje unívocamente
     */
    struct Message
    {
        msgId_type id;
        GameObject* entity_affected;
        STransformSpace tr_space;

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

            struct
            {
                GameObject* obj1;
                GameObject* obj2;
            } collision;

            struct
            {
                std::array<bool, 3> mouse_states;
            } ui_input;

            struct
            {
                double mouseX;
                double mouseY;
                double motionX;
                double motionY;
            } moveMouse;

            struct
            {
                GameObject* object_changed;
                bool mode;
            } gameObejctChangeActive;
        };
    };
} // namespace Flamingo
#endif