#ifndef __ENEMY_AI_H__
#define __ENEMY_AI_H__

#include "ECS/Component.h"
#include "FlamingoUtils/SVector3.h"
#include "Lua/BehaviourScript.h"
#include <string>
#include <FlamingoBase/Transform.h>

struct EnemyAI : public BehaviourScript
{
  public:
    __SYSTEM_ID_DECL__(ecs::_cpm_ENEMY_AI)

    enum enemyType
    {
        // Enemigo Makoy Tipo 1
        SMALL,
        // Enemigo Makoy Tipo 2
        MEDIUM,
        // Enemigo Makoy Tipo 3
        BIG,
        // Jefe Makoy
        BOSS
    };
    EnemyAI();
    virtual ~EnemyAI(){};
    void initValues() override;
    void initComponent() override;
    void update() override;

  private:
    int m_timeSinceLastDirectionChange = 0;
    SVector3 m_velocity;
    Transform* m_tr;
};

#endif