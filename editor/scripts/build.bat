@echo off
SetLocal EnableDelayedExpansion

cd ..

if not exist bin mkdir bin

SET LIB_PATH=../hellfire/bin/

SET FILES= 
for /R %%f in (*.c) do (
	SET FILES=!FILES! %%f
)

SET FLAGS=-Wall -Wextra -O3
SET INCLUDES=-Isrc -I../hellfire/src/
SET DEFINES=-DHF_ENABLE_ASSERTS
SET LINKS=-L%LIB_PATH% -lHellfire

SET assembly=editor
echo Building %assembly%...
gcc %FILES% %FLAGS% -o bin/%assembly%.exe %INCLUDES% %DEFINES% -static %LINKS%
if %ERRORLEVEL% NEQ 0 (exit /b) else (echo Successfully builded %assembly%!)