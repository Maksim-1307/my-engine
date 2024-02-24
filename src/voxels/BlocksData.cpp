#include "BlocksData.h"

using namespace graphics;

template <typename T>
void merge_vectors(std::vector<T> &target, std::vector<T> source){
    for (T el : source){
        target.push_back(el);
    }
}

void getFaceAir(int face, voxel &voxel, Mesh &mesh, std::vector<float> pos)
{
    //return 0;
}

// в дальнейшем сделать чтобы возвращал mesh
void getFaceStone(int face, voxel &voxel, Mesh &mesh, std::vector<float> pos) {
    BlockFace bf;
    unsigned int size = mesh.vertices.size() / VERTEX_SIZE;
    if (face == 0){ // y+
        merge_vectors(mesh.vertices, {
            0 + pos[0], 1 + pos[1], 0 + pos[2], 0, 0,
            0 + pos[0], 1 + pos[1], 1 + pos[2], 0, 1,
            1 + pos[0], 1 + pos[1], 0 + pos[2], 1, 0,
            1 + pos[0], 1 + pos[1], 1 + pos[2], 1, 1
        });
        merge_vectors(mesh.indices, {
            size + 0, size + 1, size + 2,
            size + 3, size + 1, size + 2
        });
    }
    if (face == 1){ // y-
        merge_vectors(mesh.vertices, {
            0 + pos[0], 0 + pos[1], 0 + pos[2], 0, 0,
            0 + pos[0], 0 + pos[1], 1 + pos[2], 0, 1,
            1 + pos[0], 0 + pos[1], 0 + pos[2], 1, 0,
            1 + pos[0], 0 + pos[1], 1 + pos[2], 1, 1
        });
        merge_vectors(mesh.indices, {
            size + 0, size + 1, size + 2,
            size + 3, size + 1, size + 2
        });
    }
    if (face == 2) { // x + 
        merge_vectors(mesh.vertices, {
            1 + pos[0], 1 + pos[1], 0 + pos[2], 0, 0,
            1 + pos[0], 0 + pos[1], 0 + pos[2], 0, 1,
            1 + pos[0], 1 + pos[1], 1 + pos[2], 1, 0,
            1 + pos[0], 0 + pos[1], 1 + pos[2], 1, 1
        });
        merge_vectors(mesh.indices, {
            size + 0, size + 1, size + 2,
            size + 3, size + 1, size + 2
        });
    }
    if (face == 3) { // x -
        merge_vectors(mesh.vertices, {
            0 + pos[0], 1 + pos[1], 0 + pos[2], 0, 0,
            0 + pos[0], 0 + pos[1], 0 + pos[2], 0, 1,
            0 + pos[0], 1 + pos[1], 1 + pos[2], 1, 0,
            0 + pos[0], 0 + pos[1], 1 + pos[2], 1, 1
        });
        merge_vectors(mesh.indices, {
            size + 0, size + 1, size + 2,
            size + 3, size + 1, size + 2
        });
    }
    if (face == 4) { // z+
        merge_vectors(mesh.vertices, {
            0 + pos[0], 0 + pos[1], 1 + pos[2], 0, 0,
            0 + pos[0], 1 + pos[1], 1 + pos[2], 0, 1,
            1 + pos[0], 0 + pos[1], 1 + pos[2], 1, 0,
            1 + pos[0], 1 + pos[1], 1 + pos[2], 1, 1
        });
        merge_vectors(mesh.indices, {
            size + 0, size + 1, size + 2,
            size + 3, size + 1, size + 2
        });
    }
    if (face == 5) { // z-
        merge_vectors(mesh.vertices, {
            0 + pos[0], 0 + pos[1], 0 + pos[2], 0, 0,
            0 + pos[0], 1 + pos[1], 0 + pos[2], 0, 1,
            1 + pos[0], 0 + pos[1], 0 + pos[2], 1, 0,
            1 + pos[0], 1 + pos[1], 0 + pos[2], 1, 1
        });
        merge_vectors(mesh.indices, {
            size + 0, size + 1, size + 2,
            size + 3, size + 1, size + 2
        });
    }
}

BlocksData::BlocksData(){
    init_blocks();
}

void BlocksData::init_blocks(){
    blocks.push_back(Block(0, getFaceAir));
    blocks.push_back(Block(1, getFaceStone));
    for (int i = 0; i < 6; i++){
        blocks[0].openFaces[i] = 1;
        blocks[1].openFaces[i] = 0;
    }
}