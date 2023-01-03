//
// Created by Ibaad A. Chaudray on 11/20/22.
//

#include "Application.h"
#include "Window.h"
#include "Util/Input/KeyInputHandler.h"
#include "Util/Render/Renderer.h"
#include "include/imgui/backends/imgui_impl_glfw.h"
#include "include/imgui/backends/imgui_impl_opengl3.h"
#include "include/imgui/imconfig.h"
#include "include/imgui/imgui.h"

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
        ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::Begin("Demo window");
    ImGui::ColorPicker3("Color Picker", new float[3]{256, 256, 256});
    ImGui::Button("Hello!");
    ImGui::End();

    // Render dear imgui into screen
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
}
