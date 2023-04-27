#ifndef __ENEMY_AI_H__
#define __ENEMY_AI_H__

#include "ECS/Component.h"
#include "FlamingoUtils/SVector3.h"
#include "Lua/BehaviourScript.h"
#include <string>
#include <FlamingoBase/Transform.h>
namespace Flamingo
{
    struct EnemyAI : public BehaviourScript
    {
      public:
        __SYSTEM_ID_DECL__(_cpm_ENEMY_AI)

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
        void update(float t_delta_time) override;
        void onCollisionEnter(GameObject* t_other) override;
        void onCollisionExit(GameObject* t_other) override;
        void checkDistance(SVector3 t_player_pos);
        void followPlayer(SVector3 t_player_pos);
        void attack();
        void getDamage(int t_damage);
        bool isAlive();

      private:
        Transform* m_tr;
        Transform* m_tr_player;
        float m_max_distance;
        int m_time_last_dir = 0;
        int m_time_last_move = 0;
        SVector3 m_velocity;
        SVector3 direction;
        bool m_wandering;
        bool m_attacking;
        bool m_colliding;
        int m_lives;

        void enemyMovement(float t_delta_time);
    };
} // namespace Flamingo
#endif