//
// Created by Ibaad A. Chaudray on 11/28/22.
//

#pragma once
#include "string"

class ShaderUtil {
public:
    ShaderUtil(const std::string &mShaderSource, const std::string &mVertexSource, const std::string &mFragmentSource);

    virtual ~ShaderUtil();
    ShaderUtil(const char* source);


private:
    std::string m_shaderSource;
    std::string m_vertexSource;
    std::string m_fragmentSource;

};
