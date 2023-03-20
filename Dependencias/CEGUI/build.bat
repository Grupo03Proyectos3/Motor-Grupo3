cd ..
set DEPENDENCIESPATH=%cd%
cd .\cegui\

set CMAKE=.\..\..\cmake\bin\cmake.exe
set CMAKEDEP=.\..\..\..\cmake\bin\cmake.exe
set EXES=.\..\..\..\Exes
set EXESDEP=.\..\..\..\..\..\Exes
set CEGUI_CONFIG_PATH=.\cegui\include\CEGUI\Config.h

IF EXIST .\dependencies\build RMDIR /S /Q .\dependencies\build

mkdir .\dependencies\build
cd .\dependencies\build

%CMAKEDEP% -DCEGUI_BUILD_EXPAT:BOOL="1" -DCEGUI_BUILD_EFFECTS11:BOOL="0" -DCEGUI_BUILD_GLFW:BOOL="0" -DCEGUI_BUILD_SILLY:BOOL="1" ..\
msbuild "CEGUI-DEPS.sln" /p:configuration=Debug
msbuild "CEGUI-DEPS.sln" /p:configuration=Release

mkdir .\..\..\src\dependencies
xcopy /y /s .\dependencies .\..\..\src\dependencies
cd .\..\..

IF EXIST .\Build RMDIR /S /Q .\Build
mkdir .\Build
cd .\Build 
%CMAKE% -DCEGUI_SAMPLES_ENABLED:BOOL="0" -DCEGUI_BUILD_LUA_MODULE:BOOL="0" -DCEGUI_BUILD_LUA_GENERATOR:BOOL="0" -DCEGUI_BUILD_RENDERER_OPENGL3:BOOL="0" -DCEGUI_BUILD_RENDERER_OPENGL:BOOL="0" -DCEGUI_BUILD_XMLPARSER_EXPAT:BOOL="1" -DCEGUI_BUILD_APPLICATION_TEMPLATES:BOOL="0" -DCEGUI_BUILD_RENDERER_OGRE:BOOL="1" -DCEGUI_BUILD_OPENGL:BOOL="0" -DCEGUI_BUILD_IMAGECODEC_SILLY:BOOL="1" -DOGRE_LIB_DBG:FILEPATH="%DEPENDENCIESPATH%\Ogre\Build\lib\Debug\OgreMain_d.lib" -DOGRE_H_PATH:PATH="%DEPENDENCIESPATH%\Ogre\Src\OgreMain\include" -DOGRE_LIB:FILEPATH="%DEPENDENCIESPATH%\Ogre\Build\lib\Release\OgreMain.lib" -DOGRE_H_BUILD_SETTINGS_PATH:PATH="%DEPENDENCIESPATH%\Ogre\Build\include" ..\Src
powershell -command "(gc %CEGUI_CONFIG_PATH%) -replace 'define CEGUI_OGRE_VERSION_MAJOR 0', 'define CEGUI_OGRE_VERSION_MAJOR 1' | Out-File -encoding ASCII %CEGUI_CONFIG_PATH%"
powershell -command "(gc %CEGUI_CONFIG_PATH%) -replace 'define CEGUI_OGRE_VERSION_MINOR 0', 'define CEGUI_OGRE_VERSION_MINOR 13' | Out-File -encoding ASCII %CEGUI_CONFIG_PATH%"
powershell -command "(gc %CEGUI_CONFIG_PATH%) -replace 'define CEGUI_OGRE_VERSION_PATCH 0', 'define CEGUI_OGRE_VERSION_PATCH 6' | Out-File -encoding ASCII %CEGUI_CONFIG_PATH%"

msbuild "cegui.sln" /p:configuration=Release 
msbuild "cegui.sln" /p:configuration=Debug 