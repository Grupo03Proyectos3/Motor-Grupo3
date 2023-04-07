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
        _cpm_PARTICLE_SYSTEM,   \
        _cmp_AUDIO_SOURCE,      \
        _cmp_UIELEMENT,         \
        _cmp_BEHAVIOUR_SCRIPT

// Lista de grupos
//
#define GROUPS_LIST    \
    GROUP_EXAMPLE,     \
        GROUP_RENDER,  \
        GROUP_PHYSICS, \
        GROUP_AUDIO,   \
        GROUP_UI

// Lista de Handlers
//
#define HANDLERS_LIST \
    HANDLER_EXAMPLE

// Lista de sistemas
//
#define SYSTEMS_LIST  \
    SYSTEM_EXAMPLE,   \
        _sys_PHYSICS, \
        _sys_RENDER,  \
        _sys_UI,      \
        _sys_LUA,     \
        _sys_AUDIO

#endif // !__ECS_DEFS__