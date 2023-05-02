#pragma once

#ifndef __COMPONENTS_H__
#define __COMPONENTS_H__

#include "Component.h"
#include "FlamingoBase/Transform.h"
#include "Lua/ScriptManager.h"
#include "Manager.h"
#include "ecs.h"

namespace Flamingo
{

    /*Añade al gameObejct dado y devuelve el componente, solicitandolo al manager directamente o pasando por el ScriptManager según
     * si pertenece al motor o ha sido creado por el ususario del motor */
    template <typename T>
    __declspec(dllexport) inline T* addComponent(GameObject* gO)
    {
        if (!std::is_base_of_v<Component, T>)
            return nullptr;

        if (!std::is_base_of_v<BehaviourScript, T>)
        {
            auto c = Manager::instance()->addComponent<T>(gO);
            dynamic_cast<Component*>(c)->initComponent();
            return c;
        }
        else
        {
            auto s = ScriptManager::instance()->addScript(typeid(T).name(), gO);
            s->initValues();
            s->initComponent();
            s->start();
            return dynamic_cast<T*>(s);
        }
    }

    /*Elimina componente del GameObject si posee, solicitandolo al manager directamente o pasando por el ScriptManager según
     * si pertenece al motor o ha sido creado por el ususario del motor */
    template <typename T>
    __declspec(dllexport) inline void removeComponent(GameObject* gO)
    {
        if (!std::is_base_of_v<Component, T>)
            return nullptr;

        if (!std::is_base_of_v<BehaviourScript, T>)
            Manager::instance()->removeComponent<T>(gO);
        else
            ScriptManager::instance()->removeScript(typeid(T).name(), gO);
    }

    /*Devuelve el componente, solicitandolo al manager directamente o pasando por el ScriptManager según
     * si pertenece al motor o ha sido creado por el ususario del motor */
    template <typename T>
    __declspec(dllexport) inline T* getComponent(GameObject* gO)
    {
        if (!std::is_base_of_v<Component, T>)
            return nullptr;

        if (!std::is_base_of_v<BehaviourScript, T>)
            return Manager::instance()->getComponent<T>(gO);
        else
            return dynamic_cast<T*>(ScriptManager::instance()->getScript(typeid(T).name(), gO));
    }

    /*Comprueba si el gameObject dado contiene el componente, solicitandolo al manager directamente o pasando por el ScriptManager según
     * si pertenece al motor o ha sido creado por el ususario del motor */
    template <typename T>
    __declspec(dllexport) inline bool hasComponent(GameObject* gO)
    {
        if (!std::is_base_of_v<Component, T>)
            return nullptr;

        if (!std::is_base_of_v<BehaviourScript, T>)
            return Manager::instance()->hasComponent<T>(gO);
        else
            return ScriptManager::instance()->hasScript(typeid(T).name(), gO);
    }

    /*Solicita al manager que se cree un gameObject y se le añada a los grupos proporcionados; asi como se le añada un componente
    transform por defecto*/
    __declspec(dllexport) inline GameObject* createGameObject(std::vector<groupId_type> t_vect_gId = {})
    {
        auto gO = Manager::instance()->addGameObject(t_vect_gId);
        auto t =addComponent<Transform>(gO);
        t->initValues();
        t->initComponent();
        return gO;
    }
} // namespace Flamingo

#endif
