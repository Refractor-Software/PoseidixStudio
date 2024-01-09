@echo off
rem Delete existing binaries, forces a full rebuild
rem The extra 'cd' commands are for debugging to ensure we're navigating correctly.
setlocal EnableDelayedExpansion

set EchoPrefix=[CommonLib]
set BinDirName=Bin
set ObjDirName=Intermediate
set ClrObjMsg=Intermediate objects cleared.
set ClrBinMsg=Binaries cleared.
set NoObjMsg=No intermediate objects folder [%ObjDirName%] exists. Presumably nothing to delete.
set NoBinMsg=No binaries folder [%BinDirName%] exists. Presumably nothing to delete.

if exist %ObjDirName% (
    rmdir /s /q %ObjDirName%
    echo %EchoPrefix% %ClrObjMsg%
) else (
    echo %EchoPrefix% %NoObjMsg%
)

if exist %BinDirName% (
    rmdir /s /q %BinDirName%
    echo %EchoPrefix% %ClrBinMsg%
) else (
    echo %EchoPrefix% %NoBinMsg%
)

endlocal
@echo on