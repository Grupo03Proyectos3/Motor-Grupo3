#include "Biblioteca/Biblioteca.h"
#include <OgreRoot.h>
#include <btBulletCollisionCommon.h>
#include <chrono>
#include <crtdbg.h>
#include <fstream>
#include <iostream>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

   Ogre::Root* root;
   root = new Ogre::Root();
    saluda("XD");

    /* std::fstream f("Assets\\mapa.txt");
    if (f.is_open()) {
        std::cout << "FICHERO ABIERTO\n";
        f.close();
    }
    else {
        std::cerr << "FICHERO NO ABIERTO";
        return 1;
    }*/

    // Game-loop
    bool game_playing = false;

    auto start_time = std::chrono::high_resolution_clock::now();
    auto previous_time = std::chrono::duration_cast<std::chrono::milliseconds>(start_time - start_time);
    while (game_playing)
    {
        // leer entrada

        // actualizar con delta_time
        auto now = std::chrono::high_resolution_clock::now();
        auto actual_time = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time);
        unsigned long long int delta_time = (actual_time - previous_time).count();
        previous_time = actual_time;

        // renderizar
    }

    if (root)
    {
        delete root;
        root = nullptr;
    }

    _CrtDumpMemoryLeaks();
    return 0;
}