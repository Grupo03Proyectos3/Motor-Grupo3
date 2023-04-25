#include "EnemyAI.h"

#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

#include "ECS/Manager.h"

EnemyAI::EnemyAI()
    : BehaviourScript()
{
}

void EnemyAI::initComponent()
{
    
}

void EnemyAI::update()
{
    std::cout << "Soy el componente EnemyAI" << std::endl;
}
