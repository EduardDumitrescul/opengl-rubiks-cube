#pragma once
#include <memory>

#include "Cube.h"
#include "Move.h"

class MoveHandler {
    std::shared_ptr<Cube> (&cubes)[3][3][3];

    void rotateFaceClockwise(std::shared_ptr<Cube> (&face)[3][3]);

    void rotateFaceCounterClockwise(std::shared_ptr<Cube> (&face)[3][3]);

    void getFace(int axis, int index, std::shared_ptr<Cube> (&face)[3][3]);

    void setFace(int axis, int index, const std::shared_ptr<Cube> (&face)[3][3]);

    void rotateCubes(int axis, bool clockwise, std::shared_ptr<Cube> (&face)[3][3]);

public:
    MoveHandler(std::shared_ptr<Cube> (&cubes)[3][3][3]);

    void performMove(Move move);
};
