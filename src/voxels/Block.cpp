#include "Block.h"

Block::Block(int id, void (*getFace)(int face, struct voxel& voxel, graphics::Mesh& mesh, std::vector<float> pos)){
    this->getFace = getFace;
    this->voxel.id = id;
}

