@echo off
rem Build script for Poseidix Commons library (debug)
setlocal EnableDelayedExpansion

rem The "control panel" for the batch script.

set LibName=PoseidixCommons%BuildTarget%
set EchoPfx=[POSEIDIX STUDIO: COMMONS]
set BinDir=Bin
set BldDir=%BuildTarget%
set ObjDir=Obj
set LibDir=Lib
set ObjDirF=%BinDir%\%BldDir%\%ObjDir%
set LibDirF=%BinDir%\%BldDir%\%LibDir%
set SrcDir=Source
set IncDir=Include
set SrcExt=cxx
set ObjExt=obj
set LibExt=lib

rem Internal workings of the script. Avoid touching this unless you know
rem what you're doing.

rem Create the required directories to compile the library.
if not exist %BinDir% mkdir %BinDir%
cd %BinDir%
if not exist %BldDir% mkdir %BldDir%
cd %BldDir%
if not exist %ObjDir% mkdir %ObjDir%
if not exist %LibDir% mkdir %LibDir%
cd ..\..

echo %EchoPfx% Starting build...

rem Include paths.

rem First path is the Poseidix parent path.
rem %IncDir% points to the parent include path.
set Incs=-I%IncDir%
rem We also need to include the Vulkan SDK libraries.
set Incs=!Incs! -I%VULKAN_SDK%\Include

rem Print all flags so far, so we know that this is working.
echo %EchoPfx% Compiler Flags: %ClFlags%
echo %EchoPfx% Include Paths:  %Incs%
echo %EchoPfx% Linker Flags:   %LnkFlags%
echo %EchoPfx% Compiler Defs:  %ClDefs%

echo %EchoPfx%

rem Tell the user that we're building the libary
echo %EchoPfx% Building Poseidix Commons static libary ^(debug build^)...

echo %EchoPfx%

rem Build each source file. This is super inefficient and a better method
rem would be much appreciated but this will work regardless.
for /r %%f in (*.%SrcExt%) do (
        echo %EchoPfx% Building source file:    %%~nxf [absolute path: %%f]
    clang++ -c -o %ObjDirF%\%%~nf.%ObjExt% %%f %ClFlags% %ClDefs% %Incs%
    if %errorlevel% neq 0 (
        echo %EchoPfx% Build failed attempting to compile %%~nxf, terminating.
        exit /b
    ) else (
        echo %EchoPfx% Successfully built file: %%~nxf [absolute path: %%f]
    )
)

echo %EchoPfx%

rem Create a list of object files.
set ObjFiles=

rem Navigate to the object file directory.
cd %ObjDirF%

rem Gather all object files.
for /r %%f in (*.%ObjExt%) do (
    echo %EchoPfx% Found object file: %%~nxf [absolute path: %%f]
    set ObjFiles=!ObjFiles! %%~nxf
)

rem Call the archiver/librarian to link everything into the final libary.
echo %EchoPfx% Linking objects and creating archive...
llvm-ar rc ..\%LibDir%\%LibName%.%LibExt% %ObjFiles%

if %errorlevel% neq 0 (
    echo %EchoPfx% Linking failed, terminating.
    exit /b
) else (
    echo %EchoPfx% Build successful.
)

endlocal
@echo on