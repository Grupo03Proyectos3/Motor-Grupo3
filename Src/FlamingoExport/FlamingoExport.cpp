// FlamingoExport.cpp : Define las funciones exportadas del archivo DLL.
//

#include "FlamingoCore.h"
#include "FlamingoExport.h"

#include "Lua/ScriptManager.h"
#include "Lua/BehaviourScript.h"

#include "Render/Animator.h"

#include "UI/UIElement.h"

#include "FlamingoBase/Scene.h"
#include "FlamingoBase/SceneManager.h"
#include "FlamingoUtils/SVector3.h"
#include "FlamingoBase/Transform.h"
#include <iostream>

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
