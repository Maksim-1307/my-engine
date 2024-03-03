#pragma once

#define GLEW_STATIC
#define GLM_FORCE_CTOR_INIT
#define SHADERS_PATH "res/shaders/"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "../voxels/voxel.h"
#include "../graphics/Mesh.h"
#include "../voxels/BlocksData.h"

#define CHUNK_WIDTH 16
#define CHUNK_HEIGHT 256

class Chunk{
    public:
    Chunk(){
        mesh.vertices.reserve(1024);
        mesh.indices.reserve(1024);
    };
    ~Chunk(){
        std::cout << "Chunk "<< this->x << " " << this->z <<" deleted\n";
    };

    int x, z;
    voxel blocksData[CHUNK_WIDTH][CHUNK_HEIGHT][CHUNK_WIDTH];// = (voxel*)malloc(CHUNK_HEIGHT * CHUNK_WIDTH * CHUNK_WIDTH * sizeof(voxel));
    graphics::Mesh mesh;
    float * vertices = (float*)malloc(10000 * sizeof(float));
    int verticesSize;
    int * indices = (int*)malloc(10000 * sizeof(int));
    int indicesSize;


    GLuint VAO;
    GLuint VBO;
    GLuint EBO;

    //BlocksData blData;

    //void updateVoxels();
    virtual void generate();
    virtual void make_buffers();
    virtual void print_blocks();

    virtual void draw();

};