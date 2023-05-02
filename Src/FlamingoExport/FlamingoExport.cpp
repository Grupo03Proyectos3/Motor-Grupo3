// FlamingoExport.cpp : Define las funciones exportadas del archivo DLL.
//

#include "FlamingoExport.h"
#include "FlamingoCore.h"

#include "Lua/BehaviourScript.h"
#include "Lua/ScriptManager.h"

#include "Render/Animator.h"

#include "UI/UIElement.h"

#include "ECS/InputHandlerContainer.h"
#include "ECS/Components.h"

#include "FlamingoBase/Scene.h"
#include "FlamingoBase/SceneManager.h"
#include "FlamingoBase/Transform.h"

#include "FlamingoUtils/FlamingoKeys.h"
#include "FlamingoUtils/SQuaternion.h"
#include "FlamingoUtils/SVector3.h"

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
