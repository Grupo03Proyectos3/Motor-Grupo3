#ifndef __MAPREADER_H__
#define __MAPREADER_H__
#pragma once

#include "FlamingoBase/ComponentsFactory.h"
#include <unordered_map>

using Data = std::unordered_map<std::string, std::string>;

class MapReader
{
  public:
    MapReader();
    ~MapReader();

    void readMap(std::string filename);

  private:
    ComponentsFactory* mComponentFactory;
    Data mdata;
};

#endif