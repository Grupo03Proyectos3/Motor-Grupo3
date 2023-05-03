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
    class AudioSystem : public Flamingo::System
    {
        typedef std::unordered_map<std::string, FMOD::Sound*> SoundMap;
        typedef std::unordered_map<std::string, FMOD::Sound*> MusicMap;
        typedef std::unordered_map<std::string, FMOD::Channel*> ChannelMap;

      public:
        __SYSTEM_ID_DECL__(Flamingo::_sys_AUDIO)

        AudioSystem();
        ~AudioSystem();

        void recieve(const Message&) override;
        void initSystem() override;
        void update(float t_delta_time) override;

      
        /**
         * @brief Crea el sonido y lo asigna al grupo correspondiente
         *
         * 
         */
        void createSound(const char* route, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO* exinfo, FMOD::Sound** sound);
        
        /**
         * @brief Crea el sonido y lo asigna al grupo correspondiente
         *
         * @param[in] route const char* Ruta del audio en la carpeta assets
         * @param[in] t_name string Nombre del audio
         * @param[in] isMusic bool True si es música, false si es un SoundEffect
         * @return FMOD::Sound* El sonido creado y registrado
         */
        FMOD::Sound* createSound(const char* route, std::string t_name, bool t_isMusic);

        /**
         * @brief Resgistra un audio como música
         *
         * @param[in] t_audioName string Nombre del audio
         * @return
         */
        void addMusic(FMOD::Sound* sound, std::string soundName);

        /**
         * @brief Registra un audio como efecto de sonido
         *
         * @param[in] t_audioName string Nombre del audio
         * @return
         */
        void addSoundEffect(FMOD::Sound* sound, std::string soundName);


         /**
         * @brief Reproduce un audio ya registrado
         *
         * @param[in] t_audioName string Nombre del audio
         * @return
         */
        void playAudio(std::string t_audioName);
        void stopAudio(std::string t_audioName);
        void setMusicVolume(float f);
        void setSoundEffectsVolume(float f);


      protected:


        /**
         * @brief Crea el sonido y lo asigna al grupo correspondiente
         *
         * @param[in] result FMOD_RESULT Control de errores de FMOD
         * @return int 1 si ha habido algún problema, 0 en otro caso
         */
        int checkError(FMOD_RESULT result);

        FMOD::System* m_system;
        FMOD::SoundGroup* m_musicGroup;
        FMOD::SoundGroup* m_soundGroup;

        SoundMap* m_soundMap;
        MusicMap* m_musicMap;
        ChannelMap* m_channelMap;
    };
}


#endif
