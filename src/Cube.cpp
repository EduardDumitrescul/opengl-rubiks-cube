#include "Cube.h"

Cube::Cube(std::shared_ptr<CubeRenderer> renderer, glm::vec3 size, glm::vec3 position, CubeColoring coloring):
coloring(coloring), renderer(renderer), size(size), position(position)
{
    
}

glm::vec3 Cube::getPosition()
{
    return position;
}

void Cube::setPosition(glm::vec3 position)
{
    this->position = position;
}

void Cube::rotate(glm::vec3 delta)
{
    rotation += delta;
}

void Cube::removeRotation()
{
    rotation = {0, 0,0};
}

CubeColoring Cube::getColoring()
{
    return coloring;
}

void Cube::rotateXClockwise(int times)
{
    while (times --)
    {
        coloring.rotateXClockwise();
    }
}

void Cube::rotateYClockwise(int times)
{
    while (times --)
    {
        coloring.rotateYClockwise();
    }
}

void Cube::rotateZClockwise(int times)
{
    while (times --)
    {
        coloring.rotateZClockwise();
    }
}

void Cube::render(std::shared_ptr<Shader> shader) const
{
    renderer->render(shader, size, position, rotation, coloring);
}

void Cube::cleanup()
{
    renderer->cleanup();
}
