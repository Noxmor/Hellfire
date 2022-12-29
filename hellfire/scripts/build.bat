@echo off
SetLocal EnableDelayedExpansion

cd ..

if not exist bin mkdir bin

SET FILES= 
for /R %%f in (*.c) do (
	SET FILES=!FILES! %%f
)

SET FLAGS=-Wall -Wextra -O3
SET INCLUDES=-Isrc
SET DEFINES=-DHF_ENABLE_ASSERTS

SET assembly=Hellfire
echo Building %assembly%...
gcc %FILES% %FLAGS% -c -o bin/%assembly%.lib %INCLUDES% %DEFINES%
if %ERRORLEVEL% NEQ 0 (exit /b) else (echo Successfully builded %assembly%!)