//
// Created by Ibaad A. Chaudray on 11/28/22.
//

#include <GLFW/glfw3.h>
#include "Renderer.h"
#include "Log.h"
#include "OpenGL/gl3.h"

Renderer::Renderer(const char* shaderSource) {

    shader = new ShaderUtil(shaderSource);
    shader->compileShader();

    vertices = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f, 1.0f, 0.0f
    };

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size()*(sizeof(float)), vertices.data(), GL_STATIC_DRAW);

    VAO = 0;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3* sizeof(float), (void*)nullptr);




}

void Renderer::render() {

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    LOG_INFO("Begin " + std::to_string(glGetError()));

    glEnableVertexAttribArray(0);
    LOG_INFO("Middle " + std::to_string(glGetError()));
    shader->s_use();

    glDrawArrays(GL_TRIANGLES, 0, 3);
    LOG_INFO("End " + std::to_string(glGetError()));

}
