#pragma once

#include "GLFWImporter.hpp"

#include <optional>
#include <vector>

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

class Device{
public:

    Device(const VkInstance* vkInstance, const VkSurfaceKHR* vkSurface);

    ~Device();
    
private:
    void cleanup();

    void createLogicalDevice();

    QueueFamilyIndices findQueueFamilies(const VkPhysicalDevice& device);    

    bool isDeviceSuitable(const VkPhysicalDevice& device);

    void pickPhysicalDevice();

    bool rateDeviceSuitability(const VkPhysicalDevice& device);

    std::vector<VkQueueFamilyProperties> m_queueFamilies;

    const VkInstance* m_vkInstance;

    const VkSurfaceKHR* m_vkSurface;

    VkPhysicalDevice m_physicalDevice;

    VkDevice m_logicalDevice;

    VkQueue m_graphicsQueue;

    VkQueue m_presentQueue;

    QueueFamilyIndices m_deviceQueueIndices;

};