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

    colors = new GLfloat[]{
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f
    };

    

    glGenBuffers(1, &EBO);


    glGenBuffers(1, &vertex_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
    glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &texture_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, texture_VBO);
    glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), uv, GL_STATIC_DRAW);


    // glGenBuffers(1, &VBO);
    // glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // glBufferData(GL_ARRAY_BUFFER, VERTEX_SIZE * 4 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);



    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(GLuint), indices, GL_STATIC_DRAW);


    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 3 * sizeof(GLfloat), (GLvoid*)0);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, texture_VBO);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_TRUE, 2 * sizeof(GLfloat), (GLvoid*)0);

    glBindVertexArray(0); 

}

void Sprite::set_position(glm::vec2 position){
    this->position = position;
    update_vertices();
}

void Sprite::update_vertices(){
    vertices = new GLfloat[] {
        0.0f, 0.0f, 0.0f,
        size.x, 0.0f, 0.0f,
        0.0f, size.y, 0.0f,
        size.x, size.y, 0.0f
    };
    update_UVs();
    laod_buffers();
}

void Sprite::update_UVs(){

    glm::vec2 normalSize = glm::normalize(size);

    uv = new GLfloat[]{
        0.0f, 0.0f,
        1.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f
    };

    // switch(UVmode){
    //     case CUSTOM:
    //         break;
    //     case FILL:
    //         uv = new GLfloat[] {
    //             0.0f, 0.0f,
    //             1.0f, 0.0f,
    //             0.0f, 1.0f,
    //             1.0f, 1.0f
    //         };
    //         break;
    //     case FIT:
    //         uv = new GLfloat[] {
    //             0, 0,
    //             normalSize.x, 0,
    //             0, normalSize.y,
    //             normalSize.x, normalSize.y
    //         };
    //         break;
    //     case COVER:
    //         //glm::vec2 normalSize = glm::normalize(size);
    //         float ratio = normalSize.x / normalSize.y;
    //         uv = new GLfloat[] {
    //             0, 0,
    //             normalSize.x / ratio, 0,
    //             0, normalSize.y / ratio,
    //             normalSize.x / ratio, normalSize.y / ratio
    //         };
    //         break;
    //     // default:
    //     //     uv = new GLfloat[] {
    //     //         0, 0,
    //     //         1, 0,
    //     //         0, 1,
    //     //         1, 1 
    //     //     };
    // }

}

// you should use uv mode CUSTOM to use this function. It disables UV auto update
void Sprite::set_UVs(GLfloat newUVs[6]){
    if (UVmode != CUSTOM){
        std::cout << "WARNING: using Sprite::set_UVs without uv mode CUSTOM" << std::endl;
    }
    uv = newUVs;
}

void Sprite::resize(glm::vec2 newSize){
    size = newSize;
    update_vertices();
}