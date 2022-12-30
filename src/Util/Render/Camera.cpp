//
// Created by Ibaad A. Chaudray on 12/8/22.
//

#include "Util/Render/Camera.h"
#include "glm/glm.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include <GLFW/glfw3.h>
Camera::Camera() {

    position = glm::vec3(-1, 0, 0);
    target = glm::vec3(0, 0, 0);
    direction = glm::normalize(position - target);
    glm::vec3 cameraRight = glm::normalize(glm::cross(up, direction));
    glm::mat4 view = glm::lookAt(position, direction, up);
    glm::mat4 proj = glm::perspective(glm::radians(45.0f), 1440.0f/ 900.0f, 0.1f, 1000.0f);
}
void Camera::update() {
    glm::vec3 cameraRight = glm::normalize(glm::cross(up, direction));
    glm::mat4 view = glm::lookAt(position, direction, up);
}
 glm::mat4 Camera::getModel() {
    glm::mat4 models = glm::mat4(1.0f);
    models = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0, 0.0, 1.0));
    return models;
}
void Camera::getMatrix() {

}

void Camera::getProj() {
    
    glm::mat4 proj = glm::perspective(1.0f, 1440.0f/900.0f, 0.01f, 1000.0f);

}
