//
// Created by Ibaad A. Chaudray on 11/20/22.
//

#pragma once
#include "Window.h"
#include "Log.h"
class Application {
public:
    Application();
    ~Application();
    void run();
private:
    Window* m_window;
};
