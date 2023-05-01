#ifndef __RENDER_SYSTEM_H__
#define __RENDER_SYSTEM_H__

#include "ECS/System.h"
#include "Camera.h"

namespace Ogre
{
    class FileSystemLayer;
    class Root;
}

namespace Flamingo
{
    class Window;

	class RenderSystem : public System
    {
        friend Scene;
      public:
        __SYSTEM_ID_DECL__(_sys_RENDER)

        RenderSystem(){};
        RenderSystem(std::string& t_app_name);
        virtual ~RenderSystem();

        void recieve(const Message&) override;
        void initSystem() override;
        void update(float t_delta_time) override;

        inline Flamingo::Window* getWindow() { return m_window; } 
        Ogre::Root* getOgreRoot(); // NO EXPORTAR
        
        inline void setMainCamera(Camera* t_camera) { m_camera = t_camera; }
        // en esta funcion se manipula la cámara
        void manipulateCamera();
        void inicializarShaders();
        void addShadersScene(Scene* scene);
      private:
        Ogre::Root* m_root = nullptr;                // OGRE root
        Ogre::FileSystemLayer* m_fs_layer = nullptr; // Fichero de recursos
        Flamingo::Window* m_window = nullptr;        
        std::string m_app_name;     // Nombre de la app
        Camera* m_camera = nullptr; // cámara

        void createRoot();
        void setUp();
        void loadResources();
        void locateResources();
        void bringResources(std::string& sec_name, std::string& type_name, std::string& arch_name);
        bool config();
        Ogre::SceneManager* createSceneManager(std::string name);
    };
}

#endif