#pragma once
#include <memory>

#include "AnimationManager.h"
#include "Cube.h"
#include "MoveHandler.h"

class Rubik : public std::enable_shared_from_this<Rubik>
{
    bool busy = false;
    
    std::shared_ptr<MoveHandler> moveHandler;
    std::shared_ptr<AnimationManager> animationManager;
    std::shared_ptr<Cube> cubes[3][3][3];
    
public:
    Rubik();

    bool isBusy();
    
    void performMove(Move move, std::function<void()> onMoveFinished, bool animation = true);

    void render(std::shared_ptr<Shader> shader, int deltaTime);

    void cleanup();

    Rubik& operator=(const Rubik& other);

    Rubik(const Rubik& other);

    bool operator<(const Rubik& other) const;

    bool operator ==(const Rubik& other) const;

    std::string toString() const;
    
    bool isSolved();
};
