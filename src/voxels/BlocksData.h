#pragma once

#include <iostream>
#include <vector>
#include "voxel.h"
#include "BlockFace.h"
#include "Block.h"
#include "../graphics/Mesh.h"
#include <glm/glm.hpp>

class BlocksData {
    public:
    BlocksData();
    void init_blocks();
    std::vector<Block> blocks;
};