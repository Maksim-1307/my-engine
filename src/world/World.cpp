#include "World.h"

voxel World::get_voxel(int x, int y, int z){
    //std::cout << "\n get voxel x: " << x << ", y: " << y << ", z: " << z << "\n";
    glm::ivec2 chunk(x / CHUNK_WIDTH, z / CHUNK_WIDTH); 
    glm::ivec2 block(x % CHUNK_WIDTH, z % CHUNK_WIDTH);
    if (x < 0) chunk.x-=1;
    if (z < 0) chunk.y-=1;
    if (block.x < 0) block.x += CHUNK_WIDTH;
    if (block.y < 0) block.y += CHUNK_WIDTH;
    auto found = chunks.find(chunk);
    if (found != chunks.end()) {
        return chunks[chunk]->blocksData[block.x][y % CHUNK_HEIGHT][block.y];
    } else {
        voxel nullvox;
        nullvox.id = 0;
        return nullvox;
    }
}


void World::load_chunk(int x, int z){
    glm::ivec2 coords(x, z);
    auto found = chunks.find(coords);
    if (found == chunks.end()) {

        this->chunks.insert({coords, new Chunk()});
        this->chunks[coords]->x = x;
        this->chunks[coords]->z = z;
        this->chunks[coords]->generate();

    }
}
