// #include "Mesh.h"

// using namespace graphics;

// Mesh::Mesh(Texture& texture, renderer::ShaderProgram& shaderProgram, GLfloat* vertices, int verticesLength, GLuint* indices, int indicesLength) : texture(texture), shaderProgram(shaderProgram){
//     this->texture = texture;
//     this->vertices = vertices;
//     this->verticesLength = verticesLength;
//     this->indices = indices;
//     this->indicesLength = indicesLength;
//     this->shaderProgram = shaderProgram;

//     set_position(position);
//     load_buffers();
// };


// void Mesh::draw(){
//     glBindVertexArray(VAO);
//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//     glDrawElements(GL_TRIANGLES, indicesLength, GL_UNSIGNED_INT, 0);
//     glBindVertexArray(0);
// }


// void Mesh::load_buffers(){

//     glGenBuffers(1, &VBO);
//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, verticesLength * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

//     glGenVertexArrays(1, &VAO);
//     glBindVertexArray(VAO);

//     glEnableVertexAttribArray(0);
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);

//     glEnableVertexAttribArray(1);
//     glVertexAttribPointer(1, 2, GL_FLOAT, GL_TRUE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

//     glBindVertexArray(0); 
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     glGenBuffers(1, &EBO);
//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//     glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesLength * sizeof(GLuint), indices, GL_STATIC_DRAW);
//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

// }

// GLuint Mesh::get_VAO(){
//     if (VAO){
//         return VAO;
//     } else {
//         load_buffers();
//     }
//     return VAO;
// }

// GLuint Mesh::get_EBO(){
//     if (EBO){
//         return EBO;
//     } else {
//         load_buffers();
//     }
//     return EBO;
// }

// void Mesh::set_position(glm::vec3 newPosition){
//     position = newPosition;
//     model = glm::translate(glm::mat4(1.0f), position);
//     shaderProgram.set_matrix4("model", model);
// }