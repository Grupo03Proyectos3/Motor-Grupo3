
cd .\Dependencias
call BuildDependencies.bat

msbuild "MiMotor.sln" /p:configuration=Debug
msbuild "MiMotor.sln" /p:configuration=Release