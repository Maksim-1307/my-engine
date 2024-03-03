#include "World.h"

voxel World::get_voxel(int x, int y, int z){
    glm::ivec2 chunk(x / CHUNK_WIDTH, z / CHUNK_WIDTH); 
    auto found = chunks.find(chunk);
    if (found != chunks.end()) {
        return chunks[chunk]->blocksData[x % CHUNK_WIDTH][y % CHUNK_HEIGHT][z % CHUNK_WIDTH];
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
