#include "Chunk.h"

void Chunk::updateVoxels(){
    for (int x = 1; x < CHUNK_WIDTH-1; x++){
        for (int y = 1; y < CHUNK_HEIGHT-1; y++){
            for (int z = 1; z < CHUNK_WIDTH-1; z++){
                voxel vox = blocksData[x][y][z];
                Block nearBlock;
                // write a function to get Block by voxel
                Block block = blData.blocks[vox.id];
                for (int face = 0; face < 6; face++){
                    voxel nearVox;
                    switch (face) {
                        case 0:
                            nearVox = blocksData[x][y+1][z];
                        case 1:
                            nearVox = blocksData[x][y-1][z];
                        case 2:
                            nearVox = blocksData[x+1][y][z];
                        case 3:
                            nearVox = blocksData[x-1][y][z];
                        case 4:
                            nearVox = blocksData[x][y][z+1];
                        case 5:
                            nearVox = blocksData[x][y][z-1];
                    }
                    nearBlock = blData.blocks[nearVox.id];
                    if (nearVox.id == 0){
                        block.getFace(face, nearVox, mesh, {(float)x, (float)y, (float)z});
                    }
                }
            }
        }
    }
}

void Chunk::generate(){
    voxel stone;
    voxel air;
    air.id = 0;
    air.states = 0;
    stone.id = 1;
    stone.states = 0;
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
}