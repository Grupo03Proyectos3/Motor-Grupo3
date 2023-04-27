#include "AudioSource.h"

#include "fmod.hpp"
#include "ECS/Manager.h"
#include "AudioSystem.h"
namespace Flamingo
{
    AudioSource::AudioSource()
    {
    }

    AudioSource::~AudioSource()
    {
        // El sistema de FMOD se encarga de borrar todos los sonidos creados, nosotros solo nos encargamos de poner el puntero a null
        m_sound = nullptr;
    }

    /// <summary>
    /// Genera un audio a partir de una ruta
    /// </summary>
    void AudioSource::initComponent()
    {
        m_playing = false;
    }

    void AudioSource::initValues(const char* songRoute, std::string songName, bool isMusic)
    {
        auto audioSystem = m_mngr->getSystem<Flamingo::AudioSystem>();
        FMOD_RESULT result;
        if (isMusic)
        {
            audioSystem->createSound(songRoute, FMOD_3D | FMOD_LOOP_NORMAL, nullptr, &m_sound);
            audioSystem->addMusic(m_sound, songName);
        }
        else
        {
            audioSystem->createSound(songRoute, FMOD_3D | FMOD_DEFAULT, nullptr, &m_sound);
            audioSystem->addSoundEffect(m_sound, songName);
        }
        m_audioName = songName;
    }
    void AudioSource::playAudio()
    {
        m_mngr->getSystem<Flamingo::AudioSystem>()->playAudio(m_audioName);
    }
} // namespace Flamingo