# Dyslexic Filter 📖

**Dyslexic Filter** is a lightweight, Windows desktop application written in C++ that adds a subtle tint overlay over your entire screen. It is designed to assist individuals with dyslexia and Visual Stress (Meares-Irlen syndrome) by reducing screen glare and contrast.

## Features
- **Click-Through:** The filter stays on top of all windows without interfering with mouse clicks, scrolling, or typing.
- **Ultra Lightweight:** Built using native Win32 API with zero external dependencies.
- **Easy Exit:** Simply press `Esc` to close the overlay.

## How to Build

### Requirements
- C++ Compiler (MSVC, MinGW, or Clang)
- CMake (version 3.10 or higher)

### Building via CMake
```bash
mkdir build
cd build
cmake ..
cmake --build .