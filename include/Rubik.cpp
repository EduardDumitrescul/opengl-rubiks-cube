#include "Rubik.h"

Rubik::Rubik()
{
    for (int i = 0; i < 3; i ++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cubes[i][j][k] = CubeFactory::createCube({0.8, 0.8, 0.8}, {i-1, j-1, k-1});
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
