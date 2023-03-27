#include "AudioSystem.h"

#include "AudioSource.h"
#include "AudioSource.h"
#include "fmod.hpp"
#include "fmod_errors.h"

#include "ECS/Manager.h"

namespace Flamingo
{
    AudioSystem::AudioSystem()
    {
    }

    AudioSystem::~AudioSystem()
    {
        m_system->release();
    }

    void AudioSystem::recieve(const Message&)
    {
    }

    void AudioSystem::initSystem()
    {
        m_group = ecs::GROUP_AUDIO;
        auto result = FMOD::System_Create(&m_system);
   

        result = m_system->init(12, FMOD_3D, 0);
        result = m_system->set3DSettings(1.0f, 1.0f, 1.0f);

        //Grupos, música y efectos
        m_system->createSoundGroup("soundGroup", &m_soundGroup);
        m_soundGroup->setVolume(100);
        m_system->createSoundGroup("musicGroup", &m_musicGroup);
        m_musicGroup->setVolume(100);
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

        //Liberar los sonidos que no estén siendo reproducidos
    }

    FMOD::Sound AudioSystem::createSound(const char* route, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO* exinfo, FMOD::Sound* sound)
    {
        m_system->createSound(route, mode, exinfo, &sound);
    }

    void AudioSystem::addMusic(FMOD::Sound* sound, std::string soundName)
    {
        m_musicMap->emplace(soundName, sound);
        sound->setSoundGroup(m_musicGroup);
    }

    void AudioSystem::addSoundEffect(FMOD::Sound* sound, std::string soundName)
    {
        m_soundMap->emplace(soundName, sound);
        sound->setSoundGroup(m_soundGroup);
    }

    void AudioSystem::playAudio(std::string audioName)
    {
        FMOD::Channel* auxChannel = nullptr;
        FMOD::Sound* auxSound = nullptr;

        if (m_soundMap->count(audioName))
            auxSound = m_soundMap->find(audioName)->second;
        else if (m_musicMap->count(audioName))
            auxSound = m_musicMap->find(audioName)->second;
        else
        {
            //cout << "Sonido no encontrado" << "\n";
            //posibilidad de lanzar error
            return;
        }

        m_system->playSound(auxSound, nullptr, true, &auxChannel);

        auxChannel->setPaused(false);
        //Distancia en el mundo a la que se puede oir el sonido
        //auxChannel->set3DMinMaxDistance(minDistance, maxDistance);
        auxChannel->setMode(FMOD_3D_LINEARROLLOFF);
        m_channelMap->emplace(audioName, auxChannel);
    }



}
