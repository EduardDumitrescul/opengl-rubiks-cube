#pragma once
#include "CubeColoring.h"
#include "Shader.h"
#include "glm/fwd.hpp"

class CubeRenderer
{
    unsigned int vao;
    unsigned int vbo;

    float vertices[96] = {
     //RIGHT
0.5,  0.5, -0.5, 1.0,
0.5,  0.5,  0.5, 1.0,
0.5, -0.5,  0.5, 1.0,
0.5, -0.5, -0.5, 1.0,
// LEFT
     -0.5,  0.5,  0.5, 1.0,
-0.5,  0.5, -0.5, 1.0,
-0.5, -0.5, -0.5, 1.0,
-0.5, -0.5,  0.5, 1.0,
//UP
0.5, 0.5, -0.5, 1.0,
-0.5, 0.5, -0.5, 1.0,
-0.5, 0.5,  0.5, 1.0,
0.5, 0.5,  0.5, 1.0,
//DOWN
-0.5, -0.5, -0.5, 1.0,
 0.5, -0.5, -0.5, 1.0,
 0.5, -0.5, 0.5, 1.0,
-0.5, -0.5, 0.5, 1.0,
//FRONT
 0.5,  0.5, 0.5, 1.0,
-0.5,  0.5, 0.5, 1.0,
-0.5, -0.5, 0.5, 1.0,
 0.5, -0.5, 0.5, 1.0,
     
//BACK
-0.5,  0.5, -0.5, 1.0,
 0.5,  0.5, -0.5, 1.0,
 0.5, -0.5, -0.5, 1.0,
-0.5, -0.5, -0.5, 1.0,




    };
public:
    CubeRenderer();

    void render(std::shared_ptr<Shader> shader, glm::vec3 size, glm::vec3 pos, CubeColoring coloring) const;
    void cleanup() const;
};
