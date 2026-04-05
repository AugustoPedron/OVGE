#pragma once

#include "Device/Device.hpp"
#include "GLFWImporter.hpp"

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

    void createSurface();

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, 
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);

    std::vector<const char*> getRequiredExtensions();

    void initVulkan();

    void initWindow();

    void mainLoop();

    void pickPhysicalDevice();

    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

    void setupDebugMessenger();

    std::shared_ptr<Device> m_device;

    VkDebugUtilsMessengerEXT m_debugMessenger;
    
    VkSurfaceKHR m_vkSurface;    

    VkInstance m_vkInstance;

    GLFWwindow* m_window;
    
};