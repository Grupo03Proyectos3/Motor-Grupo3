#pragma once

#ifndef __MANAGER_FUNCTIONS_H__
#define __MANAGER_FUNCTIONS_H__

#include "Component.h"
#include "FlamingoBase/SceneManager.h"
#include "FlamingoBase/Transform.h"
#include "FlamingoExport/FlamingoCore.h"
#include "Manager.h"
#include "Scripting/ScriptManager.h"
#include "ecs.h"

namespace Flamingo
{

    /**
     * @brief Añade al GameObject dado y devuelve el componente, solicitandolo al Manager directamente o pasando por el ScriptManager, según
     * si pertenece al motor o ha sido creado por el usuario del motor
     *
     * @param[in] gO GameObject
     */
    template <typename T>
    __declspec(dllexport) inline T* addComponent(GameObject* gO)
    {
        if (!std::is_base_of_v<Component, T>)
            return nullptr;

        if (!std::is_base_of_v<BehaviourScript, T>)
        {
            auto c = Manager::instance()->addComponent<T>(gO);

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

    /**
     * @brief Elimina componente del GameObject si posee, solicitandolo al manager directamente o pasando por el ScriptManager, según
     * si pertenece al motor o ha sido creado por el usuario del motor
     *
     * @param[in] gO GameObject
     */
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

    /**
     * @brief Devuelve componente del GameObject, solicitandolo al manager directamente o pasando por el ScriptManager, según
     * si pertenece al motor o ha sido creado por el usuario del motor
     *
     * @param[in] gO GameObject
     */
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

    /**
     * @brief Comprueba si el GameObject dado contiene el componente,, solicitandolo al manager directamente o pasando por el ScriptManager, según
     * si pertenece al motor o ha sido creado por el usuario del motor
     *
     * @param[in] gO GameObject
     */
    template <typename T>
    __declspec(dllexport) inline bool hasComponent(GameObject* gO)
    {
        if (!std::is_base_of_v<Component, T>)
            return false;

        if (!std::is_base_of_v<BehaviourScript, T>)
            return Manager::instance()->hasComponent<T>(gO);
        else
            return ScriptManager::instance()->hasScript(typeid(T).name(), gO);
    }

    /**
     * @brief Solicita al Manager que se cree un GameObject y se le añada a los grupos proporcionados; asi como se le añada un componente
     * Transform por defecto
     *
     * @param[in] std::string t_n nombre para el GameObject
     * @param[in] std::vector<groupId_type> T_vect_gId grupos a los que añadir el GameObject
     *   @return GameObject*
     */
    __declspec(dllexport) inline GameObject* createGameObject(std::string t_n, std::vector<groupId_type> t_vect_gId = {})
    {
        auto gO = Manager::instance()->addGameObject(t_vect_gId);
        gO->setName(t_n);
        auto t = addComponent<Transform>(gO);
        t->initValues();
        t->initComponent();
        FlamingoCore::instance()->getSceneManager()->getSceneActive()->addObjects(gO);
        return gO;
    }
} // namespace Flamingo

#endif
