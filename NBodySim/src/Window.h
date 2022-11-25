//
// Created by Ibaad A. Chaudray on 11/21/22.
//

#pragma once
#include <memory>
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>

class Window {

public:
    void setWindowHint(int WindowHint, int Value);

    Window();
    void update();
    void start();

    virtual ~Window();
    inline bool windowShouldClose() { return glfwWindowShouldClose(m_wndw);};
    static bool isGlfwInitialized;
private:
    GLFWwindow* m_wndw{};

};
