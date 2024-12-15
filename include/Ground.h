#pragma once
#include <memory>

#include "Shader.h"

class Ground
{
    const glm::vec3 size = {1000, 1, 1000};
    unsigned int vao;
    unsigned int vbo;

    float vertices[28] = {
        -1, -10, -1, 1.0, 0, 1, 0,
        -1, -10, 1, 1.0, 0, 1, 0,
        1, -10, 1, 1.0, 0, 1, 0,
        1, -10, -1, 1.0, 0, 1, 0,
    };
public:
    Ground();
    void render(std::shared_ptr<Shader> shader) const;
    void cleanup();
};
