#include "BehaviourScript.h"
//
//extern "C"
//{
//#include "lua.h"
//#include "lauxlib.h"
//#include "lualib.h"
//}
//#include <LuaBridge\LuaBridge.h>
#include <iostream>

BehaviourScript::BehaviourScript()
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

void BehaviourScript::initValues()
{
    std::cout << "BehaviourScript: initializing values " << m_ent->getName() << "\n";
}

void BehaviourScript::initComponent()
{
    std::cout << "BehaviourScript: initializing component " << m_ent->getName() << "\n";
}

void BehaviourScript::update(float t_delta_time)
{
    // std::cout << "BehaviourScript: updating " << m_ent->getName() << "\n";
}

void BehaviourScript::onCollisionEnter(ecs::GameObject* t_other)
{
    std::cout << "BehaviourScript: collision entered.\n";
}

void BehaviourScript::onCollisionStay(ecs::GameObject* t_other)
{
    std::cout << "BehaviourScript: collision ongoing: " << " with " << t_other->getName()
              << ".\n ";
}

void BehaviourScript::onCollisionExit(ecs::GameObject* t_other)
{
    std::cout << "BehaviourScript: collision finished.\n";
}
