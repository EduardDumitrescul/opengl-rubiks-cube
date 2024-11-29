#pragma once
#include <memory>

#include "Shader.h"
#include "glm/fwd.hpp"
#include "glm/vec3.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"

class Camera
{
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 14.0f);
    glm::vec3 targetPosition = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
public:
    glm::mat4 getProjectionMatrix();

    glm::mat4 getViewMatrix();

    void setup(std::shared_ptr<Shader> shader);
};
