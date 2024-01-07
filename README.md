# Poseidix Studio

**Poseidix Studio** is a software suite containing several workstation programs and libaries, initially created to develop video games but usable in many high-performance industries.

## Major Programs
- **Poseidix Engine** - High-performance 3D data-oriented game engine. Targets 160 FPS or higher on ninth-generation consoles.

## Building Poseidix Studio

### Windows
- Install [MSYS2](https://www.msys2.org/) to the `Vendor/MSYS2` directory (if the directory does not exist yet, which it probably won't, create it; it is gitignored for a reason). **It is critical that you install to this directory,
because FASTBuild scripts check here for build tools to avoid depending on the environment.
- Install the [MinGW Clang toolset](https://packages.msys2.org/base/mingw-w64-clang)
