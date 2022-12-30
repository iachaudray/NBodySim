//
// Created by Ibaad A. Chaudray on 11/21/22.
//

#include "Window.h"
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include "iostream"
#include "Log.h"
#include "Util/Input/KeyInputHandler.h"
bool Window::isGlfwInitialized = false;
void Window::setWindowHint(int WindowHint, int Value) {
    glfwWindowHint(WindowHint, Value);
}

Window::Window() {

    if (!Window::isGlfwInitialized) {
        glfwInit();
        Window::isGlfwInitialized = true;
    }
    glfwDefaultWindowHints();
}

void Window::update() {
    glfwPollEvents();
    glfwSwapBuffers(m_wndw);
    glClearColor(1.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::start() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
    m_wndw = glfwCreateWindow(400, 400, "Simulation", NULL, NULL);
    glfwSetKeyCallback(m_wndw, KeyInputHandler::key_callback);
    glfwFocusWindow(m_wndw);
    glfwMakeContextCurrent(m_wndw);

    LOG_INFO("Window Created");

}

Window::~Window() {
    glfwTerminate();
}

void Window::closeWindow() {
    glfwSetWindowShouldClose(m_wndw, GLFW_TRUE);
}

