//
// Created by Ibaad A. Chaudray on 9/28/22.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "ShaderUtil.h"
#include "GLFW/glfw3.h"
#include "Log.h"
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <filesystem>
std::string ShaderUtil::asString(const char *string) {
    std::ifstream t(string);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}
void ShaderUtil::asStringtwo() {
    int state = 0;// 0 = look for shader type, 1= vertex, 2=fragment, 3= geometry
    std::ifstream t(file.string());
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::istringstream input(buffer.str());
    input.str(buffer.str());
    for (std::string line; std::getline(input, line);) {
        //std::cout << line << "\n" << std::endl;
        LOG_INFO(line);
        if (line.length() > 0) {
            if (line.length() == 8 && (std::equal(line.begin(), line.end(), "//vertex"))) {
                state = 1;

                continue;
            } else if (std::equal(line.begin(), line.end(), "//fragment\n")) {
                state = 2;
                continue;
            } else if (std::equal(line.begin(), line.end(), "//geometry")) {
                state = 3;
                continue;
            }
        }
        switch (state) {
            case 1:
                vertex.append(line);
                vertex.append("\n");
                break;
            case 2:
                fragment.append(line);
                fragment.append("\n");
                break;
            case 3:
                geometry.append(line);
                geometry.append("\n");
                break;
            default:
                //idk
                break;
        }

    }
    LOG_INFO("Vertex Data");
    LOG_INFO(vertex.data());

}

ShaderUtil::~ShaderUtil() = default;

ShaderUtil::ShaderUtil(const char *filePath)  {
    file = std::filesystem::path(filePath);
    vertex = std::string("");
    fragment = std::string("");
    geometry = std::string("");
    vertexID = glCreateShader(GL_VERTEX_SHADER);
    fragmentID = glCreateShader(GL_VERTEX_SHADER);
    shaderProgram = glCreateProgram();
    asStringtwo();

}

int ShaderUtil::compileShader() {
    auto vertexShaderSource = vertex.c_str();
    glShaderSource(vertexID, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexID);
    int success = 1;
    char infoLog[512];
    glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexID, 512, NULL, infoLog);
        LOG_ERROR(std::string("Vertex failed to compile") + std::string(infoLog));

    }


    auto fragmentShaderSource = fragment.c_str();
    unsigned int fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentID, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentID);

    glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(fragmentID, 512, NULL, infoLog);


        LOG_ERROR(std::string("Fragment failed to compile") + std::string(infoLog));

    }

    glAttachShader(shaderProgram, vertexID);
    glAttachShader(shaderProgram, fragmentID);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        LOG_ERROR("HELP!");
        LOG_ERROR(std::string("Shader Program failed to compile ") + std::string(infoLog));
    }

    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);
    return 0;
}

void ShaderUtil::s_use() {
    glUseProgram(shaderProgram);
}

void ShaderUtil::uploadMat4(const char* uniform, glm::mat4 Matrix) {
    unsigned int transformLoc = glGetUniformLocation(shaderProgram, uniform);
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(((Matrix))));


}

void ShaderUtil::uploadVec3(const char* uniform, GLfloat* value) {
    unsigned int transformLoc = glGetUniformLocation(shaderProgram, uniform);
    glUniform3fv(transformLoc, 1, value);
}

void ShaderUtil::uploadVec2(const char* uniform, GLfloat* value) {
    unsigned int transformLoc = glGetUniformLocation(shaderProgram, uniform);
    glUniform2fv(transformLoc, 1, value);
}


