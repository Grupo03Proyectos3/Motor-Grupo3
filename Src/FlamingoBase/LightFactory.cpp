#include "LightFactory.h"
#include "Render/Light.h"


ecs::Component* LightFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
  /*  try
    {
        float name = std::stof(args.at("t_name"));

        Light* c = ecs::AddComponent<Light>(gO);
        c->initValues();
        c->initComponent();

        compsCreated.push_back(c);
        return c;
       
    }
    catch (const std::exception&)
    {
        throw new std::exception("Invalids or incompletes params");
    }*/
}
