#pragma once

#include <iostream>
#include <vector>
#include "voxel.h"
#include "BlockFace.h"
#include "../graphics/Mesh.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

class Block{
    public:
        Block(int id, void (*getFace)(int face, struct voxel& voxel, graphics::Mesh& mesh, glm::vec3 pos));
        Block(){};

        void (*getFace)(int face, voxel& voxel, graphics::Mesh &mesh,  glm::vec3 pos);
        bool openFaces[6];
        glm::vec2 uv = glm::vec2(0,0);
        voxel voxel;
};
