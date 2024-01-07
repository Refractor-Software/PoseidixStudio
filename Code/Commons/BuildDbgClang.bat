@echo off
rem Calls down to BuildMain.bat with the target set to Dbg.
setlocal EnableDelayedExpansion


rem Build target. In this case it's Dbg (debug).
set BuildTarget=Dbg
rem C++ standard to use.
set CxxStd=20

rem Basic compiler flags.

rem -static tells the compiler to build for static library. (May not be necessary though.)
set ClFlags=
rem -Oz is optimization for size and speed.
set ClFlags=!ClFlags! -Oz
rem -Wall enables all warnings.
set ClFlags=!ClFlags! -Wall
rem -Werror marks all warnings as errors to ensure everything is caught.
set ClFlags=!ClFlags! -Werror
rem --std=c++%CxxStd% sets the C++ standard to the value of %CxxStd%.
set ClFlags=!ClFlags! --std=c++%CxxStd%
rem -ffast-math enables fast floating-point math
set ClFlags=!ClFlags! -ffast-math

rem Linker options.

rem On Windows we need to link against the Windows SDK libraries. NOTE: Currently broken for some reason.
set LnkFlags=-luser32
rem We also need to link to Vulkan.
set LnkFlags=!LnkFlags! -lvulkan-1
set LnkFlags=!LnkFlags! -L%VULKAN_SDK%\Lib

rem Any remaining macro definitions will go here.
rem Right now this doesn't do anything.

set ClDefs=

call BuildMain.bat

endlocal
@echo on