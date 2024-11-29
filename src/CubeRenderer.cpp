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

void CubeRenderer::render(std::shared_ptr<Shader> shader, glm::vec3 size, glm::vec3 pos) const
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, size);
    model = glm::translate(model, pos);
    shader->setMat4("model", model);
    
    glBindVertexArray(vao);
    glLineWidth(2.0f);
    glDrawArrays(GL_LINE_LOOP, 0, 4);
    glDrawArrays(GL_LINE_LOOP, 4, 4);
    glDrawArrays(GL_LINE_LOOP, 8, 4);
    glDrawArrays(GL_LINE_LOOP, 12, 4);
    glDrawArrays(GL_LINE_LOOP, 16, 4);
    glDrawArrays(GL_LINE_LOOP, 20, 4);
}

void CubeRenderer::cleanup() const
{
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &vbo);
    glBindVertexArray(0);
    glDeleteVertexArrays(1, &vao);
}
