# Poseidix Studio

**Poseidix Studio** is a software suite containing several workstation programs and libaries, initially created to develop video games but usable in many high-performance industries.

## Major Programs
- **Poseidix Engine** - High-performance 3D data-oriented game engine. Targets 160 FPS or higher on ninth-generation consoles.

# Building Poseidix Studio
Currently, Poseidix Studio depends quite a bit on the user's environment to function correctly. It's not all plug-and-play, so make sure you read the installation instructions **with madman levels of care and do not mess up ONE SINGLE STEP of the process** for your given platform - otherwise, your code might not compile.

For build instructions, you check the Wiki and follow the Setup instructions for your platforms.

## Windows
**Before you blindly start clicking through installer instructions, make sure you read these notes to know exactly WHERE to install everything. The build system cannot magically find your compiler installation, especially if you pick some crazy wonky installation location, so installing in the right spot is critical to making sure that it can find everything.**

### Installing tools

- If you haven't already, install the [MSVC Build Tools](https://visualstudio.microsoft.com/downloads/?q=build+tools#build-tools-for-visual-studio-2022). If you already have an installation of Visual Studio (Community, etc), you can skip this step, as that installation will come with the build tools.
    - Make sure you know where MSVC is installed, because you will need to set the path up in a moment.
    - Be sure to install the latest Windows SDK as well.
- Install the [Vulkan SDK](https://vulkan.lunarg.com/sdk/home).
    - Install the following components when prompted, and nothing more or less:
        - Shader Toolchain Debug Symbols (64-bit)
        - GLM headers
        - SDL2 libraries and headers
        - Volk header, source, and library
        - Vulkan Memory Allocator header
    - **Ensure that the VULKAN_SDK environment variable exists.**

### Configuring environment variables

Next, you'll need to create environment variables for MSVC, the Windows SDK include path, and the Windows SDK libraries.

**Note that anything inside % signs (e.g. %INSTALL_PATH%) is a template variable and should be replaced with the applicable value.**

### For MSVC

Path: **`%INSTALL_PATH%\VC\Tools\MSVC\%INSTALLED_VER%`**

**Example:** If I installed MSVC v143 (the latest at the time of writing) to `C:\MSVC`, my `%INSTALL_PATH%` would be `C:\MSVC` and my `%INSTALLED_VER%` is `14.38.33130`. The final path in my example is **`C:\MSVC\VC\Tools\MSVC\14.38.33130`**.

### For Windows SDK

Lib Path: **%INSTALL_PATH%\%VER%\Lib

(work in progress)