#pragma once

#include <iostream>
#include <GL/glew.h>

namespace renderer{

    class ShaderProgram {

    public:

        ShaderProgram( const std::string& vertexSource, const std::string& fragmentSource);
        ~ShaderProgram();

        GLuint getID();

        bool Use();

        bool is_compiled();
    
    private:

        GLuint createShader( const std::string& source, const GLenum shaderType);

        bool isCompiled = false;
        GLuint ID = 0;

    };
}