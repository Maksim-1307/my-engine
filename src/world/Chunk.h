#pragma once

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

    int x, z;
    voxel blocksData[CHUNK_WIDTH][CHUNK_HEIGHT][CHUNK_WIDTH];
    graphics::Mesh mesh;

    //BlocksData blData;

    //void updateVoxels();
    void generate();

};