set CMAKE=.\..\..\cmake\bin\cmake.exe

IF EXIST .\Build rm /s /q .\Build

mkdir .\Build
cd .\Build

%CMAKE% ..\Src -DBUILD_BULLET2_DEMOS:BOOL="0" -DBUILD_CLSOCKET:BOOL="0" -DBUILD_CPU_DEMOS:BOOL="0" -DBUILD_ENET:BOOL="0" -DBUILD_OPENGL3_DEMOS:BOOL="0" -DBUILD_UNIT_TESTS:BOOL="0" -DUSE_MSVC_RUNTIME_LIBRARY_DLL:BOOL="1"
msbuild "BULLET_PHYSICS.sln" /p:configuration=Debug
msbuild "BULLET_PHYSICS.sln" /p:configuration=Release

cd ..