#pragma once

#include <iostream>
#include <GL/glew.h>

#define GLM_FORCE_CTOR_INIT

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace renderer{

    class ShaderProgram {

    public:

        ShaderProgram( const std::string& vertexSource, const std::string& fragmentSource);
        ~ShaderProgram();

        GLuint getID();

        bool Use();

        bool is_compiled();

        bool set_matrix4(std::string uniformName, glm::mat4 matrix);

        bool set_texture(std::string uniformName, GLuint tectureID);
    
    private:

        GLuint createShader( const std::string& source, const GLenum shaderType);

        bool isCompiled = false;
        GLuint ID = 0;

    };
}