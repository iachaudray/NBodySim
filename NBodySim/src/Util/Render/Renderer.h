//
// Created by Ibaad A. Chaudray on 11/28/22.
//

#pragma once
#include "string"
#include "Util/ShaderUtil.h"
#include <vector>

class Renderer {
public:
    explicit Renderer(const char* shaderSource);
    void render();
private:

    ShaderUtil* shader;
    std::vector<float> vertices;
    unsigned int VBO;
    unsigned int VAO;
    int error;
};
