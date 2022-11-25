//
// Created by Ibaad A. Chaudray on 11/21/22.
//

#include "Window.h"
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include "iostream"
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
    m_wndw = glfwCreateWindow(400, 400, "Simulation", NULL, NULL);
    glfwFocusWindow(m_wndw);
    glfwMakeContextCurrent(m_wndw);

}

Window::~Window() {
    glfwTerminate();
}

