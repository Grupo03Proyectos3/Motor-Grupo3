#ifndef __ENEMY_AI_H__
#define __ENEMY_AI_H__

#include "ECS/Component.h"
#include "FlamingoUtils/SVector3.h"

#include <string>

struct EnemyAI : ecs::Component
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
    //virtual void initValues(Ogre::SceneManager* t_sceneMgr, Ogre::SceneNode* t_scene_node, Flamingo::Window* t_window, std::string t_name);
    virtual void initComponent();

  private:
    Ogre::SceneManager* m_scene_mngr;
    // Ogre::SceneNode* m_scene_node;
    std::string m_name;
};

#endif