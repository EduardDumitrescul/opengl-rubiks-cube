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
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
}

void CubeRenderer::render(std::shared_ptr<Shader> shader, glm::vec3 size, glm::vec3 pos, CubeColoring coloring) const
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, pos);
    model = glm::scale(model, size);
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
