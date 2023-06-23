#pragma once
#ifndef PARTICLESFACTORY_H
#define PARTICLESFACTORY_H

#include "Factory.h"

namespace Flamingo
{

    class ParticlesFactory : public Factory
    {
      public:
        ParticlesFactory() = default;

        Component* createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;
    };
} // namespace Flamingo
#endif