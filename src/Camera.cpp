#include "Camera.h"

glm::vec3 Camera::getPosition()
{
    return {
        distance * cos(horizontalAngle) * cos(verticalAngle), 
        distance * sin(verticalAngle),
        distance * sin(horizontalAngle) * cos(verticalAngle),                    
    };
}

void Camera::moveLeft()
{
    horizontalAngle += horizontalAngleStep;
}

void Camera::moveRight()
{
    horizontalAngle -= horizontalAngleStep;
}

void Camera::moveUp()
{
    verticalAngle += verticalAngleStep;
    verticalAngle = std::min(verticalAngle, 1.0f);
    verticalAngle = std::max(verticalAngle, -1.0f);
}

void Camera::moveDown()
{
    verticalAngle -= verticalAngleStep;
    verticalAngle = std::min(verticalAngle, 1.0f);
    verticalAngle = std::max(verticalAngle, -1.0f);
}

glm::mat4 Camera::getProjectionMatrix()
{
    return glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 1000.0f);
}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(getPosition(), targetPosition, up);
}

void Camera::setup(std::shared_ptr<Shader> shader)
{
    glm::mat4 projectionMatrix = getProjectionMatrix();
    glm::mat4 viewMatrix = getViewMatrix();
    shader->setMat4("projection", projectionMatrix);
    shader->setMat4("view", viewMatrix);
}
