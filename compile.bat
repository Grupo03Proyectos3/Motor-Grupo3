cd Dependencias
cd Ogre

mkdir Build
cd Build

cmake -G "Visual Studio 17 2022" -A x64 -S ../Src -DOGRE_BUILD_COMPONENT_BITES=OFF -DOGRE_BUILD_RENDERSYSTEM_D3D9=OFF
msbuild  Ogre.sln /p:Configuration=Debug
msbuild  Ogre.sln /p:Configuration=Release