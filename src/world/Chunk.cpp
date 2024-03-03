#include "Chunk.h"

using namespace std;

void Chunk::generate(){
    voxel stone;
    voxel air;
    voxel dirt;
    air.id = 0;
    air.state = 0;
    stone.id = (uint8_t)1;
    stone.state = 0;
    dirt.id = (uint8_t)2;
    for (int x = 0; x < CHUNK_WIDTH; x++){
        for (int y = 0; y < CHUNK_HEIGHT; y++){
            for (int z = 0; z < CHUNK_WIDTH; z++){
                this->blocksData[x][y][z] = air;
                if (y == 0 || y == 1){
                    this->blocksData[x][y][z] = stone;
                }
                if (y == 2){
                    if (x == z || x == 15){
                        this->blocksData[x][y][z] = stone;
                    }
                }
            }
        }
    }
    this->blocksData[8][10][8] = dirt;
    this->blocksData[8][11][8] = dirt;
    this->blocksData[8][9][8] = dirt;
    this->blocksData[7][10][8] = dirt;
    this->blocksData[9][10][8] = dirt;

    this->blocksData[8][5][8] = dirt;
}

void Chunk::print_blocks(){
    for (int x = 0; x < CHUNK_WIDTH; x++){
        for (int y = 0; y < CHUNK_HEIGHT; y++){
            for (int z = 0; z < CHUNK_WIDTH; z++){
                std::cout << (int)this->blocksData[x][y][z].id << " ";
            } 
            std::cout << "\n";
        }
        std::cout << "\n\n";
    }
}

void Chunk::draw(){
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, verticesSize, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Chunk::make_buffers(){
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, verticesSize * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_TRUE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

    glBindVertexArray(0); 
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize * sizeof(GLuint), indices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

