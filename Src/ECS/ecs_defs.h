#pragma once
#ifndef __ECS_DEFS_H__
#define __ECS_DEFS_H__

// Lista de componentes
//
#define COMPS_LIST              \
    COMP_EXAMPLE,               \
        _cmp_RIGID_BODY,        \
        _cpm_CAMERA,            \
        _cmp_LIGHT,             \
        _cpm_TRANSFORM,         \
        _cmp_MESH_RENDERER,     \
        _cmp_PLAYER_CONTROLLER, \
        _cmp_ANIMATOR,          \
        _cpm_PARTICLE_SYSTEM

// Lista de grupos
//
#define GROUPS_LIST   \
    GROUP_EXAMPLE,    \
        GROUP_RENDER, \
        GROUP_PHYSICS

// Lista de Handlers
//
#define HANDLERS_LIST \
    HANDLER_EXAMPLE

// Lista de sistemas
//
#define SYSTEMS_LIST  \
    SYSTEM_EXAMPLE,   \
        _sys_PHYSICS, \
        _sys_RENDER, \
        _sys_UI, \
        _sys_LUA

#endif // !__ECS_DEFS__