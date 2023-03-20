set EXES=.\..\..\..\Exes
IF EXIST .\Build RMDIR /S /Q .\Build

mkdir .\Build

msbuild "lua.sln" /p:configuration=Debug
msbuild "lua.sln" /p:configuration=Release

cd .\Build

XCOPY /y /s .\lua_d.dll %EXES%
XCOPY /y /s .\lua.dll %EXES%

cd..