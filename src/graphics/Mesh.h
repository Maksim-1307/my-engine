#pragma once

#include <iostream>

#define GLEW_STATIC
#define GLM_FORCE_CTOR_INIT

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../constants.h"
#include "Texture.h"


namespace graphics{

class Mesh{
    public:
    Mesh(Texture& texture, GLfloat* vertices, int verticesLength, GLuint* indices, int indicesLength);
    //~Mesh();

    void draw();
    void set_position(glm::vec3 position){
        this->position = position;
    };
    void load_buffers();
    GLuint get_VAO();
    GLuint get_EBO();

    GLfloat* vertices;
    int verticesLength;
    GLuint* indices;
    int indicesLength;
    glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f);
    Texture& texture;

    private:
    GLuint VAO, VBO, EBO;
};

}