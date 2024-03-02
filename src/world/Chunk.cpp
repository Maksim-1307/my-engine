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
                if (y == 5){
                    this->blocksData[x][y][z] = stone;
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