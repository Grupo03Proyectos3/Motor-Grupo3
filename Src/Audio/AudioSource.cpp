#include "AudioSource.h"



Flamingo::AudioSource::AudioSource()
{
}

Flamingo::AudioSource::~AudioSource()
{
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

}
