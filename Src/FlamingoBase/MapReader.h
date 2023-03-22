#ifndef __MAPREADER_H__
#define __MAPREADER_H__
#pragma once

#include "FlamingoBase/ComponentsFactory.h"
#include "FlamingoBase/PlayerControllerFactory.h"
#include "ECS/Manager.h"
#include <unordered_map>

using Data = std::unordered_map<std::string, std::string>;

class RenderSystem;

class MapReader
{
  public:
    MapReader();
    ~MapReader();

    void readMap(std::string t_filename, RenderSystem* t_renderSystem);

  private:
    ComponentsFactory* m_componentFactory;
    Data m_data;
    ecs::Manager* m_mngr;
   
};

#endif