#include "Cube.h"

Cube::Cube(std::shared_ptr<CubeRenderer> renderer, glm::vec3 size, glm::vec3 position, CubeColoring coloring):
coloring(coloring), renderer(renderer), size(size), position(position)
{
    
}

void Cube::render(std::shared_ptr<Shader> shader) const
{
    renderer->render(shader, size, position, coloring);
}

void Cube::cleanup()
{
    renderer->cleanup();
}
