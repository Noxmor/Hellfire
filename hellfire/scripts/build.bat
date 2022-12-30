@echo off
SetLocal EnableDelayedExpansion

cd ../

if not exist bin mkdir bin
if not exist bin-int mkdir bin-int

SET FILES= 
for /R %%f in (*.c) do (
	SET FILES=!FILES! %%f
)

SET FLAGS=-Wall -Wextra -O3
SET INCLUDES=-I../src
SET DEFINES=-DHF_ENABLE_ASSERTS

SET assembly=Hellfire
echo Building %assembly%...

PUSHD bin-int
gcc %FILES% %FLAGS% -c %INCLUDES% %DEFINES%

SET OBJ_FILES= 
for /R %%f in (*.o) do (
	SET OBJ_FILES=!OBJ_FILES! %%f
)
POPD

ar rcs bin/%assembly%.lib %OBJ_FILES%

if %ERRORLEVEL% NEQ 0 (exit /b) else (echo Successfully built %assembly%!)