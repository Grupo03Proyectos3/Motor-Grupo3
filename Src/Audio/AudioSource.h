#pragma once
#ifndef __AUDIO_SOURCE_H__
#define __AUDIO_SOURCE_H__

#include "ECS/Component.h"
#include <string>

namespace FMOD
{
    class Sound;
}

class AudioSource : public ecs::Component
{
    public:
    __SYSTEM_ID_DECL__(ecs::_cmp_AUDIO_SOURCE)

    AudioSource();
    ~AudioSource();
    virtual void initComponent() override;
    void initValues(const char* songRoute, std::string songName, bool isMusic);

    protected:
    std::string m_audioName;
    bool m_playing;
    FMOD::Sound* m_sound;
};


#endif
