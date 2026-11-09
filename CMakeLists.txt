cmake_minimum_required(VERSION 3.10)
project(DyslexiaOverlay)

set(CMAKE_CXX_STANDARD 17)

add_executable(DyslexiaOverlay WIN32 main.cpp)
target_link_libraries(DyslexiaOverlay user32 gdi32)