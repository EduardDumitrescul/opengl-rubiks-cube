#include "Rubik.h"

#include "CubeFactory.h"

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

    animationManager = std::make_shared<AnimationManager>(cubes);
    moveHandler = std::make_shared<MoveHandler>(cubes);
}

bool Rubik::isBusy()
{
    return busy;
}

void Rubik::performMove(Move move, std::function<void()>onMoveFinished, bool animation)
{
    if (animation == false)
    {
        moveHandler->performMove(move);
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    cubes[i][j][k]->removeRotation();
                    cubes[i][j][k]->setPosition({i-1, j-1, k-1});
                }
            }
        }
        return;
    }
    auto callback = [this, move, onMoveFinished]() {
        moveHandler->performMove(move);

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    cubes[i][j][k]->removeRotation();
                    cubes[i][j][k]->setPosition({i-1, j-1, k-1});
                }
            }
        }
        onMoveFinished();
    };
    animationManager->startAnimation(move, callback);

    
}

void Rubik::render(std::shared_ptr<Shader> shader, int deltaTime)
{
    animationManager->update(deltaTime);
    shader->setBool("drawShadow", false);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++) {
                cubes[i][j][k]->render(shader);
            }
        }
    }
    shader->setBool("drawShadow", true);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++) {
                cubes[i][j][k]->render(shader);
            }
        }
    }
    shader->setBool("drawShadow", false);
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

Rubik& Rubik::operator=(const Rubik& other)
{
    if (this == &other) {  // Check for self-assignment
        return *this;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                this->cubes[i][j][k] = std::make_shared<Cube>(*other.cubes[i][j][k]);
            }
        }
    }

    // Copy the simple data members
    this->busy = other.busy;

    // Copy the moveHandler and animationManager (deep copy)
    this->moveHandler = std::make_unique<MoveHandler>(this->cubes);
    this->animationManager = std::make_unique<AnimationManager>(this->cubes);

    return *this;  // Return *this to allow chained assignments
}

Rubik::Rubik(const Rubik& other)
{
    this->busy = other.busy;
        
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Create a new shared_ptr to a copy of the Cube
                this->cubes[i][j][k] = std::make_shared<Cube>(*other.cubes[i][j][k]);
            }
        }
    }
    // Create new unique_ptrs by copying the objects they point to
    this->moveHandler = std::make_unique<MoveHandler>(this->cubes);
    this->animationManager = std::make_unique<AnimationManager>(this->cubes);

    // Deep copy of cubes array
}

bool Rubik::operator<(const Rubik& other) const
{
    return toString() < other.toString();
}

bool Rubik::operator==(const Rubik& other) const
{
    return toString() == other.toString();
}

std::string Rubik::toString() const
{
    std::string string = "";
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                string += cubes[i][j][k]->toString();
            }
        }
    }
    return string;
}

bool Rubik::isSolved()
{
    // Define the center piece positions for each face
    // We check the color of the center cube for each face and compare others to it.

    // Check the front face (center at [1][1][2])
    CubeColoring frontColor = cubes[1][1][2]->getColoring();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (cubes[i][j][2]->getColoring().colors[CubeColoring::FRONT] != frontColor.colors[CubeColoring::FRONT]) {
                return false;
            }
        }
    }

    // Check the back face (center at [1][1][0])
    CubeColoring backColor = cubes[1][1][0]->getColoring();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (cubes[i][j][0]->getColoring().colors[CubeColoring::BACK] != backColor.colors[CubeColoring::BACK]) {
                return false;
            }
        }
    }

    // Check the top face (center at [1][2][1])
    CubeColoring upColor = cubes[1][2][1]->getColoring();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (cubes[i][2][j]->getColoring().colors[CubeColoring::UP] != upColor.colors[CubeColoring::UP]) {
                return false;
            }
        }
    }

    // Check the bottom face (center at [1][0][1])
    CubeColoring downColor = cubes[1][0][1]->getColoring();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (cubes[i][0][j]->getColoring().colors[CubeColoring::DOWN] != downColor.colors[CubeColoring::DOWN]) {
                return false;
            }
        }
    }

    // Check the left face (center at [0][1][1])
    CubeColoring leftColor = cubes[0][1][1]->getColoring();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (cubes[0][j][i]->getColoring().colors[CubeColoring::LEFT] != leftColor.colors[CubeColoring::LEFT]) {
                return false;
            }
        }
    }

    // Check the right face (center at [2][1][1])
    CubeColoring rightColor = cubes[2][1][1]->getColoring();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (cubes[2][j][i]->getColoring().colors[CubeColoring::RIGHT] != rightColor.colors[CubeColoring::RIGHT]) {
                return false;
            }
        }
    }

    // If all checks pass, the Rubik's cube is solved
    return true;
}
