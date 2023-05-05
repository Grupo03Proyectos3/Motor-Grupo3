#ifndef __SGTechniqueResolverListener_H__
#define __SGTechniqueResolverListener_H__

#include "OgreMaterialManager.h"
#include <OgreRTShaderSystem.h>

/** Implementación por defecto de un Listener para usar con el sistema Ogre::RTShader.
    Cuando se invoca una devolución de llamada del esquema de destino con el esquema del generador de sombreado, intenta crear un sombreador equivalente
    técnica basada en la técnica predeterminada del material dado
*/
namespace Flamingo{
    class SGTechniqueResolverListener : public Ogre::MaterialManager::Listener
    {
      public:
        SGTechniqueResolverListener(Ogre::RTShader::ShaderGenerator* pShaderGenerator);

        /** Este es el punto de enlace donde se creará la técnica basada en shaders.
            Se llamará siempre que el responsable del material no encuentre la técnica adecuada
            que satisfacen el nombre del esquema de destino. Si el nombre del esquema está fuera del sistema RT Shader de destino
            nombre del esquema, intentaremos crear una técnica generada por el sombreador para él
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