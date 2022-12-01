//
// Created by Ibaad A. Chaudray on 11/21/22.
//

#include "Window.h"
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include "iostream"
#include "Log.h"
#include "Util/Keys/KeyInputHandler.h"
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
    glfwSetKeyCallback(m_wndw, KeyInputHandler::key_callback);
    glfwFocusWindow(m_wndw);
    glfwMakeContextCurrent(m_wndw);
    LOG_INFO("Created window");
}

Window::~Window() {
    glfwTerminate();
}

void Window::closeWindow() {
    glfwSetWindowShouldClose(m_wndw, GLFW_TRUE);
}

