
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
%CMAKE% -DCEGUI_SAMPLES_ENABLED:BOOL="0" -DCEGUI_BUILD_XMLPARSER_EXPAT:BOOL="1" -DCEGUI_BUILD_APPLICATION_TEMPLATES:BOOL="0" -DCEGUI_BUILD_RENDERER_OGRE:BOOL="1" -DCEGUI_BUILD_OPENGL:BOOL="0" -DCEGUI_BUILD_IMAGECODEC_SILLY:BOOL="1" -DOGRE_LIB_DBG:FILEPATH="%DEPENDENCIESPATH%\Ogre\Build\lib\Debug\OgreMain_d.lib" -DOGRE_H_PATH:PATH="%DEPENDENCIESPATH%\Ogre\Src\OgreMain\include" -DOGRE_LIB:FILEPATH="%DEPENDENCIESPATH%\Ogre\Build\lib\Release\OgreMain.lib" -DOGRE_H_BUILD_SETTINGS_PATH:PATH="%DEPENDENCIESPATH%\Ogre\Build\include" ..\Src
powershell -command "(gc %CEGUI_CONFIG_PATH%) -replace 'define CEGUI_OGRE_VERSION_MAJOR 0', 'define CEGUI_OGRE_VERSION_MAJOR 1' | Out-File -encoding ASCII %CEGUI_CONFIG_PATH%"
powershell -command "(gc %CEGUI_CONFIG_PATH%) -replace 'define CEGUI_OGRE_VERSION_MINOR 0', 'define CEGUI_OGRE_VERSION_MINOR 13' | Out-File -encoding ASCII %CEGUI_CONFIG_PATH%"
powershell -command "(gc %CEGUI_CONFIG_PATH%) -replace 'define CEGUI_OGRE_VERSION_PATCH 0', 'define CEGUI_OGRE_VERSION_PATCH 3' | Out-File -encoding ASCII %CEGUI_CONFIG_PATH%"

msbuild "cegui.sln" /p:configuration=Release 
msbuild "cegui.sln" /p:configuration=Debug 



cd .\bin

xcopy /y /s .\CEGUIBase-0.dll %EXES%
xcopy /y /s .\CEGUIBase-0_d.dll %EXES%

xcopy /y /s .\CEGUIExpatParser.dll %EXES%
xcopy /y /s .\CEGUIExpatParser_d.dll %EXES%

xcopy /y /s .\CEGUIOgreRenderer-0.dll %EXES%
xcopy /y /s .\CEGUIOgreRenderer-0_d.dll %EXES%

xcopy /y /s .\CEGUICoreWindowRendererSet.dll %EXES%
xcopy /y /s .\CEGUICoreWindowRendererSet_d.dll %EXES%

cd ..\..\Src\dependencies\bin
xcopy /y /s .\freetype_d.dll %EXESDEP%
xcopy /y /s .\freetype.dll %EXESDEP%

xcopy /y /s .\glew.dll %EXESDEP%
xcopy /y /s .\glew_d.dll %EXESDEP%

xcopy /y /s .\jpeg.dll %EXESDEP%
xcopy /y /s .\jpeg_d.dll %EXESDEP%

xcopy /y /s .\expat.dll %EXESDEP%
xcopy /y /s .\expat_d.dll %EXESDEP%

xcopy /y /s .\pcre.dll %EXESDEP%
xcopy /y /s .\pcre_d.dll %EXESDEP%

cd %DEPENDENCIESPATH%\..\..\