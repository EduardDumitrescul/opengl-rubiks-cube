#pragma once
#include <memory>

#include "Cube.h"
#include "CubeRenderer.h"

class CubeFactory
{
    static std::shared_ptr<CubeRenderer> cubeRenderer;
    
public:
    static std::shared_ptr<Cube> createCube(glm::vec3 size, glm::vec3 position);
};