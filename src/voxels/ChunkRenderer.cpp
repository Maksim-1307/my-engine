#include "ChunkRenderer.h"

using namespace std;
using namespace glm;
using namespace graphics;
/*

FACES
id   axis
0    X+
1    X-
2    Y+
3    Y-
4    Z+
5    Z-

*/

void ChunkRenderer::render(Chunk* pChunk){

    vertexCount = 0;
    indicesCount = 0;
    this->chunk = *pChunk; 
    for (int x = 1; x < CHUNK_WIDTH-1; x++){
        for (int y = 1; y < CHUNK_HEIGHT-1; y++){
            for (int z = 1; z < CHUNK_WIDTH-1; z++){
                currentCoords = vec3(x, y, z);
                voxel vox = chunk.blocksData[x][y][z];
                Block block = BlocksData::BlocksStorage.blocks[(int)vox.id];
                //Block nearBlock;
                for (int face = 0; face < 6; face++){
                    voxel nearVox;
                    if (block.openFaces[face]){
                        switch (face) {
                            case 0:
                                nearVox = chunk.blocksData[x+1][y][z];
                                break;
                            case 1:
                                nearVox = chunk.blocksData[x-1][y][z];
                                break;
                            case 2:
                                nearVox = chunk.blocksData[x][y+1][z];
                                break;
                            case 3:
                                nearVox = chunk.blocksData[x][y-1][z];
                                break;
                            case 4:
                                nearVox = chunk.blocksData[x][y][z+1];
                                break;
                            case 5:
                                nearVox = chunk.blocksData[x][y][z-1];
                                break;
                        }
                        nearBlock = BlocksData::BlocksStorage.blocks[(int)nearVox.id];

                        if (nearVox.id != 0){
                            modelCube(face, vox);
                        }
                    } 
                }
            } 
        }
    }
    pChunk->indices = this->indices;
    pChunk->vertices = this->vertices;
    pChunk->indicesSize = indicesCount;
    pChunk->verticesSize = vertexCount;
}


void ChunkRenderer::modelCube(int face, voxel &voxel){

    indices[indicesCount++] = 0 + vertexCount / VERTEX_SIZE;
    indices[indicesCount++] = 1 + vertexCount / VERTEX_SIZE;
    indices[indicesCount++] = 2 + vertexCount / VERTEX_SIZE;
    indices[indicesCount++] = 3 + vertexCount / VERTEX_SIZE;
    indices[indicesCount++] = 1 + vertexCount / VERTEX_SIZE;
    indices[indicesCount++] = 2 + vertexCount / VERTEX_SIZE;

    switch(face){
        case 0: // X+
            vertex(1, 0, 0, 0, 0);
            vertex(1, 0, 1, 1, 0);
            vertex(1, 1, 0, 0, 1);
            vertex(1, 1, 1, 1, 1);
            break;
        case 1: // X-
            vertex(0, 0, 0, 0, 0);
            vertex(0, 0, 1, 1, 0);
            vertex(0, 1, 0, 0, 1);
            vertex(0, 1, 1, 1, 1);
            break;
        case 2: // Y+
            vertex(0, 1, 0, 0, 0);
            vertex(0, 1, 1, 0, 1);
            vertex(1, 1, 0, 1, 0);
            vertex(1, 1, 1, 1, 1);
            break;
        case 3: // Y-
            vertex(0, 0, 0, 0, 0);
            vertex(0, 0, 1, 0, 1);
            vertex(1, 0, 0, 1, 0);
            vertex(1, 0, 1, 1, 1);
            break;
        case 4: // Z+
            vertex(0, 0, 1, 0, 0);
            vertex(0, 1, 1, 0, 1);
            vertex(1, 0, 1, 1, 0);
            vertex(1, 1, 1, 1, 1);
            break;
        case 5: // Z-
            vertex(0, 0, 0, 0, 0);
            vertex(0, 1, 0, 0, 1);
            vertex(1, 0, 0, 1, 0);
            vertex(1, 1, 0, 1, 1);
            break;

    };
    
}

void ChunkRenderer::modelAir(int face, voxel &voxel){
    return;
}


void ChunkRenderer::vertex(float x, float y, float z, float UVx, float UVy){

    vertices[vertexCount++] = x + currentCoords.x + chunk.x * CHUNK_WIDTH;
    vertices[vertexCount++] = y + currentCoords.y;
    vertices[vertexCount++] = z + currentCoords.z + chunk.z * CHUNK_WIDTH;
    vertices[vertexCount++] = (1.0f / ATLAS_SIZE) * (float)UVx + nearBlock.uv.x / ATLAS_SIZE;
    vertices[vertexCount++] = (1.0f / ATLAS_SIZE) * (float)UVy + nearBlock.uv.y / ATLAS_SIZE;
}
