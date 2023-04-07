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

void BehaviourScript::initValues()
{
    std::cout << "BehaviourScript: initializing values " << m_ent->getName() << "\n";
}

void BehaviourScript::initComponent()
{
    std::cout << "BehaviourScript: initializing component " << m_ent->getName() << "\n";
}

void BehaviourScript::update()
{
    // std::cout << "BehaviourScript: updating " << m_ent->getName() << "\n";
}

void BehaviourScript::onCollisionEnter(ecs::GameObject* t_one, ecs::GameObject* t_other)
{
    std::cout << "BehaviourScript: collision entered.\n";
}

void BehaviourScript::onCollisionStay(ecs::GameObject* t_one, ecs::GameObject* t_other)
{
    std::cout << "BehaviourScript: collision ongoing: " << t_one->getName() << " and " << t_other->getName()
              << ".\n ";
}
