#include "Rubik.h"

Rubik::Rubik()
{
    
    for (int i = 0; i < 3; i ++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                CubeColoring coloring;
                if (k == 0) {
                    coloring.colors[CubeColoring::BACK] = Colors::RED;
                }
                if (k == 2)
                {
                    coloring.colors[CubeColoring::FRONT] = Colors::ORANGE;
                }
                if (j == 0) {
                    coloring.colors[CubeColoring::DOWN] = Colors::YELLOW;
                }
                if (j == 2) {
                    coloring.colors[CubeColoring::UP] = Colors::WHITE;
                }
                if (i == 0) {
                    coloring.colors[CubeColoring::LEFT] = Colors::GREEN;
                }
                if (i == 2) {
                    coloring.colors[CubeColoring::RIGHT] = Colors::BLUE;
                }

                cubes[i][j][k] = CubeFactory::createCube({0.8, 0.8, 0.8}, {i-1, j-1, k-1}, coloring);
            }
        }
    }
}

void Rubik::render(std::shared_ptr<Shader> shader)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++) {
                cubes[i][j][k]->render(shader);
            }
        }
    }
}

void Rubik::cleanup()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cubes[i][j][k]->cleanup();
            }
        }
    }
}
