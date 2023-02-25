#pragma once
#ifndef __ECS_DEFS_H__
#define __ECS_DEFS_H__

// Lista de componentes
//
#define COMPS_LIST \
    COMP_EXAMPLE,  \
        _cmp_RIGID_BODY, \
        _cpm_CAMERA

// Lista de grupos
//
#define GROUPS_LIST \
    GROUP_EXAMPLE

// Lista de Handlers
//
#define HANDLERS_LIST \
    HANDLER_EXAMPLE

// Lista de sistemas
//
#define SYSTEMS_LIST \
    SYSTEM_EXAMPLE,  \
        _sys_PHYSICS

#endif // !__ECS_DEFS__