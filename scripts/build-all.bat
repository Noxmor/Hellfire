@echo off

echo Building all...

cd ..

PUSHD hellfire
CALL build.bat
POPD
if %ERRORLEVEL% NEQ 0 (exit /b)

PUSHD editor
call build.bat
POPD
if %ERRORLEVEL% NEQ 0 (exit /b)

echo Successfully builded all assemblies!