//
// Created by Ibaad A. Chaudray on 9/28/22.
//
#pragma once
#include <cstdio>
#include <filesystem>
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
private:
    void asStringtwo();

};
