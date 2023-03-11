#pragma once
#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "ECS/Component.h"
#include <map>
#include <string>
#include <vector>
class Factory
{
  public:
    Factory() = default;

   virtual ecs::Component* createComponent(const std::map<std::string, std::string>& args);

   void deleteComponents();

   private:
   std::vector<ecs::Component*> compsCreated;
};
#endif