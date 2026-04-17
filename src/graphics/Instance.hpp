#pragma once
#define VULKAN_HPP_NO_STRUCT_CONSTRUCTORS
#include <vulkan/vulkan_raii.hpp>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <atomic>

struct InstanceSettings{
    std::vector<const char*> extensions;
    std::vector<const char*> layers;
    vk::InstanceCreateFlags flags;
};

class Instance
{
    vk::raii::Context  context;
    vk::raii::Instance instance = nullptr;
public:
    std::vector<int> extension;

    Instance(/* args */);
    ~Instance();

    void create(InstanceSettings extensions);

};