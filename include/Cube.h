#pragma once
#include <memory>

#include "Colors.h"
#include "CubeRenderer.h"
#include "glm/gtc/type_ptr.hpp"

class Cube
{
    std::shared_ptr<CubeRenderer> renderer;

    glm::vec3 size = {1, 1, 1};
    glm::vec3 position = {0, 0, 0};
    glm::vec3 animationPosition = {0, 0, 0};
    glm::quat rotation = {1,0 , 0, 0};
    glm::quat animationRotation = {1, 0, 0, 0};
    
    CubeColoring coloring;
public:
    Cube(std::shared_ptr<CubeRenderer> renderer, glm::vec3 size, glm::vec3 position, CubeColoring coloring);

    Cube(const Cube& other)
        : size(other.size),               // Direct copy of glm::vec3
          position(other.position),       // Direct copy of glm::vec3
          rotation(other.rotation),       // Direct copy of glm::vec3
          coloring(other.coloring)        // Copy of CubeColoring
    {
        // Deep copy of the renderer (create a new CubeRenderer object)
        this->renderer = std::make_shared<CubeRenderer>(*other.renderer);
    }

    glm::vec3 getPosition();

    void setPosition(glm::vec3 position);

    void setAnimationPosition(glm::vec3 animationPosition);

    void removeRotation();

    void render(std::shared_ptr<Shader> shader) const;

    void cleanup();
    CubeColoring getColoring();

    void rotateXClockwise(int times);

    void rotateYClockwise(int times);

    void rotateZClockwise(int times);

    bool operator<(const Cube& other) const
    {
        return this->coloring.colors < other.coloring.colors;
    }

    std::string toString()
    {
        return coloring.toString();
    }

    glm::quat getRotation();

    void setAnimationRotation(glm::quat qua);
};


