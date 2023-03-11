#pragma once
#ifndef __COMPONENTSFACTORY_H__
#define __COMPONENTSFACTORY_H__

#include "ECS/SingletonECS.h"
#include "Factory.h"
#include <map>
#include <string>

class ComponentsFactory : public SingletonECS<ComponentsFactory>
{
    friend SingletonECS<ComponentsFactory>;

  public:
    ComponentsFactory()
    {
        componentFactories = std::map<std::string, Factory*>();
    };

    ecs::Component* getComponent(const std::string& type, std::map<std::string, std::string> args);

    // crear una factoria del tipo X
    void addFactory(const std::string& type, const Factory* f);

  private:
    std::map<std::string, Factory*> componentFactories;
};
#endif