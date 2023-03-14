#pragma once

#ifndef __COMPONENTS_H__
#define __COMPONENTS_H__


#include "Component.h"
#include "ecs.h"
#include "Manager.h"

class GameObject;
namespace ecs
{
    //La directiva de preprocesador _declspec(dllexport) es utilizada en C y C++ para indicar que una función o variable debe ser exportada desde una biblioteca dinámica (DLL)
    //para que pueda ser utilizada por otros programas o bibliotecas. Quizá hay que añadirla a estos métodos
    template <typename T>
    inline T* AddComponent(GameObject* gO)
    {
        return Manager::instance()->addComponent<T>(gO);
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
