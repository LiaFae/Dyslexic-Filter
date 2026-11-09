@echo off
echo Creating build directory...
mkdir build
cd build

echo Compiling with CMake...
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release

echo.
echo Done! The executable is located in the build folder.
pause