#include "PlayerController.h"

#include "ECS/InputHandlerContainer.h"

namespace Flamingo
{
    PlayerController::PlayerController()
    {
    }

    PlayerController::~PlayerController()
    {
        delete m_mainCamera;
    }

    void PlayerController::initValues(float t_playerSpeed)
    {
        m_playerSpeed = (t_playerSpeed);
        m_active = (true);
        m_mainCamera = (new Camera());
    }

    void PlayerController::initComponent()
    {
        m_transform = m_mngr->getComponent<Transform>(m_ent);
    }

    void PlayerController::movePlayer(float t_vertical, float t_horizontal)
    {
        m_transform->translate(SVector3(t_horizontal, 0, t_vertical));
    }

    void PlayerController::rotatePlayer(SQuaternion t_angle)
    {
        m_transform->setRotation(t_angle);
    }
    void PlayerController::handleInput()
    {
        auto& ihldr = Flamingo::Input();
        // Ogre::Quaternion quat(Ogre::Degree(90), Ogre::Vector3::UNIT_Y); TO DO, no debería usar Ogre
        // SQuaternion q = SQuaternion(quat);
        if (ihldr.keyDownEvent())
        {
            if (ihldr.isKeyDown(FLM_w))
            {
                movePlayer(m_playerSpeed, 0.0f);
                rotatePlayer(SQuaternion(0.0, 0.0, 0.0, 1.0));
            }
            else if (ihldr.isKeyDown(FLM_s))
            {
                movePlayer(-m_playerSpeed, 0.0f);
                rotatePlayer(SQuaternion(0.0, 1.0, 0.0, 0.0));
            }
            if (ihldr.isKeyDown(FLM_a))
            {
                movePlayer(0.0f, -m_playerSpeed);
                rotatePlayer(SQuaternion(0.0, -0.7071068, 0.0, 0.7071068));
            }
            else if (ihldr.isKeyDown(FLM_d))
            {
                movePlayer(0.0f, m_playerSpeed);
                rotatePlayer(SQuaternion(0.0, 0.7071068, 0.0, 0.7071068));
            }
        }
    }
} // namespace Flamingo