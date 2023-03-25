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
    
    void findDir(const char* t_path, std::ofstream& t_output);
};