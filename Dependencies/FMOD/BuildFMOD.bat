set EXES=.\..\..\..\..\..\..\Exes

cd .\api\core\libs\x64

XCOPY /y /s .\fmod.dll %EXES%
XCOPY /y /s .\fmodL.dll %EXES%

XCOPY /y /s .\fmodstudio.dll %EXES%
XCOPY /y /s .\fmodstudioL.dll %EXES%

XCOPY /y /s .\fsbank.dll %EXES%
XCOPY /y /s .\libfsbvorbis64.dll %EXES%
XCOPY /y /s .\opus.dll %EXES%

cd .\..\..\..\..

