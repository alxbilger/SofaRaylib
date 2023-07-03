cmake_minimum_required(VERSION 3.12)
project(SofaRaylib VERSION 1.0 LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(Sofa.Core REQUIRED)
sofa_find_package(Sofa.GUI.Common REQUIRED)

set(RAYLIB_VERSION 4.2.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

# List all files
set(SOFARAYLIB_SRC_DIR src/${PROJECT_NAME})
set(HEADER_FILES
    ${SOFARAYLIB_SRC_DIR}/config.h.in
    ${SOFARAYLIB_SRC_DIR}/RaylibGUI.h
    ${SOFARAYLIB_SRC_DIR}/RaylibWrapper.h
    ${SOFARAYLIB_SRC_DIR}/DrawToolRaylib.h
)
set(SOURCE_FILES
    ${SOFARAYLIB_SRC_DIR}/init.cpp
    ${SOFARAYLIB_SRC_DIR}/RaylibGUI.cpp
    ${SOFARAYLIB_SRC_DIR}/RaylibWrapper.cpp
    ${SOFARAYLIB_SRC_DIR}/DrawToolRaylib.cpp
)
set(README_FILES
    README.md
)

# Create the plugin library.
add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${README_FILES})

# Link the plugin library to its dependency(ies).
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Core)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.GUI.Common)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

# Create package Config, Version & Target files.
# Deploy the headers, resources, scenes & examples.
# Set the plugin 'relocatable' if built within SOFA.
# --> see SofaMacros.cmake
sofa_create_package_with_targets(
    PACKAGE_NAME ${PROJECT_NAME}
    PACKAGE_VERSION ${PROJECT_VERSION}
    TARGETS ${PROJECT_NAME} AUTO_SET_TARGET_PROPERTIES
    INCLUDE_SOURCE_DIR "src"
    INCLUDE_INSTALL_DIR ${PROJECT_NAME}
    RELOCATABLE "plugins"
)
