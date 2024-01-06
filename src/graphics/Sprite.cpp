#include "Sprite.h"

using namespace graphics;

Sprite::Sprite(Texture& texture, renderer::ShaderProgram& shaderProgram, glm::vec2 size, enum UVmode) : texture(texture), shaderProgram(shaderProgram){
    
    indices = new GLuint[]{
        0, 1, 2,
        1, 3, 2
    };

    this->texture = texture;
    this->shaderProgram = shaderProgram;
    this->size = size;
    this->UVmode = UVmode;
    update_vertices();

}

void Sprite::render(){
    shaderProgram.Use();
    texture.bind_texture();

    shaderProgram.set_matrix4("view", glm::translate(glm::mat4(1.0f), glm::vec3(position, 0.0f)));
    shaderProgram.set_texture("Texture", texture.get_ID());

    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

}

void Sprite::laod_buffers(){    

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, VERTEX_SIZE * 4 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);


    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, VERTEX_SIZE * sizeof(GLfloat), (GLvoid*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_TRUE, VERTEX_SIZE * sizeof(GLfloat), (GLvoid*)((VERTEX_SIZE - 2) * sizeof(GLfloat)));

    glBindVertexArray(0); 


    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(GLuint), indices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Sprite::set_position(glm::vec2 position){
    this->position = position;
    update_vertices();
}

void Sprite::update_vertices(){
    vertices = new GLfloat[] {
    //  coords (X, Y, Z)      and UV (X, Y)
        0.0f, 0.0f, 0.0f,     0.0f, 0.0f,
        size.x, 0.0f, 0.0f,   1.0f, 0.0f,
        0.0f, size.y, 0.0f,   0.0f, 1.0f,
        size.x, size.y, 0.0f, 1.0f, 1.0f
    };
    laod_buffers();
}

void Sprite::resize(glm::vec2 newSize){
    size = newSize;
    update_vertices();
}