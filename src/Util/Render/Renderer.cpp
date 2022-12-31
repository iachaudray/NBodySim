//
// Created by Ibaad A. Chaudray on 11/28/22.
//

#include <GLFW/glfw3.h>
#include "Renderer.h"
#include "../../Log.h"
#include "OpenGL/gl3.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Camera.h"
#include "glm/gtx/string_cast.hpp"
Renderer::Renderer(const char* shaderSource) {

    shader = new ShaderUtil(shaderSource);
    shader->compileShader();

    vertices = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.5f, 0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f
    };
    elements = {
            2, 1, 0, 2, 0, 3
    };
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*(sizeof(float)), vertices.data(), GL_STATIC_DRAW);
    VAO = 0;
   glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3* sizeof(float), (void*)nullptr);
    EBO = 0;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements.size()*(sizeof(unsigned int)), elements.data(), GL_STATIC_DRAW);

    x=0.0f;
    model = Camera::getModel();
    model = glm::translate(model, glm::vec3(0.5f, -0.5f, 0.0f));
}
unsigned int error;
void Renderer::render() {
    x+=0.003f;
    glm::vec3 colors(x, 0.4f, 1.0f);
    shader->uploadVec3("color", glm::value_ptr(colors));
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    model = glm::rotate(model, glm::radians(1.0f), glm::vec3(0.0, 0.0, 1.0));

    shader->uploadMat4("projection", model);

    glEnableVertexAttribArray(0);
    shader->s_use();

    glDrawElements(GL_TRIANGLES, elements.size(), GL_UNSIGNED_INT, 0);
    
}
