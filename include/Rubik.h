#pragma once
#include <memory>

#include "Cube.h"
#include "CubeFactory.h"

class Rubik
{
    std::shared_ptr<Cube> cubes[3][3][3];
    
public:
    Rubik();

    void render(std::shared_ptr<Shader> shader);

    void cleanup();
};
