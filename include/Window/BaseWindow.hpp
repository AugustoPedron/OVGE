#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <memory>

class BaseWindow {
public:

    BaseWindow();

    ~BaseWindow();

    void run();

private:
    void cleanup();

    void initVulkan();

    void initWindow();

    void mainLoop();

    GLFWwindow* m_window;
    
};