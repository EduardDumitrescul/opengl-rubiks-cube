#include "Cube.h"

Cube::Cube(std::shared_ptr<CubeRenderer> renderer, glm::vec3 size, glm::vec3 position)
{
    this->renderer = renderer;
    this->size = size;
    this->position = position;
}

void Cube::render(std::shared_ptr<Shader> shader) const
{
    renderer->render(shader, size, position);
}

void Cube::cleanup()
{
    renderer->cleanup();
}
