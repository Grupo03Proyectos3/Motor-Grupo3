#pragma once
#ifndef __AUDIO_SYSTEM_H__
#define __AUDIO_SYSTEM_H__

#include "ECS/System.h"
#include <unordered_map>
#include <string>

namespace FMOD
{
    class Sound;
    class System;
    class SoundGroup;
    class Channel;
    class mega;
} // namespace FMOD

struct FMOD_CREATESOUNDEXINFO;
enum FMOD_RESULT;
typedef unsigned int FMOD_MODE;

namespace Flamingo
{
    class AudioSystem : public ecs::System
    {
        typedef std::unordered_map<std::string, FMOD::Sound*> SoundMap;
        typedef std::unordered_map<std::string, FMOD::Sound*> MusicMap;
        typedef std::unordered_map<std::string, FMOD::Channel*> ChannelMap;

      public:
        __SYSTEM_ID_DECL__(ecs::_sys_AUDIO)

        AudioSystem();
        ~AudioSystem();

        void recieve(const Message&) override;
        void initSystem() override;
        void update(float t_delta_time) override;

        void createSound(const char* route, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO* exinfo, FMOD::Sound** sound);
        FMOD::Sound* createSound(const char* route, std::string name, bool isMusic);
        void addMusic(FMOD::Sound* sound, std::string soundName);
        void addSoundEffect(FMOD::Sound* sound, std::string soundName);

        void playAudio(std::string audioName);
        void setMusicVolume(float f);
        void setSoundEffectsVolume(float f);

        int checkError(FMOD_RESULT result);

      protected:
        FMOD::System* m_system;
        FMOD::SoundGroup* m_musicGroup;
        FMOD::SoundGroup* m_soundGroup;

        SoundMap* m_soundMap;
        MusicMap* m_musicMap;
        ChannelMap* m_channelMap;
    };
}


#endif
