#pragma once

#include <iostream>

#define GLEW_STATIC
#define GLM_FORCE_CTOR_INIT

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "Texture.h"

namespace graphics{

class SpriteData{
    public:

    SpriteData(int vertices_len, GLfloat* vertices, int indices_len, GLuint* indices, int uv_len, GLfloat* uv, Texture& texture);

    SpriteData();
    ~SpriteData();

    bool is_full();
    
    GLfloat* vertices;
    GLuint* indices;
    GLfloat* uv;

    int vertices_len, indices_len, uv_len;

};

}