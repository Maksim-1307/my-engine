#include "Chunk.h"

using namespace std;

void Chunk::updateVoxels(){
    for (int x = 1; x < CHUNK_WIDTH-1; x++){
        for (int y = 1; y < CHUNK_HEIGHT-1; y++){
            for (int z = 1; z < CHUNK_WIDTH-1; z++){
                voxel vox = this->blocksData[x][y][z];
                Block block = this->blData.blocks[(int)vox.id];
                Block nearBlock;
                for (int face = 0; face < 6; face++){
                    voxel nearVox;
                    if (block.openFaces[face]){
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
                        //cout << (int)nearBlock.voxel.id << "\n\n";
                        if ((int)nearVox.id == 1){
                            cout << "\n\n\n\n\n STONE \n\n\n\n\n\n"; 
                            exit(1200);
                        }
                        if ((int)vox.id == 1){
                            cout << "current is Stone";
                            exit (0);
                        }
                        nearBlock = blData.blocks[(int)nearVox.id];
                        //nearBlock.getFace(face, vox, mesh, {(float)x, (float)y, (float)z});

                        //костыль


                        if (y == 10){
                            blData.blocks[1].getFace(face, blData.blocks[0].voxel, mesh, {(float)x, (float)y, (float)z});
                        }
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
    air.state = 0;
    stone.id = (uint8_t)1;
    stone.state = 0;
    for (int x = 0; x < CHUNK_WIDTH; x++){
        for (int y = 0; y < CHUNK_HEIGHT; y++){
            for (int z = 0; z < CHUNK_WIDTH; z++){
                this->blocksData[x][y][z] = air;
                // if (y == 5){
                //     this->blocksData[x][y][z] = stone;
                // }
            }
        }
    }
    this->blocksData[8][10][8] = stone;
    this->blocksData[8][11][8] = stone;
    this->blocksData[8][9][8] = stone;
    this->blocksData[7][10][8] = stone;
    this->blocksData[9][10][8] = stone;
}