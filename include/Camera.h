#pragma once
#include <memory>

#include "Shader.h"
#include "glm/fwd.hpp"
#include "glm/vec3.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"

class Camera
{
    float distance = 15;
    float distanceStep = 0.25;
    float horizontalAngle = 0;
    float horizontalAngleStep = 0.1;
    float verticalAngle = 0;
    float verticalAngleStep = 0.01;
    
    glm::vec3 targetPosition = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

    glm::mat4 getProjectionMatrix();

    glm::mat4 getViewMatrix();
public:
    void moveLeft();

    void moveRight();

    void moveUp();

    void moveDown();

    void increaseDistance();

    void decreaseDistance();

    glm::vec3 getPosition();
    
    void setup(std::shared_ptr<Shader> shader);
};
