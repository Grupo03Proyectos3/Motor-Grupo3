#include "Factory.h"

namespace Flamingo
{
    Factory::~Factory()
    {}

    Flamingo::Component* Factory::createComponent(Flamingo::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
    {
        return nullptr;
    }


} // namespace Flamingo