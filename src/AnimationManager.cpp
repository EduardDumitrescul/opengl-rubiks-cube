#include "AnimationManager.h"

int AnimationManager::animationDuration = 250;

AnimationManager::AnimationManager(std::shared_ptr<Cube>(& cubes)[3][3][3]): cubes(cubes)
{
}

void AnimationManager::startAnimation(Move move, std::function<void()> callback)
{
    if (animationRunning == false)
    {
        this->animationProgress = 0;
        this->move = move;
        animationRunning = true;
        this->animationFinishedCallback = callback;
    }
}

void AnimationManager::update(int deltaTimestamp)
{
    if (animationRunning)
    {
        animationProgress += deltaTimestamp;
        if (animationProgress >= animationDuration)
        {
            animationProgress = animationDuration;
            animationRunning = false;
            animationFinishedCallback();
            return;
        }   
        
        // if (angle >= glm::radians(90.0f)) {
        //     angle = glm::radians(90.0f);
        //     animationRunning = false;
        //     animationFinishedCallback();
        //     // animationFinishedCallback = nullptr;
        //     angle = 0;
        //     return;
        // }
        // if (angle <= glm::radians(-90.0f)) {
        //     angle = glm::radians(-90.0f);
        //     animationRunning = false;
        //     animationFinishedCallback();
        //     // animationFinishedCallback = nullptr;
        //     angle = 0;
        //     return;
        // }

        switch (move)
        {
        case Move::UP: {rotateUp(false, deltaTimestamp);break;}
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
void AnimationManager::rotateUp(bool reverse, int deltaTime)
{
    float sign = -1;
    if (reverse)
    {
        sign = 1;
    }

    for (int i = 0; i < 3; i++)
    {
        int j = 2;
        for (int k = 0; k < 3; k++)
        {
            glm::quat deltaRotation = glm::angleAxis(glm::radians(90.0f) * sign, glm::vec3(0.0f, 1.0f, 0.0f));
            glm::quat interpolatedRotation = glm::slerp({1, 0, 0, 0}, deltaRotation, 1.0f * animationProgress / animationDuration);
            cubes[i][j][k]->setAnimationRotation(interpolatedRotation);
            
            glm::vec3 currentPosition = cubes[i][j][k]->getPosition();
            glm::vec3 positionRelativeToAxis = glm::vec3(currentPosition.x, 0.0f, currentPosition.z);
            glm::vec3 rotatedPosition = interpolatedRotation * positionRelativeToAxis;
            cubes[i][j][k]->setAnimationPosition(rotatedPosition - positionRelativeToAxis );

        }
    }
}

void AnimationManager::rotateDown(bool reverse)
{
    float sign = 1;
    if (reverse)
    {
        sign = -1;
    }
        
    for (int i = 0; i < 3; i++)
    {
        int j = 0;
        for (int k = 0; k < 3; k++)
        {
            glm::quat deltaRotation = glm::angleAxis(glm::radians(90.0f) * sign, glm::vec3(0.0f, 1.0f, 0.0f));
            glm::quat interpolatedRotation = glm::slerp({1, 0, 0, 0}, deltaRotation, 1.0f * animationProgress / animationDuration);
            cubes[i][j][k]->setAnimationRotation(interpolatedRotation);
            
            glm::vec3 currentPosition = cubes[i][j][k]->getPosition();
            glm::vec3 positionRelativeToAxis = glm::vec3(currentPosition.x, 0.0f, currentPosition.z);
            glm::vec3 rotatedPosition = interpolatedRotation * positionRelativeToAxis;
            cubes[i][j][k]->setAnimationPosition(rotatedPosition - positionRelativeToAxis );
        }
    }
}

void AnimationManager::rotateFront(bool reverse)
{
    float sign = -1;
    if (reverse)
    {
        sign = 1;
    }
        
    for (int i = 0; i < 3; i++)
    {
        int k = 2;
        for (int j = 0; j < 3; j++)
        {
            glm::quat deltaRotation = glm::angleAxis(glm::radians(90.0f) * sign, glm::vec3(0.0f, 0.0f, 1.0f));
            glm::quat interpolatedRotation = glm::slerp({1, 0, 0, 0}, deltaRotation, 1.0f * animationProgress / animationDuration);
            cubes[i][j][k]->setAnimationRotation(interpolatedRotation);
            
            glm::vec3 currentPosition = cubes[i][j][k]->getPosition();
            glm::vec3 positionRelativeToAxis = glm::vec3(currentPosition.x, currentPosition.y, 0.0f);
            glm::vec3 rotatedPosition = interpolatedRotation * positionRelativeToAxis;
            cubes[i][j][k]->setAnimationPosition(rotatedPosition - positionRelativeToAxis );
        }
    }
}

void AnimationManager::rotateBack(bool reverse)
{
    float sign = 1;
    if (reverse)
    {
        sign = -1;
    }
        
    for (int i = 0; i < 3; i++)
    {
        int k = 0;
        for (int j = 0; j < 3; j++)
        {
            glm::quat deltaRotation = glm::angleAxis(glm::radians(90.0f) * sign, glm::vec3(0.0f, 0.0f, 1.0f));
            glm::quat interpolatedRotation = glm::slerp({1, 0, 0, 0}, deltaRotation, 1.0f * animationProgress / animationDuration);
            cubes[i][j][k]->setAnimationRotation(interpolatedRotation);
            
            glm::vec3 currentPosition = cubes[i][j][k]->getPosition();
            glm::vec3 positionRelativeToAxis = glm::vec3(currentPosition.x, currentPosition.y, 0.0f);
            glm::vec3 rotatedPosition = interpolatedRotation * positionRelativeToAxis;
            cubes[i][j][k]->setAnimationPosition(rotatedPosition - positionRelativeToAxis );
        }
    }
}

void AnimationManager::rotateLeft(bool reverse)
{
    float sign = 1;
    if (reverse)
    {
        sign = -1;
    }
        
    for (int k = 0; k < 3; k++)
    {
        int i = 0;
        for (int j = 0; j < 3; j++)
        {
            glm::quat deltaRotation = glm::angleAxis(glm::radians(90.0f) * sign, glm::vec3(1.0f, 0.0f, 0.0f));
            glm::quat interpolatedRotation = glm::slerp({1, 0, 0, 0}, deltaRotation, 1.0f * animationProgress / animationDuration);
            cubes[i][j][k]->setAnimationRotation(interpolatedRotation);
            
            glm::vec3 currentPosition = cubes[i][j][k]->getPosition();
            glm::vec3 positionRelativeToAxis = glm::vec3(0, currentPosition.y, currentPosition.z);
            glm::vec3 rotatedPosition = interpolatedRotation * positionRelativeToAxis;
            cubes[i][j][k]->setAnimationPosition(rotatedPosition - positionRelativeToAxis );
        }
    }
}

void AnimationManager::rotateRight(bool reverse)
{
    float sign = -1;
    if (reverse)
    {
        sign = 1;
    }
        
    for (int k = 0; k < 3; k++)
    {
        int i = 2;
        for (int j = 0; j < 3; j++)
        {
            glm::quat deltaRotation = glm::angleAxis(glm::radians(90.0f) * sign, glm::vec3(1.0f, 0.0f, 0.0f));
            glm::quat interpolatedRotation = glm::slerp({1, 0, 0, 0}, deltaRotation, 1.0f * animationProgress / animationDuration);
            cubes[i][j][k]->setAnimationRotation(interpolatedRotation);
            
            glm::vec3 currentPosition = cubes[i][j][k]->getPosition();
            glm::vec3 positionRelativeToAxis = glm::vec3(0, currentPosition.y, currentPosition.z);
            glm::vec3 rotatedPosition = interpolatedRotation * positionRelativeToAxis;
            cubes[i][j][k]->setAnimationPosition(rotatedPosition - positionRelativeToAxis );
        }
    }
}
