#include "PruebaScript.h"
//
//extern "C"
//{
//#include "lua.h"
//#include "lauxlib.h"
//#include "lualib.h"
//}
//#include <LuaBridge\LuaBridge.h>
#include <iostream>
namespace Flamingo
{

    PruebaScript::PruebaScript()
    {
    }

    PruebaScript::~PruebaScript()
    {
    }

    BehaviourScript* PruebaScript::clone()
    {
        return new PruebaScript();
    }

    void PruebaScript::initValues()
    {
        std::cout << "PruebaScript: initializing values "
                  << "\n";
    }

    void PruebaScript::initComponent()
    {
        std::cout << "PruebaScript: initializing component "
                  << "\n";
    }

    void PruebaScript::update(float t_delta_time)
    {
        // std::cout << "BehaviourScript: updating " << m_ent->getName() << "\n";
    }

    void PruebaScript::onCollisionEnter(GameObject* t_other)
    {
        std::cout << "PruebaScript: collision entered.\n";
    }

    void PruebaScript::onCollisionStay(GameObject* t_other)
    {
        std::cout << "PruebaScript: collision ongoing: "
                  << " with " << t_other->getName()
                  << ".\n ";
    }

    void PruebaScript::onCollisionExit(GameObject* t_other)
    {
        std::cout << "PruebaScript: collision finished.\n";
    }
} // namespace Flamingo