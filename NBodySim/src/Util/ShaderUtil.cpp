//
// Created by Ibaad A. Chaudray on 9/28/22.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "ShaderUtil.h"
#include "glfw/glfw3.h"
#include "../Log.h"
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
    std::istringstream input;
    input.str(buffer.str());

    for (std::string line; std::getline(input, line);) {
        //std::cout << line << "\n" << std::endl;
        if (std::equal(line.begin(), line.end(),"//vertex")) {
            state = 1;
            //std::cout << "Vertex Line" << line << std::endl;

            continue;
        }
        if (std::equal(line.begin(), line.end(),"//fragment\n")) {
            state = 2;
            continue;
        }
        if (std::equal(line.begin(), line.end(),"//geometry")) {
            state = 3;
            continue;
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
    std::cout << "fragment Shader:\n" << fragment << "\nEnd Fragment" << std::endl;
    std::cout << "vertex Shader\n" << vertex << std::endl;
}

ShaderUtil::~ShaderUtil() = default;

ShaderUtil::ShaderUtil(const char *filePath)  {
    file = std::filesystem::path(filePath);
    vertexID = glCreateShader(GL_VERTEX_SHADER);
    fragmentID = glCreateShader(GL_VERTEX_SHADER);
    shaderProgram = glCreateProgram();
    asStringtwo();

}

int ShaderUtil::compileShader() {
    auto vertexShaderSource = vertex.c_str();

    glShaderSource(vertexID, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexID);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexID, 512, NULL, infoLog);
        std::cout << "Vertex failed to compile: " << infoLog << std::endl;

    }


    auto fragmentShaderSource = fragment.c_str();
    unsigned int fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentID, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentID);

    glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(fragmentID, 512, NULL, infoLog);
        std::cout << "Fragment failed to compile: " << infoLog << std::endl;

    }

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexID);
    glAttachShader(shaderProgram, fragmentID);
    glLinkProgram(shaderProgram);

    return 0;
}

void ShaderUtil::s_use() {
    glUseProgram(shaderProgram);
}
