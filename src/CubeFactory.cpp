#include "CubeFactory.h"

std::shared_ptr<CubeRenderer> CubeFactory::cubeRenderer = nullptr;

std::shared_ptr<Cube> CubeFactory::createCube(glm::vec3 size, glm::vec3 position, CubeColoring coloring)
{
    if (cubeRenderer == nullptr) {
        cubeRenderer = std::make_shared<CubeRenderer>();
    }
    return std::make_shared<Cube>(cubeRenderer, size, position, coloring);
}
