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
        auto audioSystem = m_mngr->getSystem<Flamingo::AudioSystem>();
        FMOD_RESULT result;
        if (m_isMusic)
        {
            audioSystem->createSound(m_songRoute.c_str(), FMOD_3D | FMOD_LOOP_NORMAL, nullptr, &m_sound);
            audioSystem->addMusic(m_sound, m_songName);
        }
        else
        {
            audioSystem->createSound(m_songRoute.c_str(), FMOD_3D | FMOD_DEFAULT, nullptr, &m_sound);
            audioSystem->addSoundEffect(m_sound, m_songName);
        }
        m_audioName = m_songName;
    }

    void AudioSource::initValues(const char* songRoute, std::string songName, bool isMusic)
    {
        m_playing = false;
        m_songRoute = songRoute;
        m_songName = songName;
        m_isMusic = isMusic;
    }
    void AudioSource::playAudio()
    {
        m_mngr->getSystem<Flamingo::AudioSystem>()->playAudio(m_audioName);
    }

    void AudioSource::stopAudio()
    {
        m_mngr->getSystem<Flamingo::AudioSystem>()->stopAudio(m_audioName);
    }
    void AudioSource::setVolume(float f)
    {
        m_mngr->getSystem<Flamingo::AudioSystem>()->stopAudio(m_audioName);
    }
} // namespace Flamingo