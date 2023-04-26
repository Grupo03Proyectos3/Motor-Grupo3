#include "AudioFactory.h"

AudioFactory::AudioFactory()
{
}

ecs::Component* AudioFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        std::string route = (args.at("t_routeSong"));
        std::string name = (args.at("t_songName"));
        std::string musicS = (args.at("t_music"));

        bool music;

        if (musicS == "true")
            music = true;
        else if (musicS == "false")
            music = false;
        else 
             throw new std::exception("Invalids or incompletes params");


        AudioSource* c = ecs::AddComponent<AudioSource>(gO);
        c->initValues(route.c_str(), name, music);
        c->initComponent();

        ecs::Manager::instance()->addGameObjectToGroups(gO, {ecs::GROUP_AUDIO});
        return c;
    }
    catch (...)
    {
        std::cerr << "[ERROR Audio Factory]: Key not found" << '\n';
        exit(1);
    }
}
