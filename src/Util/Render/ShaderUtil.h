//
// Created by Ibaad A. Chaudray on 9/28/22.
//
#pragma once
#include <cstdio>
#include <filesystem>
#include <GLFW/glfw3.h>
#include "include/glm/detail/type_mat4x4.hpp"

class ShaderUtil {
public:
    std::filesystem::path file;
    std::string vertex;
    std::string fragment;
    std::string geometry;
    unsigned int fragmentID;
    unsigned int vertexID;
    unsigned int shaderProgram;
    explicit ShaderUtil(const char *filePath);

    virtual ~ShaderUtil();

    static std::string asString(const char* string);


    int compileShader();
    //static int compileShader(const char* filePath);
    void s_use();

    void uploadMat4(const char* uniform, glm::mat4 Matrix);
    void uploadVec3(const char* uniform, GLfloat* value);
    void uploadVec2(const char* uniform, GLfloat* value);

private:
    void asStringtwo();




};
