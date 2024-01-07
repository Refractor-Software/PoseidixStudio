@echo off
rem Delete existing binaries, forces a full rebuild
rem The extra 'cd' commands are for debugging to ensure we're navigating correctly
setlocal EnableDelayedExpansion

set EchoPrefix=[POSEIDIX STUDIO: COMMONS]
set BinDirName=Bin
set ClrBinMsg=Binaries cleared!
set NoBinMsg=No binaries folder [%BinDirName%] exists. Presumably nothing to delete.

if exist %BinDirName% (
    rmdir /s /q %BinDirName%
    echo %EchoPrefix% %ClrBinMsg%
) else (
    echo %EchoPrefix% %NoBinMsg%
)

endlocal