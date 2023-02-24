cd Dependencias
cd Ogre

mkdir Build
cd Build

cmake -G "Visual Studio 17 2022" -A x64 -S ../Src -DOGRE_BUILD_COMPONENT_BITES=ON -DOGRE_BUILD_RENDERSYSTEM_D3D9=OFF
msbuild  Ogre.sln /p:Configuration=Debug
msbuild  Ogre.sln /p:Configuration=Release

copy .\bin\release\OgreBites.dll .\..\..\..\Exes
copy .\bin\debug\OgreBites_d.dll .\..\..\..\Exes

copy .\bin\release\OgreMain.dll .\..\..\..\Exes
copy .\bin\debug\OgreMain_d.dll .\..\..\..\Exes

copy .\bin\release\Codec_STBI.dll .\..\..\..\Exes
copy .\bin\debug\Codec_STBI_d.dll .\..\..\..\Exes

copy .\bin\release\OgreOverlay.dll .\..\..\..\Exes
copy .\bin\debug\OgreOverlay_d.dll .\..\..\..\Exes

copy .\bin\release\OgreRTShaderSystem.dll .\..\..\..\Exes
copy .\bin\debug\OgreRTShaderSystem_d.dll .\..\..\..\Exes

copy .\bin\release\RenderSystem_Direct3D11.dll .\..\..\..\Exes
copy .\bin\debug\RenderSystem_Direct3D11_d.dll .\..\..\..\Exes

copy .\bin\release\OgreBullet.dll .\..\..\..\Exes

copy .\bin\release\zlib.dll .\..\..\..\Exes
copy .\bin\release\SDL2.dll .\..\..\..\Exes