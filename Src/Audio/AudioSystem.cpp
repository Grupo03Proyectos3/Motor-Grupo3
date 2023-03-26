#include "AudioSystem.h"

#include "ECS/Manager.h"
#include "AudioSource.h"

namespace Flamingo
{
    AudioSystem::AudioSystem()
    {
    }

    AudioSystem::~AudioSystem()
    {
    }

    void AudioSystem::recieve(const Message&)
    {
    }

    void AudioSystem::initSystem()
    {
        m_group = ecs::GROUP_AUDIO;
    }

    void AudioSystem::update(float t_delta_time)
    {
        //Actualiza todos los componentes de audio
        for (auto game_object : m_mngr->getEntities(m_group))
        {
            auto aSource = m_mngr->getComponent<AudioSource>(game_object);
            if (aSource != nullptr)
            {
        
            }
        }
    }
}
