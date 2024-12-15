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

void Cube::setAnimationPosition(glm::vec3 animationPosition)
{
    this->animationPosition = animationPosition;
}

void Cube::removeRotation()
{
    rotation = {1, 0,0, 0};
    animationRotation = {1, 0, 0, 0};
    animationPosition = {0, 0, 0};
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

glm::quat Cube::getRotation()
{
    return this->rotation * animationRotation;
}

void Cube::setAnimationRotation(glm::quat qua)
{
    this->animationRotation = qua;
}

void Cube::render(std::shared_ptr<Shader> shader) const
{
    renderer->render(shader, size, position + animationPosition, rotation * animationRotation, coloring);
}

void Cube::cleanup()
{
    renderer->cleanup();
}
