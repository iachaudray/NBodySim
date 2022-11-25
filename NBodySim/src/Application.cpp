//
// Created by Ibaad A. Chaudray on 11/20/22.
//

#include "Application.h"
#include "Window.h"
Application::Application() {
    m_window = new Window();
    m_window->setWindowHint(GLFW_VERSION_MAJOR, 4);
    m_window->setWindowHint(GLFW_VERSION_MINOR, 1);
}

Application::~Application() {
    delete m_window;
}

void Application::run() {

    m_window->start();

    while (!m_window->windowShouldClose()) {

        m_window->update();
    }
    return;
}
