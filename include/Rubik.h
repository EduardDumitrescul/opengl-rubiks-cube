#pragma once
#include <memory>

#include "AnimationManager.h"
#include "Cube.h"
#include "MoveHandler.h"

class Rubik
{
    std::unique_ptr<MoveHandler> moveHandler;
    std::unique_ptr<AnimationManager> animationManager;
    std::shared_ptr<Cube> cubes[3][3][3];
    
public:
    Rubik();

    void makeMove(Move move);

    void render(std::shared_ptr<Shader> shader);

    void cleanup();
};
