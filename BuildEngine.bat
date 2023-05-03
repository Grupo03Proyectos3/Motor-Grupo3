
cd .\Dependencies
call BuildDependencies.bat
cd ..

msbuild "MiMotor.sln" /p:configuration=Debug
msbuild "MiMotor.sln" /p:configuration=Release