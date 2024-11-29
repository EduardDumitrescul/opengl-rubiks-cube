#pragma once
#include <memory>
#include <string>

#include "CubeRenderer.h"
#include "Shader.h"

class App
{
    static std::shared_ptr<App> instance;

    int windowPositionX = 100, windowPositionY = 100;
    int windowWidth = 800, windowHeight = 600;
    std::string title = "OpenGL Rubik's Cube";

    std::shared_ptr<Shader> shader;
    std::unique_ptr<CubeRenderer> cubeRenderer;
    
    void initialize();
    static void renderFunction();
    static void cleanup();
public:
    static std::shared_ptr<App> getInstance();
    void run(int argc, char** argv);
};
