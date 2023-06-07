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
    /// Genera un audio a partir de una ruta y lo guarda a través de un nombre
    /// </summary>
    void AudioSource::initComponent()
    {
        auto audioSystem = m_mngr->getSystem<Flamingo::AudioSystem>();
        audioSystem->createSound(m_songRoute.c_str(), m_audioName, m_isMusic);
    }

    void AudioSource::initValues(const char* songRoute, std::string songName, bool isMusic)
    {
        m_songRoute = songRoute;
        m_audioName = songName;
        m_isMusic = isMusic;
    }
    void AudioSource::playAudio()
    {
        m_mngr->getSystem<Flamingo::AudioSystem>()->playAudio(m_audioName);
    }

    void AudioSource::stopAudio()
    {
        auto aSys = m_mngr->getSystem<Flamingo::AudioSystem>();
        std::string s = m_audioName;
        aSys->stopAudio(s);
    }
    void AudioSource::setVolume(float f)
    {
        m_mngr->getSystem<Flamingo::AudioSystem>()->setChannelVolume(f, m_audioName);
    }
} // namespace Flamingo