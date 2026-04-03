#include "Window/BaseWindow.hpp"

#include <string>

using namespace std;

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;
const string WINDOW_NAME = "OVGE";

BaseWindow::BaseWindow(): m_window(nullptr)
{

}

BaseWindow::~BaseWindow()
{
    /*if(m_window)
    {
        m_window.reset(nullptr);
    }*/
}

void BaseWindow::cleanup()
{
    glfwDestroyWindow(m_window);

    glfwTerminate();
}

void BaseWindow::initVulkan()
{

}

void BaseWindow::initWindow()
{
    glfwInit();
    
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    m_window = glfwCreateWindow(WIDTH, HEIGHT, WINDOW_NAME.c_str(), nullptr, nullptr);
}

void BaseWindow::mainLoop()
{
    while (!glfwWindowShouldClose(m_window)) {
        glfwPollEvents();
    }
}

void BaseWindow::run()
{
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}