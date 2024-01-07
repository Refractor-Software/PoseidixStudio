# Poseidix Studio

**Poseidix Studio** is a software suite containing several workstation programs and libaries, initially created to develop video games but usable in many high-performance industries.

## Major Programs
- **Poseidix Engine** - High-performance 3D data-oriented game engine. Targets 160 FPS or higher on ninth-generation consoles.

## Building Poseidix Studio

### Windows
- Install [MSYS2](https://www.msys2.org/) to C:msys64\ (this should be the default path in the installer).
- Install the [MinGW Clang toolset](https://packages.msys2.org/groups/mingw-w64-clang-x86_64-toolchain) from the UCRT64 terminal (the one that opens by default after installation).
- Install the [Vulkan SDK](https://vulkan.lunarg.com/sdk/home). Install the following components when prompted, and nothing more or less:
    - Shader Toolchain Debug Symbols (64-bit)
    - GLM headers
    - SDL2 libraries and headers
    - Volk header, source, and library
    - Vulkan Memory Allocator header
