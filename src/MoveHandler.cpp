#include "MoveHandler.h"

void MoveHandler::rotateFaceClockwise(std::shared_ptr<Cube>(& face)[3][3])
{
    auto temp = face[0][0];
    face[0][0] = face[2][0];
    face[2][0] = face[2][2];
    face[2][2] = face[0][2];
    face[0][2] = temp;

    temp = face[0][1];
    face[0][1] = face[1][0];
    face[1][0] = face[2][1];
    face[2][1] = face[1][2];
    face[1][2] = temp;
}

void MoveHandler::rotateFaceCounterClockwise(std::shared_ptr<Cube>(& face)[3][3])
{
    rotateFaceClockwise(face);
    rotateFaceClockwise(face);
    rotateFaceClockwise(face);
}

void MoveHandler::getFace(int axis, int index, std::shared_ptr<Cube>(& face)[3][3])
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (axis == 0)      // X-axis (LEFT/RIGHT)
                face[i][j] = cubes[index][i][j];
            else if (axis == 1) // Y-axis (UP/DOWN)
                face[i][j] = cubes[i][index][j];
            else if (axis == 2) // Z-axis (FRONT/BACK)
                face[i][j] = cubes[i][j][index];
        }
    }
}

void MoveHandler::setFace(int axis, int index, const std::shared_ptr<Cube>(& face)[3][3])
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (axis == 0)      // X-axis (LEFT/RIGHT)
                cubes[index][i][j] = face[i][j];
            else if (axis == 1) // Y-axis (UP/DOWN)
                cubes[i][index][j] = face[i][j];
            else if (axis == 2) // Z-axis (FRONT/BACK)
                cubes[i][j][index] = face[i][j];
        }
    }
}

void MoveHandler::rotateCubes(int axis, bool clockwise, std::shared_ptr<Cube>(& face)[3][3])
{
    int times = 1;
    if (clockwise == false)
    {
        times = 3;
    }
    switch (axis)
    {
    case 0:
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    face[i][j]->rotateXClockwise(times);
                }
            }
            break;
        }
    case 1:
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    face[i][j]->rotateYClockwise(times);
                }
            }
            break;
        }
    case 2:
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    face[i][j]->rotateZClockwise(times);
                }
            }
            break;
        }
    default: break;
    }
}

MoveHandler::MoveHandler(std::shared_ptr<Cube>(& cubes)[3][3][3]): cubes(cubes)
{}

void MoveHandler::performMove(Move move)
{
    std::shared_ptr<Cube> face[3][3];

    switch (move) {
    case Move::UP:
        getFace(1, 2, face);
        rotateFaceCounterClockwise(face);
        rotateCubes(1, true, face);
        setFace(1, 2, face);             
        break;

    case Move::UP_REVERSE:
        getFace(1, 2, face);
        rotateFaceClockwise(face);
        rotateCubes(1, false, face);
        setFace(1, 2, face);
        break;

    case Move::DOWN:
        getFace(1, 0, face);
        rotateFaceClockwise(face);
        rotateCubes(1, false, face);
        setFace(1, 0, face);
        break;

    case Move::DOWN_REVERSE:
        getFace(1, 0, face);
        rotateFaceCounterClockwise(face);
        rotateCubes(1, true, face);
        setFace(1, 0, face);
        break;

    case Move::LEFT:
        getFace(0, 0, face);
        rotateFaceCounterClockwise(face);
        rotateCubes(0, false, face);
        setFace(0, 0, face);
        break;

    case Move::LEFT_REVERSE:
        getFace(0, 0, face);
        rotateFaceClockwise(face);
        rotateCubes(0, true, face);
        setFace(0, 0, face);
        break;

    case Move::RIGHT:
        getFace(0, 2, face);
        rotateFaceClockwise(face);
        rotateCubes(0, true, face);
        setFace(0, 2, face);
        break;

    case Move::RIGHT_REVERSE:
        getFace(0, 2, face);
        rotateFaceCounterClockwise(face);
        rotateCubes(0, false, face);
        setFace(0, 2, face);
        break;

    case Move::FRONT:
        getFace(2, 2, face);
        rotateFaceClockwise(face);
        rotateCubes(2, true, face);
        setFace(2, 2, face);
        break;

    case Move::FRONT_REVERSE:
        getFace(2, 2, face);
        rotateFaceCounterClockwise(face);
        rotateCubes(2, false, face);
        setFace(2, 2, face);
        break;

    case Move::BACK:
        getFace(2, 0, face);
        rotateFaceCounterClockwise(face);
        rotateCubes(2, false, face);
        setFace(2, 0, face);
        break;

    case Move::BACK_REVERSE:
        getFace(2, 0, face);
        rotateFaceClockwise(face);
        rotateCubes(2, true, face);
        setFace(2, 0, face);
        break;

    default:
        throw std::invalid_argument("Invalid move");
    }
}
