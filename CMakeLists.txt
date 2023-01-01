cmake_minimum_required(VERSION 3.23)
project(NBodySimulation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "ON")
file(GLOB IM_GUI ${PROJECT_SOURCE_DIR}/include/imgui/*.cpp)

add_executable(NBodySimulation src/Entrypoint.cpp src/Application.cpp src/Application.h src/Window.cpp src/Log.cpp src/Log.h
    src/Util/Render/Renderer.cpp src/Util/Render/ShaderUtil.cpp src/Util/Input/KeyInputHandler.cpp src/Util/Render/Camera.cpp
     include/imgui/backends/imgui_impl_opengl3.cpp include/imgui/backends/imgui_impl_glfw.cpp ${IM_GUI})
target_include_directories(NBodySimulation PRIVATE include/imgui)
target_include_directories(NBodySimulation PRIVATE src/)
target_include_directories(NBodySimulation PRIVATE ${PROJECT_SOURCE_DIR})
# Disable building extras we won't need (pure C++ project)

find_package(glfw3 3.3 REQUIRED)
target_link_libraries(NBodySimulation glfw)
find_package(OpenGL REQUIRED)
find_package(spdlog REQUIRED)
target_link_libraries(NBodySimulation spdlog::spdlog OpenGL::GL)
