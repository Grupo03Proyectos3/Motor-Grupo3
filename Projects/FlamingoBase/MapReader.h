#ifndef __MAPREADER_H__
#define __MAPREADER_H__
#pragma once

#include <map>
#include "FlamingoBase/ComponentsFactory.h"

using Data = std::map<std::string, std::string>;

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