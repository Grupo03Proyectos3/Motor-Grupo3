#include "TransformFactory.h"
#include "Transform.h"

ecs::Component* TransformFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        //falta configurar trnasform para que sea adecuado
        Transform* c = ecs::AddComponent<Transform>(gO);
        //t->initValues();
        c->initComponent();

        compsCreated.push_back(c);
        return c;
       
    }
    catch (const std::exception&)
    {
        throw new std::exception("Parámetros de entrada inválidos o incompletos");
    }
}
