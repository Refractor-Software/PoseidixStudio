# Poseidix Studio

**Poseidix Studio** is a software suite containing several workstation programs and libaries, initially created to develop video games but usable in many high-performance industries.

## Major Programs
- **Poseidix Engine** - High-performance 3D data-oriented game engine. Targets 160 FPS or higher on ninth-generation consoles.

## Building Poseidix Studio
Currently, Poseidix Studio depends quite a bit on the user's environment to function correctly. It's not all plug-and-play, so make sure you read the installation instructions **with madman levels of care and do not mess up ONE SINGLE STEP of the process** for your given platform - otherwise, your code might not compile.

### Windows
**Before you blindly start clicking through installer instructions, make sure you read these notes to know exactly WHERE to install everything. The build system cannot magically find your compiler installation, especially if you pick some crazy wonky installation location, so installing in the right spot is critical to making sure that it can find everything.
- Install the latest build of [LLVM](https://github.com/llvm/llvm-project/releases) for win64. It might take a bit to find it. Your browser might wine about the file not being commonly downloaded, but it is completely safe. Force it to accept the download and run the installer.
    - **Add LLVM to the system path, and add an environment variabled named LLVM which points to the LLVM\bin folder.**
- Install the [Vulkan SDK](https://vulkan.lunarg.com/sdk/home).
    - Install the following components when prompted, and nothing more or less:
        - Shader Toolchain Debug Symbols (64-bit)
        - GLM headers
        - SDL2 libraries and headers
        - Volk header, source, and library
        - Vulkan Memory Allocator header
    - **Ensure that the VULKAN_SDK environment variable exists.**