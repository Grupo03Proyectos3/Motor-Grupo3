#pragma once
#ifndef __AUDIO_SOURCE_H__
#define __AUDIO_SOURCE_H__

#include "ECS/Component.h"
#include <string>
#include "FlamingoExport/FlamingoAPI.h"


namespace FMOD
{
    class Sound;
}
namespace Flamingo
{
    FLAMINGOEXPORT_API class AudioSource : public Flamingo::Component
    {
      public:
        __SYSTEM_ID_DECL__(Flamingo::_cmp_AUDIO_SOURCE)

        AudioSource();
        ~AudioSource();
        virtual void initComponent() override;
        void initValues(const char* songRoute, std::string songName, bool isMusic);
        void playAudio();

      protected:
        std::string m_audioName;
        bool m_playing;
        FMOD::Sound* m_sound;
    };
} // namespace Flamingo

#endif
