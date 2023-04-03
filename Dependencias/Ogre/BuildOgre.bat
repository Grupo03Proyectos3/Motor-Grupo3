set CMAKE=.\..\..\cmake\bin\cmake.exe
set EXES=.\..\..\..\Exes

IF EXIST .\Build RMDIR /S /Q .\Build

mkdir .\Build
cd .\Build

%CMAKE% ..\Src -DOGRE_BUILD_COMPONENT_BITES=ON -DOGRE_BUILD_RENDERSYSTEM_D3D9=OFF -DOGRE_BIULD_PLUGIN_DOT_SCENE=OFF
msbuild  Ogre.sln /p:Configuration=Debug
msbuild  Ogre.sln /p:Configuration=Release

msbuild "OGRE.sln" /p:configuration=Debug
msbuild "OGRE.sln" /p:configuration=Release

:: Copia de DLLs a Exes 
XCOPY /y /s .\bin\release\OgreBites.dll %EXES%
XCOPY /y /s .\bin\debug\OgreBites_d.dll %EXES%

XCOPY /y /s .\bin\release\OgreMain.dll %EXES%
XCOPY /y /s .\bin\debug\OgreMain_d.dll %EXES%

XCOPY /y /s .\bin\release\Codec_STBI.dll %EXES%
XCOPY /y /s .\bin\debug\Codec_STBI_d.dll %EXES%

XCOPY /y /s .\bin\release\OgreOverlay.dll %EXES%
XCOPY /y /s .\bin\debug\OgreOverlay_d.dll %EXES%

XCOPY /y /s .\bin\release\OgreRTShaderSystem.dll %EXES%
XCOPY /y /s .\bin\debug\OgreRTShaderSystem_d.dll %EXES%

::XCOPY /y /s .\bin\release\RenderSystem_Direct3D11.dll %EXES%
::XCOPY /y /s .\bin\debug\RenderSystem_Direct3D11_d.dll %EXES%

XCOPY /y /s .\bin\release\RenderSystem_GL.dll %EXES%
XCOPY /y /s .\bin\debug\RenderSystem_GL_d.dll %EXES%

XCOPY /y /s .\bin\release\Plugin_ParticleFX.dll %EXES%
XCOPY /y /s .\bin\debug\Plugin_ParticleFX_d.dll %EXES%

XCOPY /y /s .\bin\release\OgreBullet.dll %EXES%

XCOPY /y /s .\bin\release\zlib.dll %EXES%
:: XCOPY /y /s .\bin\release\SDL2.dll %EXES%

:: BUILD SDL2

cd .\SDL2-build
msbuild  SDL2.sln /p:Configuration=Debug
msbuild  SDL2.sln /p:Configuration=Release

XCOPY /y /s .\Release\SDL2.dll .\..\..\..\..\Exes
XCOPY /y /s .\Debug\SDL2d.dll .\..\..\..\..\Exes

cd ..
cd ..