#pragma once

#include <iostream>
#include "../voxels/voxel.h"
#include "../graphics/Mesh.h"
#include "../voxels/BlocksData.h"
#include "../world/Chunk.h"
#include "../graphics/Mesh.h"
#include "../constants.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

#define ATLAS_SIZE 8

using namespace glm;
using namespace std;

class ChunkRenderer{
    public:
    ChunkRenderer(){};
    ~ChunkRenderer(){};

    void render(Chunk* pChunk);
    void vertex(float x, float y, float z, float UVx, float UVy);
    void face();
    void modelCube(int face, voxel &voxel);
    void modelAir(int face, voxel &voxel);

    vec3 currentCoords = vec3(0,0,0);
    int vertexCount = 0;
    int indicesCount = 0;
    float * vertices = (float*)malloc(10000 * sizeof(float));
    int * indices = (int*)malloc(10000 * sizeof(int));
    Block nearBlock;
    Chunk chunk;
};
