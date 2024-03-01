#include "Block.h"

Block::Block(int id, void (*getFace)(int face, struct voxel& voxel, graphics::Mesh& mesh, glm::vec3 pos)){
    this->getFace = getFace;
    this->voxel.id = id;
    this->voxel.state = 0;
    std::cout << "\n\nthis voxel id is: " << (int)this->voxel.id;
}

