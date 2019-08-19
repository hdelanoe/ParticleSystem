#include "System.hpp"

System::System()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    bind();
    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    glFinish();
}

void	System::bind(void)
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, NP * sizeof(particle), NULL, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(particle), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
