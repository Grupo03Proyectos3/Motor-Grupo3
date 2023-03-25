#pragma once

#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include "dirent.h"

class Loader
{

public:
    Loader(){};
    ~Loader(){};
   
    void loadDirectories();
   
private:
    std::string parsePath(std::string t_path);
    void findDir(const char* t_dir, std::ofstream& t_output);
};