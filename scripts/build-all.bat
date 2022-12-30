@echo off

SetLocal

echo Building all...

cd ../

PUSHD hellfire
PUSHD scripts
CALL build.bat
POPD
POPD
if %ERRORLEVEL% NEQ 0 (exit /b)

PUSHD editor
PUSHD scripts
call build.bat
POPD
POPD
if %ERRORLEVEL% NEQ 0 (exit /b)

echo Successfully built all assemblies!