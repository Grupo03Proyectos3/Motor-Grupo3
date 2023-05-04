#ifndef __MAPREADER_H__
#define __MAPREADER_H__
#pragma once

#include "FlamingoBase/ComponentsFactory.h"
#include "FlamingoBase/MeshRendererFactory.h"
#include "FlamingoBase/RigidbodyFactory.h"
#include "FlamingoBase/TransformFactory.h"
#include "FlamingoBase/LightFactory.h"
#include "FlamingoBase/CameraFactory.h"
#include "FlamingoBase/AnimatorFactory.h"
#include "FlamingoBase/UIElementFactory.h"
#include "ECS/Manager.h"
#include <unordered_map>

using Data = std::unordered_map<std::string, std::string>;

class RenderSystem;
class Flamingo::Scene;
namespace Flamingo
{

    class MapReader
    {
      public:
        MapReader(Flamingo::RenderSystem* t_renderSystem);
        ~MapReader();

        /**
        @brief Añadde las factorías necesarias
        *
        @return
        */
        void initMapReader();
        bool readMap(std::string t_filename, Flamingo::Scene* t_scene);

      private:
        ComponentsFactory* m_componentFactory;
        Data m_data;
        Manager* m_mngr;
        GameObject* gO;

       
        Flamingo::RenderSystem* m_renderSystem;
    };
} // namespace Flamingo
#endif