#include "CubeRenderer.h"
#include "GL/glew.h"
#include "glm/gtx/matrix_decompose.inl"

CubeRenderer::CubeRenderer()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float),  (void*)(3 * sizeof(float)));
}

void CubeRenderer::render(std::shared_ptr<Shader> shader, glm::vec3 size, glm::vec3 pos, glm::vec3 rotation, CubeColoring coloring) const
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, pos);
    model = glm::scale(model, size);
    model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
    shader->setMat4("model", model);
    
    glBindVertexArray(vao);
    glLineWidth(2.0f);
    glm::vec4 color = coloring.getColor(coloring.colors[CubeColoring::RIGHT]);
    shader->setVec4("color", color);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    color = coloring.getColor(coloring.colors[CubeColoring::LEFT]);
    shader->setVec4("color", color);
    glDrawArrays(GL_TRIANGLE_FAN, 4, 4);
    color = coloring.getColor(coloring.colors[CubeColoring::UP]);
    shader->setVec4("color", color);
    glDrawArrays(GL_TRIANGLE_FAN, 8, 4);
    color = coloring.getColor(coloring.colors[CubeColoring::DOWN]);
    shader->setVec4("color", color);
    glDrawArrays(GL_TRIANGLE_FAN, 12, 4);
    color = coloring.getColor(coloring.colors[CubeColoring::FRONT]);
    shader->setVec4("color", color);
    glDrawArrays(GL_TRIANGLE_FAN, 16, 4);
    color = coloring.getColor(coloring.colors[CubeColoring::BACK]);
    shader->setVec4("color", color);
    glDrawArrays(GL_TRIANGLE_FAN, 20, 4);
}

void CubeRenderer::cleanup() const
{
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &vbo);
    glBindVertexArray(0);
    glDeleteVertexArrays(1, &vao);
}
