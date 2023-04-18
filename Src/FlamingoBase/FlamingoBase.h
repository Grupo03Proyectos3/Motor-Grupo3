#pragma once

class RenderSystem;
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
       
      private:

        bool loadScene(RenderSystem* t_render_sys, Scene* t_scene);

      
    };
}
