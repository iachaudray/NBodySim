cmake_minimum_required(VERSION 3.23)
project(NBodySimulation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "ON")

add_executable(NBodySimulation src/EntryPoint.cpp src/Core.h src/Application.cpp src/Application.h src/Window.cpp src/Window.h src/Log.cpp src/Log.h src/Util/Render/Renderer.cpp src/Util/Render/Renderer.h src/Util/Render/ShaderUtil.cpp src/Util/Render/ShaderUtil.h src/Util/Input/KeyInputHandler.cpp src/Util/Input/KeyInputHandler.h src/Util/Render/Camera.cpp src/Util/Render/Camera.h)
target_include_directories(NBodySimulation PRIVATE include/)
target_include_directories(NBodySimulation PRIVATE src/)
find_package(glfw3 3.3 REQUIRED)
target_link_libraries(NBodySimulation glfw)
find_package(OpenGL REQUIRED)
find_package(spdlog REQUIRED)
target_link_libraries(NBodySimulation spdlog::spdlog)
target_link_libraries(NBodySimulation OpenGL::GL)


