//
// Created by Ibaad A. Chaudray on 11/20/22.
//

#include "Application.h"
#include "Window.h"
#include "Util/Keys/KeyInputHandler.h"
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
        if (KeyInputHandler::getKeyPressed(GLFW_KEY_E)) {
            m_window->closeWindow();
        }
        m_window->update();
    }
}
