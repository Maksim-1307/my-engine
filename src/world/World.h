#pragma once

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include "../voxels/voxel.h"
#include "../graphics/Mesh.h"
#include "../voxels/BlocksData.h"
#include "Chunk.h"
#include "../voxels/voxel.h"
class World{
    public:
    World();
    ~World();

    voxel get_voxel(int x, int y, int z);

    std::unordered_map<glm::ivec2, Chunk> chunks;
};

