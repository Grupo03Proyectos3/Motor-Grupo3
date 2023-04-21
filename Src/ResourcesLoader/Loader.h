#ifndef __LOADER_H__
#define __LOADER_H__

#include <fstream>

class Loader
{
public:
    Loader(){};
    ~Loader(){};
   
    void loadDirectories();
   
private:
    
    void findDir(const char* t_path, std::ofstream& t_output);
};
#endif