#pragma once

#include <iostream>
#include <vector>
#include "voxel.h"
#include "BlockFace.h"
#include "../graphics/Mesh.h"

class Block{
    public:
        Block(int id, void (*getFace)(int face, struct voxel& voxel, graphics::Mesh& mesh, glm::vec3 pos));
        Block(){};

        void (*getFace)(int face, voxel& voxel, graphics::Mesh &mesh,  glm::vec3 pos);
        bool openFaces[6];
        voxel voxel;
};
