//
// Created by Ibaad A. Chaudray on 12/8/22.
//

#pragma once
#include "include/glm/glm.hpp"
#include "include/glm/ext/matrix_transform.hpp"

class Camera {
public:
    Camera();
    void getMatrix();
    constexpr const static glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    static void getProj();
    static glm::mat4 getModel();
    constexpr static glm::mat4 model = (glm::mat4(1.0f));
private:
    glm::vec3 position;
    glm::vec3 direction;
    glm::vec3 target;


    void update();


};
