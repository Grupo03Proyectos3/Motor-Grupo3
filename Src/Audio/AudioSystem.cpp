#include "AudioSystem.h"

#include "AudioSource.h"

#include "fmod.hpp"
#include "fmod_errors.h"

#include "ECS/Manager.h"


namespace Flamingo
{
    AudioSystem::AudioSystem()
    {
        // m_group = ecs::GROUP_AUDIO;
    }

    AudioSystem::~AudioSystem()
    {
        m_system->release();

        delete m_soundMap;
        delete m_musicMap;
        delete m_channelMap;
    }

    void AudioSystem::recieve(const Message&)
    {
    }

    void AudioSystem::initSystem()
    {
        m_group = Flamingo::GROUP_AUDIO;
        checkError(FMOD::System_Create(&m_system));

        m_soundMap = new SoundMap();
        m_musicMap = new MusicMap();
        m_channelMap = new ChannelMap();

        checkError(m_system->init(32, FMOD_3D, 0));
        checkError(m_system->set3DSettings(1.0f, 1.0f, 1.0f));

        // Grupos, música y efectos
        checkError(m_system->createSoundGroup("soundGroup", &m_soundGroup));
        m_soundGroup->setVolume(0.2);
        checkError(m_system->createSoundGroup("musicGroup", &m_musicGroup));
        m_musicGroup->setVolume(0.2);
    }

    void AudioSystem::update(float t_delta_time)
    {
    }

    void AudioSystem::createSound(const char* route, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO* exinfo, FMOD::Sound** sound)
    {
        if (checkError(m_system->createSound(route, mode, exinfo, &(*sound))) == 1)
        {
            throw std::runtime_error("Fallo al cargar el audio de ruta" + (std::string)route); 
        }
    }

    FMOD::Sound* AudioSystem::createSound(const char* route, std::string name, bool isMusic)
    {
        FMOD::Sound* sound = nullptr;

        if (isMusic)
        {
            createSound(route, FMOD_3D | FMOD_LOOP_NORMAL, nullptr, &sound);
            addMusic(sound, name);
        }
        else
        {
            createSound(route, FMOD_3D | FMOD_DEFAULT, nullptr, &sound);
            addSoundEffect(sound, name);
        }
        return sound;
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

    void AudioSystem::playAudio(std::string t_audioName)
    {
        FMOD::Channel* auxChannel = nullptr;
        FMOD::Sound* auxSound = nullptr;

        if (m_soundMap->count(t_audioName))
            auxSound = m_soundMap->find(t_audioName)->second;
        else if (m_musicMap->count(t_audioName))
            auxSound = m_musicMap->find(t_audioName)->second;
        else
        {
            // cout << "Sonido no encontrado" << "\n";
            // posibilidad de lanzar error
            return;
        }

        m_system->playSound(auxSound, nullptr, true, &auxChannel);

        auxChannel->setPaused(false);
        // Distancia en el mundo a la que se puede oir el sonido
        // auxChannel->set3DMinMaxDistance(minDistance, maxDistance);
        auxChannel->setMode(FMOD_3D_LINEARROLLOFF);
        m_channelMap->emplace(t_audioName, auxChannel);
    }

    /// <summary>
    /// Volumen de 0 a 1 donde 1 es el máximo.
    /// </summary>
    /// <param name="f"></param>
    void AudioSystem::setMusicVolume(float f)
    {
        m_musicGroup->setVolume(f);
    }

    void AudioSystem::setSoundEffectsVolume(float f)
    {
        m_soundGroup->setVolume(f);
    }

    int AudioSystem::checkError(FMOD_RESULT result)
    {
        if (result != FMOD_OK)
        {
            return 1;
        }
        return 0;
    }
}




