#include "AudioSource.h"

#include "fmod.hpp"
#include "ECS/Manager.h"
#include "AudioSystem.h"

Flamingo::AudioSource::AudioSource()
{
}

Flamingo::AudioSource::~AudioSource()
{
    //El sistema se encarga de borrar todos los sonidos creados, nosotros solo nos encargamos de poner el puntero a null
    m_sound = nullptr;
}

/// <summary>
/// Genera un audio a partir de una ruta
/// </summary>
void Flamingo::AudioSource::initComponent()
{
    m_playing = false;
}

void Flamingo::AudioSource::initValues(const char* songRoute, std::string songName, bool isMusic)
{
    auto audioSystem = m_mngr->getSystem<AudioSystem>();
    FMOD_RESULT result;
    if (isMusic)
    {
        audioSystem->createSound(songRoute, FMOD_3D | FMOD_LOOP_NORMAL, nullptr, m_sound);
        audioSystem->addMusic(m_sound, songName);
    }
    else
    {
        audioSystem->createSound(songRoute, FMOD_3D | FMOD_DEFAULT, nullptr, m_sound); 
        audioSystem->addSoundEffect(m_sound, songName);
    }
    m_audioName = songName;

}
