#include "01-01-square/square-app.h"

SquareApp* SquareApp::instance = nullptr;

void SquareApp::run(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(windowPositionX, windowPositionY); // pozitia initiala a ferestrei
	glutInitWindowSize(windowWidth, windowHeight); //dimensiunile ferestrei
	glutCreateWindow(windowTitle.c_str()); // titlul ferestrei

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glewInit(); // nu uitati de initializare glew; trebuie initializat inainte de a a initializa desenarea

	initialize();

	glutDisplayFunc(renderFunction);
	glutCloseFunc(cleanup);
	glutMainLoop();
}

void SquareApp::initialize()
{
	squareShader = new Shader("shaders/square.vert", "shaders/square.frag");
	square = new Square();
}

void SquareApp::renderFunction()
{
	glClear(GL_COLOR_BUFFER_BIT);

	instance->squareShader->use();
	instance->square->render();
	instance->squareShader->remove();

	glFlush();
}

void SquareApp::cleanup()
{
	instance->square->cleanup();
}

SquareApp* SquareApp::getInstance() {
	if (instance == nullptr) {
		instance = new SquareApp();
	}
	return instance;
}


