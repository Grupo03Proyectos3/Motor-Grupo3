#include "EnemyAI.h"

#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

#include "ECS/Manager.h"

EnemyAI::EnemyAI()
    : BehaviourScript()
{
}

void EnemyAI::initValues()
{
    m_tr = m_mngr->getComponent<Transform>(m_ent);
}

void EnemyAI::initComponent()
{
}

void EnemyAI::update()
{
    std::cout << "Soy el componente EnemyAI" << std::endl;

    // m_timeSinceLastDirectionChange += dt;
    //// SVector3 m_velocity;
    ////  Si ha pasado suficiente tiempo, cambia la direcci�n del enemigo
    //if (m_timeSinceLastDirectionChange >= 1000.0f)
    //{
    //    float x = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
    //    float y = 0;
    //    float z = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;

    //    // std::cout << "MARACUY�!!!!!!!!!!!! x: " << x << " y: " << y << " z: " << z << std::endl;

    //    // Crea un vector con estos valores y normal�zalo
    //    SVector3 direction(x, y, z);
    //    direction.normalize();
    //    // std::cout << "Normalice!!!!!!!!!!!! x: " << direction.getX() << " y: " << direction.getY() << " z: " << direction.getZ() << std::endl;

    //    // Genera una direcci�n aleatoria
    //    SVector3 randomDirection = direction;

    //    // Asigna una velocidad constante a lo largo de esta direcci�n
    //    m_velocity = randomDirection * 0.2f;

    //    // Reinicia el contador de tiempo
    //    m_timeSinceLastDirectionChange = 0;
    //}
    m_tr->translate(SVector3(0, 0.5, 0));
}
