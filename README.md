# SofaRaylib

SOFA plugin containing a SOFA GUI based on Raylib.

# Build Instructions

As any SOFA plugin, follow the instructions on the [SOFA documentation website](https://www.sofa-framework.org/community/doc/plugins/build-a-plugin-from-sources/)

# Dependencies

The plugin is based on [raylib](https://www.raylib.com/). If it cannot be found, the library is fetched and built 
automatically, including all its dependencies.

Limitation: since raylib uses glfw, SofaRaylib and SofaGLFW cannot both be configured into the same solution. This is 
because both plugins create the target `glfw`.

# Status

INCOMPLETE

## To do

- Implement all the functions in `DrawToolRaylib`
- Implement a component similar to `OglModel`
- Fix CMake install error
- Control of the camera
- Draw triangles on both sides
