// FlamingoExport.cpp : Define las funciones exportadas del archivo DLL.
//

#include "FlamingoExport.h"
#include "FlamingoCore.h"

#include "Scripting/BehaviourScript.h"
#include "Scripting/ScriptManager.h"

#include "Render/Animator.h"

#include "UI/UIElement.h"

#include "ECS/InputHandlerContainer.h"
#include "ECS/ManagerFunctions.h"

#include "FlamingoBase/Scene.h"
#include "FlamingoBase/SceneManager.h"
#include "FlamingoBase/Transform.h"

#include "FlamingoUtils/FlamingoKeys.h"
#include "FlamingoUtils/SQuaternion.h"
#include "FlamingoUtils/SVector3.h"

#include <iostream>

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
