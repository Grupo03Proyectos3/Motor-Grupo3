#pragma once

#ifndef __COMPONENTS_H__
#define __COMPONENTS_H__


#include "Component.h"
#include "ecs.h"
#include "Manager.h"

class GameObject;
namespace ecs
{

    template <typename T, typename... Ts>
    _declspec(dllexport) T* AddComponent(GameObject* gO, Ts&&... args)
    {
        return Manager::instance()->addComponent<T>(gO, args...);
    }
   
    template <typename T>
    inline void removeComponent()
    {
        Manager::instance()->removeComponent<T>(this);
    }

    template <typename T>
    inline T* getComponent()
    {
        return Manager::instance()->getComponent<T>(this);
    }

    template <typename T>
    inline bool hasComponent()
    {
        return Manager::instance()->hasComponent<T>(this);
    }
} 

#endif
