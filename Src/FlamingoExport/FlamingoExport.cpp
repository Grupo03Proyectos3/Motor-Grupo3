// FlamingoExport.cpp : Define las funciones exportadas del archivo DLL.
//

#include "pch.h"
#include "framework.h"
#include "FlamingoExport.h"
#include <iostream>
namespace Flamingo
{
    //// Ejemplo de variable exportada
    // FLAMINGOEXPORT_API int nFlamingoExport=0;
    //
    //// Ejemplo de funciÃ³n exportada.
    // FLAMINGOEXPORT_API int fnFlamingoExport(void)
    //{
    //     return 0;
    // }

    CFlamingoExport* CFlamingoExport::_instance = nullptr;

    bool CFlamingoExport::Init()
    {
        _instance = new CFlamingoExport();
        return true;
    }

    CFlamingoExport* CFlamingoExport::Instance()
    {
        return _instance;
    }

    // Constructor de clase exportada.
    CFlamingoExport::CFlamingoExport()
    {
        return;
    }

    void CFlamingoExport::DoSomething()
    {
        std::cout << "CFlamingoExport::DoSomething() : " << _instance << "\n";
    }
} // namespace Flamingo