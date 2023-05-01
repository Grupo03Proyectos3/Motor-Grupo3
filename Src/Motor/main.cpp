#include <Windows.h>
#include <crtdbg.h>
#include <fstream>
#include <iostream>
#include <string>

#include "FlamingoExport/FlamingoCore.h"

typedef bool(__cdecl* GameEntryPoint)(void);

int main(int argc, char* argv[])
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtMemState sOld;
    _CrtMemState sNew;
    _CrtMemState sDiff;
    _CrtMemCheckpoint(&sOld); // take a snapshot

#ifdef _DEBUG
    HMODULE hinstLib = LoadLibrary(TEXT("GameExport_d"));
#else
    HMODULE hinstLib = LoadLibrary(TEXT("GameExport"));
#endif

    Flamingo::FlamingoCore* fBase = new Flamingo::FlamingoCore();

    try
    {
        // PARA TRABAJAR CON EL JUEGO

        // if (hinstLib != NULL)
        //{
        //     std::cout << "Libreria cargada\n";

        //    Flamingo::FlamingoCore* core = Flamingo::FlamingoCore::instance();

        //    // Ejecución de una función
        //    GameEntryPoint initJuego = (GameEntryPoint)GetProcAddress(hinstLib, "InitJuego");
        //    if (initJuego)
        //    {
        //        initJuego();

        //        if (core->FlamingoInit())
        //        {
        //            core->FlamingoLoop();
        //        }
        //        else
        //            std::cout << "No se ha podido inicializar el motor\n";

        //        core->FlamingoExit();

        //        FreeLibrary(hinstLib); // OJO! Si cargo una DLL DEBO LIBERARLA -> debe hacerse al cerrar el juego
        //    }
        //    else
        //        std::cout << "No he encontrado InitJuego\n";
        //}
        // else
        //{
        //    std::cout << "No se encuentra la DLL DllJuego\n";
        //}

        // PARA TRABAJAR DESDE EL MOTOR
        FreeLibrary(hinstLib);
        if (fBase->FlamingoInit())
        {
            fBase->FlamingoLoop();
            fBase->FlamingoExit();
        }

        delete fBase;
    }
    catch (std::exception& excepcion)
    {
        std::cout << excepcion.what() << '\n';
    }
    catch (...)
    {
        std::cout << "Error al ejecutar el motor\n";
    }

    if (fBase != nullptr)
    {
        delete fBase;
    }

    // PARA TRABAJAR DESDE EL MOTOR
    // FreeLibrary(hinstLib);
    // Flamingo::FlamingoCore* fBase = new Flamingo::FlamingoCore();
    // if (fBase->FlamingoInit())
    //{
    //    fBase->FlamingoLoop();
    //    fBase->FlamingoExit();
    //}

    // delete fBase;

    // uncomment to check Memory leaks
    // int* i = new int();
    // _CrtDumpMemoryLeaks();
    //_CrtMemCheckpoint(&sNew);                    // take a snapshot
    // if (_CrtMemDifference(&sDiff, &sOld, &sNew)) // if there is a difference
    //{
    //    OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
    //    _CrtMemDumpStatistics(&sDiff);
    //    OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
    //    _CrtDumpMemoryLeaks();
    //}

    return 0;
}