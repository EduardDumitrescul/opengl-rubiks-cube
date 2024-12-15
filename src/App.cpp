#include "App.h"

#include "GL/glew.h"
#include <GL/freeglut.h>

#include "CubeFactory.h"

std::shared_ptr<App> App::instance = nullptr;

void App::run(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(windowPositionX, windowPositionY);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow(title.c_str());
    glDepthMask(GL_TRUE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK); 
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glewInit();

    initialize();

    glutTimerFunc(16, instance->timerFunction, 0);
    glutSpecialFunc(specialKeyFunction);
    glutKeyboardFunc(keyboardFunction);
    glutDisplayFunc(renderFunction);
    glutCloseFunc(cleanup);
    glutMainLoop();
}


void App::initialize()
{
    camera = std::make_unique<Camera>();
    shader = std::make_shared<Shader>("shaders/app.vert", "shaders/app.frag");
    rubik = std::make_shared<Rubik>();
    shuffler = std::make_unique<RubikShuffler>(rubik);
    solver = std::make_unique<Solver>(rubik);
}

void App::timerFunction(int value)
{
    glutPostRedisplay(); // Request a redraw
    glutTimerFunc(16, timerFunction, 0); // Schedule next timer event in ~16ms
}

void App::keyboardFunction(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'u': {instance->rubik->performMove(Move::UP, []{});break;}
        case 'd':{instance->rubik->performMove(Move::DOWN, []{});break;}
        case 'l':{instance->rubik->performMove(Move::LEFT, []{});break;}
        case 'r':{instance->rubik->performMove(Move::RIGHT, []{});break;}
        case 'f':{instance->rubik->performMove(Move::FRONT, []{});break;}
        case 'b': {instance->rubik->performMove(Move::BACK, []{});break;}
        case 'U': {instance->rubik->performMove(Move::UP_REVERSE, []{});break;}
        case 'D':{instance->rubik->performMove(Move::DOWN_REVERSE, []{});break;}
        case 'L':{instance->rubik->performMove(Move::LEFT_REVERSE, []{});break;}
        case 'R':{instance->rubik->performMove(Move::RIGHT_REVERSE, []{});break;}
        case 'F':{instance->rubik->performMove(Move::FRONT_REVERSE, []{});break;}
        case 'B': {instance->rubik->performMove(Move::BACK_REVERSE, []{});break;}
        case '1': {instance->shuffler->shuffle(); break;}
        case '2': {instance->solver->run(); break;}
        case '-': {instance->camera->decreaseDistance(); break;}
        case '=': {instance->camera->increaseDistance(); break;}
        default: break;
    }
}

void App::specialKeyFunction(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        instance->camera->moveLeft();
        break;
    case GLUT_KEY_UP:
        instance->camera->moveUp();
        break;
    case GLUT_KEY_RIGHT:
        instance->camera->moveRight();
        break;
    case GLUT_KEY_DOWN:
        instance->camera->moveDown();
        break;
    }
}

void App::renderFunction()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable (GL_DEPTH_TEST);
    
    instance->shader->use();
    instance->camera->setup(instance->shader);
    instance->shader->setVec3("lightPos", glm::vec3(10.0f, 10.0f, 10.0f));
    instance->shader->setVec3("viewPos", instance->camera->getPosition());
    instance->shader->setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
    instance->shader->setVec3("fogColor", glm::vec3(0.2f, 0.2f, 0.2f)); // Fog color
    instance->shader->setFloat("density", 0.05f);
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