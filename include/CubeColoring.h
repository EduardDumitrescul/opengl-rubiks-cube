#pragma once
#include <vector>
#include "Colors.h"
#include "glm/vec4.hpp"

struct CubeColoring {
    std::vector<Colors> colors;

    CubeColoring();

    enum Orientation {
        UP = 0,
        FRONT = 1,
        RIGHT = 2,
        BACK = 3,
        LEFT = 4,
        DOWN = 5
    };

    glm::vec4 getColor(Colors value) const;

    // Rotate the colors of the cube's faces clockwise on the X-axis (Left/Right)
    void rotateXClockwise();

    // Rotate the colors of the cube's faces counterclockwise on the X-axis (Left/Right)
    void rotateXCounterClockwise();

    // Rotate the colors of the cube's faces clockwise on the Y-axis (Up/Down)
    void rotateYClockwise();

    // Rotate the colors of the cube's faces counterclockwise on the Y-axis (Up/Down)
    void rotateYCounterClockwise();

    // Rotate the colors of the cube's faces clockwise on the Z-axis (Front/Back)
    void rotateZClockwise();

    // Rotate the colors of the cube's faces counterclockwise on the Z-axis (Front/Back)
    void rotateZCounterClockwise();
};

inline CubeColoring::CubeColoring()
{
    colors.resize(6);
    colors[0] = Colors::BLACK;  // UP
    colors[1] = Colors::BLACK;  // FRONT
    colors[2] = Colors::BLACK;  // RIGHT
    colors[3] = Colors::BLACK;  // BACK
    colors[4] = Colors::BLACK;  // LEFT
    colors[5] = Colors::BLACK;  // DOWN
}

inline glm::vec4 CubeColoring::getColor(Colors value) const
{
    switch (value) {
    case Colors::BLACK: return glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    case Colors::BLUE: return glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
    case Colors::WHITE: return glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    case Colors::GREEN: return glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
    case Colors::ORANGE: return glm::vec4(1.0f, 0.7f, 0.0f, 1.0f);
    case Colors::RED: return glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
    case Colors::YELLOW: return glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
    default: return glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    }
}

inline void CubeColoring::rotateXClockwise()
{
    // Rotate UP, FRONT, DOWN, BACK clockwise
    std::swap(colors[UP], colors[FRONT]);
    std::swap(colors[FRONT], colors[DOWN]);
    std::swap(colors[DOWN], colors[BACK]);
}

inline void CubeColoring::rotateXCounterClockwise()
{
    // Rotate UP, FRONT, DOWN, BACK counterclockwise
    std::swap(colors[UP], colors[BACK]);
    std::swap(colors[BACK], colors[DOWN]);
    std::swap(colors[DOWN], colors[FRONT]);
}

inline void CubeColoring::rotateYClockwise()
{
    // Rotate LEFT, FRONT, RIGHT, BACK clockwise
    std::swap(colors[LEFT], colors[FRONT]);
    std::swap(colors[FRONT], colors[RIGHT]);
    std::swap(colors[RIGHT], colors[BACK]);
}

inline void CubeColoring::rotateYCounterClockwise()
{
    // Rotate LEFT, FRONT, RIGHT, BACK counterclockwise
    std::swap(colors[LEFT], colors[BACK]);
    std::swap(colors[BACK], colors[RIGHT]);
    std::swap(colors[RIGHT], colors[FRONT]);
}

inline void CubeColoring::rotateZClockwise()
{
    // Rotate UP, LEFT, DOWN, RIGHT clockwise
    std::swap(colors[UP], colors[LEFT]);
    std::swap(colors[LEFT], colors[DOWN]);
    std::swap(colors[DOWN], colors[RIGHT]);
}

inline void CubeColoring::rotateZCounterClockwise()
{
    // Rotate UP, LEFT, DOWN, RIGHT counterclockwise
    std::swap(colors[UP], colors[RIGHT]);
    std::swap(colors[RIGHT], colors[DOWN]);
    std::swap(colors[DOWN], colors[LEFT]);
}
