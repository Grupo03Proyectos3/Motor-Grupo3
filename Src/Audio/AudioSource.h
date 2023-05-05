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
    class AudioSource : public Flamingo::Component
    {
      public:
        __SYSTEM_ID_DECL__(Flamingo::_cmp_AUDIO_SOURCE)

        AudioSource();
        ~AudioSource();
        FLAMINGOEXPORT_API virtual void initComponent() override;
        FLAMINGOEXPORT_API void initValues(const char* songRoute, std::string songName, bool isMusic);
        FLAMINGOEXPORT_API void playAudio();
        FLAMINGOEXPORT_API void stopAudio();
        FLAMINGOEXPORT_API void setVolume(float f);

      protected:
        std::string m_audioName;
        FMOD::Sound* m_sound;
        std::string m_songRoute;
        std::string m_songName;
        bool m_isMusic;

    };
} // namespace Flamingo

#endif
