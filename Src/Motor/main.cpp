#include <Windows.h>
#include <crtdbg.h>

#include "FlamingoBase/FlamingoBase.h"

typedef bool(__cdecl* GameEntryPoint)(void);

int main(int argc, char* argv[])
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtMemState sOld;
    _CrtMemState sNew;
    _CrtMemState sDiff;
    _CrtMemCheckpoint(&sOld); // take a snapshot

//#ifdef _DEBUG
//    HMODULE hinstLib = LoadLibrary(TEXT("EldersbaneExport_d"));
//#else
//    HMODULE hinstLib = LoadLibrary(TEXT("EldersbaneExport"));
//#endif
    //// carga implícita del motor en el main -> se hace en el juego
    // CFlamingoExport::Init();
    // CFlamingoExport* miMotor = CFlamingoExport::Instance();
    // miMotor->DoSomething();

    // PARA TRABAJAR CON EL JUEGO

    // if (hinstLib != NULL)
    //{
    //     Flamingo::FlamingoBase* fBase = new Flamingo::FlamingoBase();
    //     std::cout << "Libreria cargada\n";

    //    // Ejecución de una función

    //    GameEntryPoint initJuego = (GameEntryPoint)GetProcAddress(hinstLib, "InitJuego");
    //    if (initJuego)
    //    {
    //        initJuego();
    //        if (fBase->FlamingoInit())
    //        {
    //            fBase->FlamingoLoop();
    //            fBase->FlamingoExit();
    //        }
    //        else
    //            std::cout << "No he encontrado InitJuego\n";

    //        delete fBase;
    //        FreeLibrary(hinstLib); // OJO! Si cargo una DLL DEBO LIBERARLA -> debe hacerse al cerrar el juego
    //    }
    //}
    // else
    //{
    //    std::cout << "No se encuentra la DLL DllJuego\n";
    //}

    // PARA TRABAJAR DESDE EL MOTOR
    //FreeLibrary(hinstLib);
    Flamingo::FlamingoBase* fBase = new Flamingo::FlamingoBase();
    if (fBase->FlamingoInit())
    {
        fBase->FlamingoLoop();
    }

    fBase->FlamingoExit();
    delete fBase;

    // int* i = new int();

    _CrtMemCheckpoint(&sNew);                    // take a snapshot
    if (_CrtMemDifference(&sDiff, &sOld, &sNew)) // if there is a difference
    {
        OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
        _CrtMemDumpStatistics(&sDiff);
        OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
        _CrtDumpMemoryLeaks();
    }

    return 0;
}
