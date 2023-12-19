#include "ShaderProgram.h"

namespace renderer{

    ShaderProgram::ShaderProgram( const std::string& vertexSource, const std::string& fragmentSource ){

        GLuint shaderProgram;
        shaderProgram = glCreateProgram();

        GLuint VertexShader = this->createShader(vertexSource, GL_VERTEX_SHADER);
        GLuint FragmentShader = this->createShader(fragmentSource, GL_FRAGMENT_SHADER);

        glAttachShader(shaderProgram, VertexShader);
        glAttachShader(shaderProgram, FragmentShader);

        glLinkProgram(shaderProgram);

        GLint success;
        GLchar infoLog[512];

        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
            exit(-1);
        } else {
            std::cout << "program created" << std::endl;
            this -> isCompiled = true;
            this -> ID = shaderProgram;
        }

        glDeleteShader(VertexShader);
        glDeleteShader(VertexShader);

    };

    ShaderProgram::~ShaderProgram(){
        glDeleteProgram(ID);
        std::cout << "shaderprogram deleted" << std::endl;
    }

    bool ShaderProgram::Use(){
        glUseProgram(ID);
    }

    bool ShaderProgram::is_compiled(){
        return this -> isCompiled;
    }

    GLuint ShaderProgram::getID(){
        return this -> ID;
    }

    GLuint ShaderProgram::createShader( const std::string& source, const GLenum shaderType ){

        GLuint pShader;

        pShader = glCreateShader(shaderType);

        if (source.empty()) {
            std::cout << "ERROR: shader source is empty" << std::endl;
            exit(-1);
        }

        const char * code = source.c_str();

        glShaderSource(pShader, 1, &code, NULL);

        glCompileShader(pShader);

        GLint success;
        GLchar infoLog[512];

        glGetShaderiv(pShader, GL_COMPILE_STATUS, &success);

        if (!success){
            glGetShaderInfoLog(pShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
            std::cout << "VERTEX SHADER SOUORCE: \n" << source << std::endl;
            exit(-1);
        }

        return pShader;
    }


}