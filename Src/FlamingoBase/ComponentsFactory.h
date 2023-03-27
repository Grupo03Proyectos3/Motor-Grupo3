#pragma once
#ifndef __COMPONENTSFACTORY_H__
#define __COMPONENTSFACTORY_H__

#include "ECS/SingletonECS.h"
#include "ECS/GameObject.h"
#include "Factory.h"
#include <map>
#include <string>

/*Clase que se encarga de gestionar las diferentes factorías de componentes. 
* Se le pueden tanto pedir componentes como añadir factorías para posteriormente obtener componentes del tipo dado.
*/
class ComponentsFactory : public SingletonECS<ComponentsFactory>
{
    friend SingletonECS<ComponentsFactory>;

  public:
    ComponentsFactory();
    ~ComponentsFactory();


    ecs::Component* addComponent(ecs::GameObject* gO, const std::string& type, std::unordered_map<std::string, std::string> args);

    // crear una factoria del tipo X
    void addFactory(std::string type, Factory* f);

  private:
    std::map<std::string, Factory*> componentFactories;
};
#endif