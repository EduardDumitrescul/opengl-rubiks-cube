#pragma once

#include <string>
#include "01-01-square/square.h"
#include "Shader.h"

class SquareApp {
	static SquareApp* instance;

	int windowPositionX = 100, windowPositionY = 100;
	int windowHeight = 600, windowWidth = 600;
	std::string windowTitle = "Grafica pe Calculator";

	Shader* squareShader = nullptr;
	Square* square = nullptr;

	void initialize();
	static void renderFunction();
	static void cleanup();
public:
	static SquareApp* getInstance();
	void run(int argc, char* argv[]);
};