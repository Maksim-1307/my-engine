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

enum UVmode {
    FILL,  // texture stretch all over sprite (like background-size: 100%; in CSS)
    COVER, // texture fill all sprite without stretching (like background-size: cover; in CSS)
    FIT,   // texture fits into a sprite (like background-size: contain; in CSS)
    CUSTOM
};

namespace graphics{


    class Sprite{
        public:

        Sprite(Texture& texture, renderer::ShaderProgram& shaderProgram, glm::vec2 size, enum UVmode);

        glm::vec2 get_size(){
            return this->size;
        };

        void update_vertices();

        void render();

        void set_position(glm::vec2 position);
        void resize(glm::vec2 newSize);
        void laod_buffers();

        private:

        GLuint VBO;
        GLuint EBO;
        GLuint VAO;

        GLfloat* vertices;
        GLuint* indices;
        glm::vec2 position = glm::vec2(0, 0);
        glm::vec2 size;
        Texture& texture;
        renderer::ShaderProgram& shaderProgram;
        UVmode UVmode;
    };
}