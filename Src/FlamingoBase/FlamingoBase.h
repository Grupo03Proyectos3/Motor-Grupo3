#pragma once

namespace Flamingo
{
    class RenderSystem;
}

namespace Flamingo 
{
    class Scene;

    class FlamingoBase
    {
      public:

        FlamingoBase();
        ~FlamingoBase();

        bool FlamingoInit();
        void FlamingoLoop();
        bool FlamingoExit();
       
        void hola();
      private:

        bool loadScene(Flamingo::RenderSystem* t_render_sys, Scene* t_scene);

      
    };
}
