#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <memory>
#include <vector>

class BaseWindow {
public:

    BaseWindow();

    ~BaseWindow();

    void run();

private:
    bool checkValidationLayerSupport();

    void cleanup();

    void createInstance();

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, 
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);

    std::vector<const char*> getRequiredExtensions();

    void initVulkan();

    void initWindow();

    void mainLoop();

    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

    void setupDebugMessenger();

    GLFWwindow* m_window;

    VkInstance m_vkInstance;

    VkDebugUtilsMessengerEXT m_debugMessenger;
    
};