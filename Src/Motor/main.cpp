#include <Windows.h>
#include <crtdbg.h>
#include <iostream>
#include <string>

#include "FlamingoExport/FlamingoCore.h"

typedef bool(__cdecl* GameEntryPoint)(void);

int main(int argc, char* argv[])
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

#ifdef _DEBUG
    HMODULE hinstLib = LoadLibrary(TEXT("GameExport_d"));
#else
    HMODULE hinstLib = LoadLibrary(TEXT("GameExport"));
#endif

    // PARA TRABAJAR CON EL JUEGO

    if (hinstLib != NULL)
    {
        std::cout << "Libreria cargada\n";

        Flamingo::FlamingoCore* core = Flamingo::FlamingoCore::instance();

        // Ejecución de una función
        GameEntryPoint initJuego = (GameEntryPoint)GetProcAddress(hinstLib, "InitJuego");
        if (initJuego)
        {
            initJuego();

            if (core->FlamingoInit())
            {
                core->FlamingoLoop();
            }
            else
                std::cout << "No se ha podido inicializar el motor\n";

            core->FlamingoExit();

            FreeLibrary(hinstLib); // OJO! Si cargo una DLL DEBO LIBERARLA -> debe hacerse al cerrar el juego
        }
        else
            std::cout << "No he encontrado InitJuego\n";
    }
    else
    {
        std::cout << "No se encuentra la DLL DllJuego\n";
    }

    //// PARA TRABAJAR DESDE EL MOTOR
    // Flamingo::FlamingoCore* fBase = new Flamingo::FlamingoCore();
    // if (fBase->FlamingoInit()){
    //     fBase->FlamingoLoop();
    //     fBase->FlamingoExit();
    // }
    // else
    //     return -1;
    // delete fBase;

    //_CrtDumpMemoryLeaks();

    return 0;
}