#pragma once
#include <memory>

#include "Colors.h"
#include "CubeRenderer.h"
#include "glm/gtc/type_ptr.hpp"

class Cube
{
private:
    std::shared_ptr<CubeRenderer> renderer;

    glm::vec3 size = {1, 1, 1};
    glm::vec3 position = {0, 0, 0};
    

    CubeColoring coloring;
public:
    Cube(std::shared_ptr<CubeRenderer> renderer, glm::vec3 size, glm::vec3 position, CubeColoring coloring);

    void render(std::shared_ptr<Shader> shader) const;

    void cleanup();
};


