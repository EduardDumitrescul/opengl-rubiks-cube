#include "App.h"

#include "GL/glew.h"
#include <GL/freeglut.h>

#include "CubeFactory.h"
#include "Rubik.h"

std::shared_ptr<App> App::instance = nullptr;

void App::run(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glutInitWindowPosition(windowPositionX, windowPositionY); // pozitia initiala a ferestrei
    glutInitWindowSize(windowWidth, windowHeight); //dimensiunile ferestrei
    glutCreateWindow(title.c_str()); // titlul ferestrei

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glewInit(); // nu uitati de initializare glew; trebuie initializat inainte de a a initializa desenarea

    initialize();

    glutDisplayFunc(renderFunction);
    glutCloseFunc(cleanup);
    glutMainLoop();
}


void App::initialize()
{
    camera = std::make_unique<Camera>();
    shader = std::make_shared<Shader>("shaders/app.vert", "shaders/app.frag");
    rubik = std::make_unique<Rubik>();
}

void App::renderFunction()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    instance->shader->use();

    instance->camera->setup(instance->shader);

    instance->rubik->render(instance->shader);

    glutSwapBuffers();
}

void App::cleanup()
{
    instance->rubik->cleanup();
}

std::shared_ptr<App> App::getInstance() {
    if (instance == nullptr) {
        instance = std::make_shared<App>();
    }
    return instance;
}