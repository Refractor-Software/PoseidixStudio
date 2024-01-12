@echo off
rem Delete existing binaries, forces a full rebuild
setlocal EnableDelayedExpansion

set EchoPrefix=[Binaries Clearer]
set BinDirName=bin
set ClrBinMsg=Binaries cleared.
set NoBinMsg=No binaries folder [%BinDirName%] exists. Presumably nothing to delete.

if exist %BinDirName% (
    rmdir /s /q %BinDirName%
    echo %EchoPrefix% %ClrBinMsg%
) else (
    echo %EchoPrefix% %NoBinMsg%
)

endlocal
@echo on