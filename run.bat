@echo off

cmake -B build -G "MinGW Makefiles"
cmake --build build

@echo %errorlevel%

if %errorlevel% neq 0 (
    echo Error on build.
    exit /b 1
)

echo .

.\build\Renderer.exe

