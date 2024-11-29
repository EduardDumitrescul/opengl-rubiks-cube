#include "Camera.h"

glm::mat4 Camera::getProjectionMatrix()
{
    return glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 1000.0f);
}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(position, targetPosition, up);
}

void Camera::setup(std::shared_ptr<Shader> shader)
{
    glm::mat4 projectionMatrix = getProjectionMatrix();
    glm::mat4 viewMatrix = getViewMatrix();
    shader->setMat4("projection", projectionMatrix);
    shader->setMat4("view", viewMatrix);
}
