#pragma once
#include <vector>

#include "Colors.h"

struct CubeColoring {
    std::vector<Colors> colors;
    
    CubeColoring()
    {
        colors.resize(6);
        colors[0] = Colors::BLACK;
        colors[1] = Colors::BLACK;
        colors[2] = Colors::BLACK;
        colors[3] = Colors::BLACK;
        colors[4] = Colors::BLACK;
        colors[5] = Colors::BLACK;
    }
    

    enum Orientation {
        UP = 0,
        FRONT = 1,
        RIGHT = 2,
        BACK = 3,
        LEFT = 4,
        DOWN = 5
    };

    glm::vec4 getColor(Colors value) const
    {
        switch (value)
        {
        case BLACK: return glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        case BLUE: return glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
        case WHITE: return glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        case GREEN: return glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
        case ORANGE: return glm::vec4(1.0f, 0.7f, 0.0f, 1.0f);
        case RED: return glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
        case YELLOW: return glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
        default: return glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        }
    }
};
