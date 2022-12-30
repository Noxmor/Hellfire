@echo off
SetLocal EnableDelayedExpansion

cd ../

if not exist bin mkdir bin
if not exist bin-int mkdir bin-int

SET LIB_PATH=../hellfire/bin/

SET FILES= 
for /R %%f in (*.c) do (
	SET FILES=!FILES! %%f
)

SET FLAGS=-Wall -Wextra -O3
SET INCLUDES=-I../src -I../../hellfire/src/
SET DEFINES=-DHF_ENABLE_ASSERTS
SET LINKS=-L%LIB_PATH% -lHellfire

SET assembly=Hellfire-Editor
echo Building %assembly%...

PUSHD bin-int
gcc %FILES% %FLAGS% -c %INCLUDES% %DEFINES% %LINKS%

SET OBJ_FILES= 
for /R %%f in (*.o) do (
	SET OBJ_FILES=!OBJ_FILES! %%f
)
POPD

gcc %OBJ_FILES% -o bin/%assembly%.exe %INCLUDES% %DEFINES% %LINKS%

if %ERRORLEVEL% NEQ 0 (exit /b) else (echo Successfully builded %assembly%!)