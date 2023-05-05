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
        Ogre::Root* getOgreRoot();

        void inicializarShaders();
        void addShadersScene(Scene* scene);
      private:
        Ogre::Root* m_root = nullptr;                // OGRE root
        Ogre::FileSystemLayer* m_fs_layer = nullptr; // Fichero de recursos
        Flamingo::Window* m_window = nullptr;        
        std::string m_app_name;     // Nombre de la app
        /**
        @brief Crea la raiz
        **/
        void createRoot();
        /**
        @brief Crea, inilicializa la ventana y llama a inicializar los recursos
        **/
        void setUp();
        /**
        @brief Inicializa los recursos
        **/
        void loadResources();
        /**
        @brief Carga los recursos en el sistema si estos no han sido inicilizados
        **/
        void locateResources();
        /**
        @brief Trae los recursos al sistema y inicializa el pipeline de renderizado
        **/
        void bringResources(std::string& sec_name, std::string& type_name, std::string& arch_name);
        /**
        @brief Comprueba la configuración guardada de video/sonido/etc
        *
        @return bool Devuelve true si habia configuracion.
        */
        bool config();
        /**
        @brief Crea un SceneManager de Ogre
        **/
        Ogre::SceneManager* createSceneManager(std::string name);
    };
}

#endif