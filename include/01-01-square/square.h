#pragma once

class Square {
	unsigned int vaoId;

	unsigned int verticesVboId;
	float vertices[24] = {
		0.5f,  0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 1.0f,
		0.5f,  0.5f, 0.0f, 1.0f
	};

	unsigned int colorsVboId;
	float colors[24] = {
		1.0f, 0.5f, 0.2f, 1.0f,
		1.0f, 0.5f, 0.2f, 1.0f,
		1.0f, 0.5f, 0.2f, 1.0f,
		1.0f, 0.5f, 0.2f, 1.0f,
		1.0f, 0.5f, 0.2f, 1.0f,
		1.0f, 0.5f, 0.2f, 1.0f,
	};
public:
	Square();

	void render();
	void cleanup();
};