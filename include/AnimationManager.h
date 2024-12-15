#pragma once
#include <functional>
#include <memory>

#include "Cube.h"
#include "Shader.h"
#include "Move.h"

class AnimationManager
{
    std::shared_ptr<Cube> (&cubes)[3][3][3];
    
    bool animationRunning = false;
    static int animationDuration;
    int animationProgress;
    float angle = 0;
    float step = 0.1f;
    std::function<void()> animationFinishedCallback;
    
    Move move;
public:
    AnimationManager(std::shared_ptr<Cube> (&cubes)[3][3][3]);

    void startAnimation(Move move, std::function<void()> callback);

    void update(int deltaTimestamp);

    void rotateUp(bool reverse = false, int deltaTime = animationDuration);

    void rotateDown(bool reverse = false);

    void rotateFront(bool reverse = false);

    void rotateBack(bool reverse = false);

    void rotateLeft(bool reverse = false);

    void rotateRight(bool reverse = false);
};
