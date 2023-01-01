//
// Created by Ibaad A. Chaudray on 11/20/22.
//

#include "Application.h"
#include "Window.h"
#include "Util/Input/KeyInputHandler.h"
#include "Util/Render/Renderer.h"


Application::Application() {
    m_window = new Window();
    m_window->setWindowHint(GLFW_VERSION_MAJOR, 4);
    m_window->setWindowHint(GLFW_VERSION_MINOR, 1);
    m_window->start();
    LOG_INFO("Application Initialized");

}

Application::~Application() {
    delete m_window;
}

void Application::run() {
    

    auto renderer = Renderer("../assets/default.glsl");


    while (!m_window->windowShouldClose()) {
        if (KeyInputHandler::getKeyPressed(GLFW_KEY_E)) {
            m_window->closeWindow();
        }
        m_window->update();
        renderer.render();
    }
}
