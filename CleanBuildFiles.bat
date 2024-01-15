@echo off
rem Delete existing binaries, forces a full rebuild
rem Currently this must be either copied to subdirectories or assigned to user PATH
rem and called from the command prompt in the appropriate subdirectories.
rem Soon I'd like to update this to iterate subfolders and work automagically.
setlocal EnableDelayedExpansion

set EchoPrefix=[Build Files Cleaner]
set BinDirName=bin
set ClrBinMsg=Binaries cleared.
set NoBinMsg=No binaries folder [%BinDirName%] exists. Presumably nothing to delete.

if exist %BinDirName% (
    rmdir /s /q %BinDirName%
    echo %EchoPrefix% %ClrBinMsg%
) else (
    echo %EchoPrefix% %NoBinMsg%
)

rem TODO: Add .fdb file support (for cleaning FASTBuild dependency graphs)

endlocal
@echo on