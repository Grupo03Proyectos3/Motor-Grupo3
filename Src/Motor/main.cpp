#include <Windows.h>
#include <crtdbg.h>
#include <fstream>
#include <iostream>
#include <string>

#include "FlamingoExport/FlamingoCore.h"

typedef bool(__cdecl* GameEntryPoint)(void);

#ifdef _DEBUG
int main(int argc, char* argv[])
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtMemState sOld;
    //_CrtMemState sNew;
    //_CrtMemState sDiff;
    //_CrtMemCheckpoint(&sOld); // take a snapshot

    HMODULE hinstLib = LoadLibrary(TEXT("GameExport_d"));
#else

int WINAPI wWinMain(HINSTANCE hInstance,  HINSTANCE  hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    HMODULE hinstLib = LoadLibrary(TEXT("GameExport"));
#endif

    auto core = Flamingo::FlamingoCore::instance();

    try
    {
        // PARA TRABAJAR CON EL JUEGO
        if (hinstLib != NULL)
        {
            std::cout << "Libreria cargada\n";
            // Ejecución de una función
            GameEntryPoint initJuego = (GameEntryPoint)GetProcAddress(hinstLib, "InitJuego");
            if (initJuego)
            {
                if (initJuego())
                {
                    if (core->FlamingoInit())
                    {
                        core->FlamingoLoop();
                    }
                    else
                        std::cout << "No se ha podido inicializar el motor\n";
                }
                else
                {
                    std::cout << "Ha ocurrido un error en initJuego\n";
                }
                
             
               // FreeLibrary(hinstLib); // OJO! Si cargo una DLL DEBO LIBERARLA -> debe hacerse al cerrar el juego
            }
            else
                std::cout << "No se ha encontrado initJuego\n";
        }
        else
        {
            std::cout << "No se encuentra la DLL DllJuego\n";
        }
    }
    catch (std::exception& excepcion)
    {
        std::cout << excepcion.what() << '\n';

        const char* cadena = excepcion.what();
        int tamano = MultiByteToWideChar(CP_UTF8, 0, cadena, -1, NULL, 0);
        std::wstring wstr(tamano, 0);
        MultiByteToWideChar(CP_UTF8, 0, cadena, -1, &wstr[0], tamano);
        LPCWSTR lpcwstr = wstr.c_str();
        MessageBox(NULL, lpcwstr, L"ERROR", MB_OK);
       
    }

    if (core != nullptr)
    {
        core->FlamingoExit();
        delete core;
    }

    FreeLibrary(hinstLib);

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