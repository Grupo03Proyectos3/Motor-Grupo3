#include "EnemyAI.h"

#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

#include "ECS/Manager.h"
#include <Physics/PlayerController.h>


EnemyAI::EnemyAI()
    : BehaviourScript()
{
}

void EnemyAI::initValues()
{
    m_tr = m_mngr->getComponent<Transform>(m_ent);
    m_time_last_dir = 0;
    m_time_last_move = 0;
    m_velocity = SVector3(0,0,0);
    m_wandering = false;
    m_lives = 2;
}

void EnemyAI::initComponent()
{
}

void EnemyAI::update(float t_delta_time)
{
    //if (m_lives <= 0)
    //{
    //    m_ent->setActive(false);
    //    m_ent->setAlive(false);
    //}
     m_time_last_dir += t_delta_time;
    //std::cout << m_timeSinceLastDirectionChange << std::endl;
    
    //  Si ha pasado suficiente tiempo, cambia la direccion del enemigo
    if (m_time_last_dir >= 5000.0f)
    {
        float x = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
        float y = 0;
        float z = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;


        // Crea un vector con estos valores y normal�zalo
        SVector3 direction(x, y, z);
        direction.normalize();

    
        // Asigna una velocidad constante a lo largo de esta direcci�n
        m_velocity = direction * 0.2f;

        // Reinicia el contador de tiempo
        m_time_last_dir = 0;
    }
    //m_tr->translate(SVector3(m_velocity*t_delta_time));
    //m_velocity = SVector3(0, 0, 0);
    //  Mueve el enemigo mientras no haya pasado suficiente tiempo
    if (m_time_last_dir < 2000.0f)
    {
        m_tr->translate(SVector3(m_velocity * t_delta_time));
    }
    else
    {
        m_velocity = SVector3(0, 0, 0);
    }
   
}

void EnemyAI::onCollisionEnter(ecs::GameObject* t_other)
{
    if (m_mngr->hasComponent<PlayerController>(t_other))
    {
        std::cout << "Choque: Jugador-Enemigo  "<<m_lives << std::endl;
        m_lives--;
    }
}
