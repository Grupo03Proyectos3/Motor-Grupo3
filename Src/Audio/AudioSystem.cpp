#include "AudioSystem.h"

#include "AudioSource.h"

#include "fmod.hpp"
#include "fmod_errors.h"

#include "ECS/Manager.h"


AudioSystem::AudioSystem()
{
    //m_group = ecs::GROUP_AUDIO;
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
    m_group = ecs::GROUP_AUDIO;
    checkError(FMOD::System_Create(&m_system)); 

    m_soundMap = new SoundMap();
    m_musicMap = new MusicMap();
    m_channelMap = new ChannelMap();
    
    checkError(m_system->init(32, FMOD_3D, 0));
    checkError(m_system->set3DSettings(1.0f, 1.0f, 1.0f));
    
    //Grupos, m�sica y efectos
    checkError(m_system->createSoundGroup("soundGroup", &m_soundGroup));
    m_soundGroup->setVolume(0.5);
    checkError(m_system->createSoundGroup("musicGroup", &m_musicGroup));
    m_musicGroup->setVolume(0.5);
}
    
void AudioSystem::update(float t_delta_time)
{
    //Actualiza todos los componentes de audio
    for (auto game_object : m_mngr->getEntities(m_group))
    {
        /*auto aSource = m_mngr->getComponent<AudioSource>(game_object);
        if (aSource != nullptr)
        {
            
        }*/
    }
    
    //Liberar los sonidos que no est�n siendo reproducidos
}
    
/// <summary>
/// Devuelve en el par�metro Sound el sonido ya creado.
/// </summary>
/// <param name="route"></param>
/// <param name="mode"></param>
/// <param name="exinfo"></param>
/// <param name="sound"></param>
void AudioSystem::createSound(const char* route, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO* exinfo, FMOD::Sound** sound)
{
    checkError(m_system->createSound(route, mode, exinfo, &(*sound)));
}

/// <summary>
/// Crea el sonido y lo asigna al grupo correspondiente
/// </summary>
/// <param name="route"></param>
/// <param name="name"></param>
/// <param name="isMusic">True para grupo m�sica, false para grupo sound effect.</param>
/// <returns></returns>
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

/// <summary>
/// Volumen de 0 a 1 donde 1 es el m�ximo.
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




