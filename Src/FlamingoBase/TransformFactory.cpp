#include "TransformFactory.h"
#include "Transform.h"

ecs::Component* TransformFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        float p_x = std::stof(args.at("positionX"));
        float p_y = std::stof(args.at("positionY"));
        float p_z = std::stof(args.at("positionZ"));

        float r_x = std::stof(args.at("rotationX"));
        float r_y = std::stof(args.at("rotationY"));
        float r_z = std::stof(args.at("rotationZ"));
        float r_w = std::stof(args.at("rotationW"));

        float s_x = std::stof(args.at("scaleX"));
        float s_y = std::stof(args.at("scaleY"));
        float s_z = std::stof(args.at("scaleZ"));


        Transform* c = ecs::AddComponent<Transform>(gO);
        c->initValues(SVector3(p_x, p_y, p_z), SQuaternion(r_x, r_y, r_z, r_w), SVector3(s_x, s_y, s_z));
        c->initComponent();

        return c;
       
    }
    catch (...)
    {
        std::cerr << "[ERROR Transform Factory]: Key not found" << '\n';
        exit(1);
    }
}
