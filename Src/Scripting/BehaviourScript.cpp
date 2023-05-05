#include "BehaviourScript.h"
#include <iostream>
namespace Flamingo
{
    BehaviourScript::BehaviourScript()
        : Component()
    {
    }

    BehaviourScript::~BehaviourScript()
    {
    }

    BehaviourScript* BehaviourScript::clone()
    {
        return new BehaviourScript();
    }

    std::string BehaviourScript::GetScriptName()
    {
        return typeid(*this).name();
    }
} // namespace Flamingo