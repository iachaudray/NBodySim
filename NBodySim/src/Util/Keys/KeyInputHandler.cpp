//
// Created by Ibaad A. Chaudray on 12/1/22.
//

#include "KeyInputHandler.h"

void KeyInputHandler::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        keyInput[key] = true;
    } else if (action == GLFW_RELEASE) {
        keyInput[key] = false;
    }
}

bool KeyInputHandler::keyInput[350] = {false};