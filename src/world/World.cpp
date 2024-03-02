#include "World.h"

voxel World::get_voxel(int x, int y, int z){
    glm::ivec2 chunk(x / CHUNK_WIDTH, z / CHUNK_WIDTH); 
    auto found = chunks.find(chunk);
    if (found != chunks.end()) {
        return chunks[chunk]->blocksData[x % CHUNK_WIDTH][y % CHUNK_HEIGHT][z % CHUNK_WIDTH];
    }
}


void World::load_chunk(glm::ivec2 coords){
    auto found = chunks.find(coords);
    if (found == chunks.end()) {

        chunks.insert({coords, new Chunk()});
        chunks[coords]->x = coords.x;
        chunks[coords]->z = coords.y;
        chunks[coords]->generate();

        chunks[coords]->print_blocks();

    }
}