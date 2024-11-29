#pragma once
#include <memory>

#include "Cube.h"
#include "Shader.h"
#include "Move.h"

class AnimationManager
{
    std::shared_ptr<Cube> cubes[3][3][3];
    
    bool animationRunning = false;
    float angle = 0;
    float step = 0.1f;
    Move move;
public:
    AnimationManager(std::shared_ptr<Cube> cubes[3][3][3])
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    this->cubes[i][j][k] = cubes[i][j][k];
                }
            }
        }
    }

    void startAnimation(Move move)
    {
        if (animationRunning == false)
        {
            this->move = move;
            animationRunning = true;
        }
    }
    
    void update()
    {
        if (animationRunning)
        {
            angle += step;
            if (angle >= glm::radians(90.0f)) {
                angle = glm::radians(90.0f);
                animationRunning = false;
                angle = 0;
            }
            if (angle <= glm::radians(-90.0f)) {
                angle = glm::radians(-90.0f);
                animationRunning = false;
                angle = 0;
            }

            switch (move)
            {
                case Move::UP: {rotateUp();break;}
                case Move::DOWN:{rotateDown();break;}
                case Move::FRONT:{rotateFront();break;}
                case Move::BACK:{rotateBack();break;}
                case Move::RIGHT:{rotateRight();break;}
                case Move::LEFT:{rotateLeft();break;}
                case Move::UP_REVERSE: {rotateUp(true);break;}
                case Move::DOWN_REVERSE:{rotateDown(true);break;}
                case Move::FRONT_REVERSE:{rotateFront(true);break;}
                case Move::BACK_REVERSE:{rotateBack(true);break;}
                case Move::RIGHT_REVERSE:{rotateRight(true);break;}
                case Move::LEFT_REVERSE:{rotateLeft(true);break;}
                default: break;
            }
        }
        else
        {
            
        }
    }

    void rotateUp(bool reverse = false)
    {
        int sign = 1;
        if (reverse)
        {
            sign = -1;
        }
        
        for (int i = 0; i < 3; i++)
        {
            int j = 2;
            for (int k = 0; k < 3; k++)
            {
                cubes[i][j][k]->rotate({0, -sign * step, 0});
                glm::vec4 pos = glm::vec4(cubes[i][j][k]->getPosition(), 1);
                glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), sign * step, glm::vec3(0, -1, 0));
                pos = rotationMatrix * pos;
                cubes[i][j][k]->setPosition(glm::vec3(pos));
            }
        }
    }

    void rotateDown(bool reverse = false)
    {
        int sign = 1;
        if (reverse)
        {
            sign = -1;
        }
        
        for (int i = 0; i < 3; i++)
        {
            int j = 0;
            for (int k = 0; k < 3; k++)
            {
                cubes[i][j][k]->rotate({0, sign * step, 0});
                glm::vec4 pos = glm::vec4(cubes[i][j][k]->getPosition(), 1);
                glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), sign * step, glm::vec3(0, 1, 0));
                pos = rotationMatrix * pos;
                cubes[i][j][k]->setPosition(glm::vec3(pos));
            }
        }
    }
    
    void rotateFront(bool reverse = false)
    {
        int sign = 1;
        if (reverse)
        {
            sign = -1;
        }
        
        for (int i = 0; i < 3; i++)
        {
            int k = 2;
            for (int j = 0; j < 3; j++)
            {
                cubes[i][j][k]->rotate({0, 0, -sign * step});
                glm::vec4 pos = glm::vec4(cubes[i][j][k]->getPosition(), 1);
                glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), sign * step, glm::vec3(0, 0, -1));
                pos = rotationMatrix * pos;
                cubes[i][j][k]->setPosition(glm::vec3(pos));
            }
        }
    }

    void rotateBack(bool reverse = false)
    {
        int sign = 1;
        if (reverse)
        {
            sign = -1;
        }
        
        for (int i = 0; i < 3; i++)
        {
            int k = 0;
            for (int j = 0; j < 3; j++)
            {
                cubes[i][j][k]->rotate({0, 0, sign * step,});
                glm::vec4 pos = glm::vec4(cubes[i][j][k]->getPosition(), 1);
                glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), sign * step, glm::vec3(0, 0, 1));
                pos = rotationMatrix * pos;
                cubes[i][j][k]->setPosition(glm::vec3(pos));
            }
        }
    }

    void rotateLeft(bool reverse = false)
    {
        int sign = 1;
        if (reverse)
        {
            sign = -1;
        }
        
        for (int k = 0; k < 3; k++)
        {
            int i = 0;
            for (int j = 0; j < 3; j++)
            {
                cubes[i][j][k]->rotate({sign * step, 0, 0});
                glm::vec4 pos = glm::vec4(cubes[i][j][k]->getPosition(), 1);
                glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), sign * step, glm::vec3(1, 0, 0));
                pos = rotationMatrix * pos;
                cubes[i][j][k]->setPosition(glm::vec3(pos));
            }
        }
    }

    void rotateRight(bool reverse = false)
    {
        int sign = 1;
        if (reverse)
        {
            sign = -1;
        }
        
        for (int k = 0; k < 3; k++)
        {
            int i = 2;
            for (int j = 0; j < 3; j++)
            {
                cubes[i][j][k]->rotate({-sign * step, 0, 0});
                glm::vec4 pos = glm::vec4(cubes[i][j][k]->getPosition(), 1);
                glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), sign * step, glm::vec3(-1, 0, 0));
                pos = rotationMatrix * pos;
                cubes[i][j][k]->setPosition(glm::vec3(pos));
            }
        }
    }
    
};
