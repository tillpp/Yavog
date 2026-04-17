#pragma once
#include <vulkan/vulkan_raii.hpp>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <atomic>

class Window
{
    GLFWwindow *window = nullptr;
public:
    Window();
    Window(const Window&)=delete;
    ~Window();

    void create();
    void close();
    bool update();
};
