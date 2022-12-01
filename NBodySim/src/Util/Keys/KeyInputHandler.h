//
// Created by Ibaad A. Chaudray on 12/1/22.
//

#pragma once


#include <GLFW/glfw3.h>

class KeyInputHandler {
public:
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    inline static bool getKeyPressed(int key) {
        return keyInput[key];
    }
private:
    static bool keyInput[350];
};
