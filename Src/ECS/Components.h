#pragma once

#ifndef __COMPONENTS_H__
#define __COMPONENTS_H__


#include "Component.h"
#include "ecs.h"
#include "Manager.h"

class GameObject;
namespace ecs
{
    //La directiva de preprocesador _declspec(dllexport) es utilizada en C y C++ para indicar que una funci�n o variable debe ser exportada desde una biblioteca din�mica (DLL)
    //para que pueda ser utilizada por otros programas o bibliotecas. Quiz� hay que a�adirla a estos m�todos
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
