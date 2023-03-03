// This file is part of the course TPV2@UCM - Samir Genaim
#pragma once

#ifndef __MESSAGES_DEFS_H__
#define __MESSAGES_DEFS_H__

#include <cstdint>

#include "ecs.h"

using msgId_type = uint8_t;
enum msgId : msgId_type
{
    MSG_EXAMPLE
};

struct Message
{
    msgId_type id;

    union
    {
        struct
        {
            ecs::GameObject* e;
        } example_msg;
    };
};

#endif