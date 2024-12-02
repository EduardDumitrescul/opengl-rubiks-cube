#pragma once
#include <memory>
#include <string>

#include "Camera.h"
#include "Cube.h"
#include "Shader.h"

#include "CubeRenderer.h"
#include "Rubik.h"
#include "RubikShuffler.h"


class App
{
    static std::shared_ptr<App> instance;

    int windowPositionX = 100, windowPositionY = 100;
    int windowWidth = 800, windowHeight = 600;
    std::string title = "OpenGL Rubik's Cube";

    std::unique_ptr<Camera> camera;
    std::shared_ptr<Shader> shader;
    std::shared_ptr<Rubik> rubik;

    std::shared_ptr<RubikShuffler> shuffler;
    
    void initialize();

    static void timerFunction(int value);
    static void keyboardFunction(unsigned char key, int x, int y);
    static void specialKeyFunction(int key, int x, int y);
    static void renderFunction();
    static void cleanup();
public:
    static std::shared_ptr<App> getInstance();
    void run(int argc, char** argv);
};
