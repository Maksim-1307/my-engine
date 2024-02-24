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

#include <vector>


namespace graphics{

class Mesh{
    public:
    Mesh(GLfloat* vertices, int verticesLength, GLuint* indices, int indicesLength) {
        this->vertices = std::vector<GLfloat>(vertices, vertices + verticesLength);
        this->indices = std::vector<GLuint>(indices, indices + indicesLength);
    };
    Mesh(){};

    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;

};

}