#include "Ground.h"

#include "glm/gtx/matrix_decompose.inl"

Ground::Ground()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float),  (void*)(4 * sizeof(float)));

}

void Ground::render(std::shared_ptr<Shader> shader) const
{
    glBindVertexArray(vao);
    
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, size);
    shader->setMat4("model", model);
    shader->setVec4("color", glm::vec4(231.0/255,236.0/255,163.0/255, 1));

    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void Ground::cleanup()
{
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &vbo);
    glBindVertexArray(0);
    glDeleteVertexArrays(1, &vao);
}
