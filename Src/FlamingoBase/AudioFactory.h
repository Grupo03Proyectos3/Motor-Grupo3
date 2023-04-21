#pragma once
#ifndef __AUDIOFACTORY_H__
#define __AUDIOFACTORY_H__

#include "Factory.h"
#include "Audio/AudioSource.h"
/*Clase base para las diferentes factorías de componentes que tendremos en el proyecto.
 *Contiene una lista de todos los componentes creados para eliminarlos al finalziar la ejecución
 */
class AudioFactory : public Factory
{
  public:
    AudioFactory();

   ecs::Component* createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;
};
#endif