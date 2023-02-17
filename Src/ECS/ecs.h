#pragma once

#ifndef __ECS_H__
#define __ECS_H__

#include <cstdint>

#if __has_include("ecs_defs.h")
#include "ecs_defs.h"

#endif
namespace ecs
{

    struct Component;
    class Entity;
    class Manager;
    class System;

    using compId_type = uint8_t;
    using groupId_type = uint8_t;
    using handlerId_type = uint8_t;
    using systemId_type = uint8_t;

    // list of component identifiers
    enum compId : compId_type
    {
        COMPS_LIST,

        // do not remove this
        LAST_COMP_ID
    };

    // list of group identifiers
    enum groupId : compId_type
    {
        _grp_GENERAL,
        GROUPS_LIST, /* taken from ../game/ecs_defs */

        // do not remove this
        LAST_GROUP_ID
    };

    // list of handler identifiers
    enum handlerId : handlerId_type
    {
        HANDLERS_LIST,

        // do not remove this
        LAST_HANDLER_ID
    };

    // list of system identifiers
    enum systemId : systemId_type
    {
        SYSTEMS_LIST,

        // do not remove this
        LAST_SYSTEM_ID
    };

    constexpr compId_type maxComponentId = compId::LAST_COMP_ID;
    constexpr groupId_type maxGroupId = groupId::LAST_GROUP_ID;
    constexpr handlerId_type maxHandlerId = handlerId::LAST_HANDLER_ID;
    constexpr systemId_type maxSystemId = systemId::LAST_SYSTEM_ID;


//
#define __COMP_ID_DECL__(cId) constexpr static ecs::compId_type id = cId;

// a macro for system identifier declaration, e.g., __SYSID_DECL__(ecs::_sys_ASTEROIDS)
// expands to:
//
//   constexpr static ecs::sysId_type id = ecs::_sys_ASTEROIDS;
//
#define __SYSTEM_ID_DECL__(cId) constexpr static ecs::systemId_type id = cId;

} // namespace ecs

#endif