#pragma once
#ifndef __AUDIO_SYSTEM_H__
#define __AUDIO_SYSTEM_H__

#include "ECS/System.h"


namespace FMOD
{
    class Sound;
    class System;
    class SoundGroup;
    class Channel;
}
namespace Flamingo
{
    class AudioSystem : public ecs::System
    {
      public:
        __SYSTEM_ID_DECL__(ecs::_sys_AUDIO)

        AudioSystem();
        ~AudioSystem();

        void recieve(const Message&) override;
        void initSystem() override;
        void update(float t_delta_time) override;
    };
}

#endif
