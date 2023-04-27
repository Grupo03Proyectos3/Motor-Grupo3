#pragma once

#ifndef __COMPONENTS_H__
#define __COMPONENTS_H__

#include "Component.h"
#include "Lua/ScriptManager.h"
#include "ecs.h"

class GameObject;
namespace Flamingo
{
    template <typename T>
    inline T* AddComponent(GameObject* gO)
    {
        if (!std::is_base_of_v<BehaviourScript, T>)
            return Manager::instance()->addComponent<T>(gO);
        //falta asegurarse de que nunca se realice con un behaviorScript puro, sin heredar
        else
            return dynamic_cast<T*>(ScriptManager::instance()->addScript(typeid(T).name(), gO));
        
    }

    template <typename T>
    inline void removeComponent(GameObject* gO)
    {
        Manager::instance()->removeComponent<T>(gO);
    }

    template <typename T>
    inline T* getComponent(GameObject* gO)
    {
        return Manager::instance()->getComponent<T>(gO);
    }

    template <typename T>
    inline bool hasComponent(GameObject* gO)
    {
        return Manager::instance()->hasComponent<T>(gO);
    }
} // namespace Flamingo

#endif
