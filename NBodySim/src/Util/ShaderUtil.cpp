//
// Created by Ibaad A. Chaudray on 11/28/22.
//

#include "ShaderUtil.h"

ShaderUtil::ShaderUtil(const std::string &mShaderSource, const std::string &mVertexSource, const std::string &mFragmentSource)
        : m_shaderSource(mShaderSource), m_vertexSource(mVertexSource), m_fragmentSource(mFragmentSource) {}

ShaderUtil::~ShaderUtil() {

}

ShaderUtil::ShaderUtil(const char *source) {
    m_shaderSource = source;

}
