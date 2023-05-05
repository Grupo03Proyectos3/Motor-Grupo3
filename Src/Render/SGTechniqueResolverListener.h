#ifndef __SGTechniqueResolverListener_H__
#define __SGTechniqueResolverListener_H__

#include "OgreMaterialManager.h"
#include <OgreRTShaderSystem.h>

/** Implementaci�n por defecto de un Listener para usar con el sistema Ogre::RTShader.
    Cuando se invoca una devoluci�n de llamada del esquema de destino con el esquema del generador de sombreado, intenta crear un sombreador equivalente
    t�cnica basada en la t�cnica predeterminada del material dado
*/
namespace Flamingo{
    class SGTechniqueResolverListener : public Ogre::MaterialManager::Listener
    {
      public:
        SGTechniqueResolverListener(Ogre::RTShader::ShaderGenerator* pShaderGenerator);

        /** Este es el punto de enlace donde se crear� la t�cnica basada en shaders.
            Se llamar� siempre que el responsable del material no encuentre la t�cnica adecuada
            que satisfacen el nombre del esquema de destino. Si el nombre del esquema est� fuera del sistema RT Shader de destino
            nombre del esquema, intentaremos crear una t�cnica generada por el sombreador para �l
        */
        Ogre::Technique* handleSchemeNotFound(unsigned short schemeIndex,
                                              const Ogre::String& schemeName,
                                              Ogre::Material* originalMaterial, unsigned short lodIndex,
                                              const Ogre::Renderable* rend) override;

        bool afterIlluminationPassesCreated(Ogre::Technique* tech) override;

        bool beforeIlluminationPassesCleared(Ogre::Technique* tech) override;

      protected:
        Ogre::RTShader::ShaderGenerator* mShaderGenerator;
    };
} // namespace Flamingo
#endif