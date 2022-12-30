//
// Created by Ibaad A. Chaudray on 11/28/22.
//

#pragma once
#include "string"
#include "ShaderUtil.h"
#include <vector>

class Renderer {
public:
    explicit Renderer(const char* shaderSource);
    void render();
private:
    float x;
    ShaderUtil* shader;
    std::vector<float> vertices;
    std::vector<unsigned int> elements;
    unsigned int VBO{};
    unsigned int VAO;
    unsigned int EBO;
    int error{};
    glm::mat4 model;
};
