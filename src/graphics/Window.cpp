#include "Window.hpp"

int64_t glfwCount;


Window::Window(/* args */)
{
    if(glfwCount == 0){
        glfwInit();
    }
    glfwCount++;
}

Window::~Window()
{
    close();
    glfwCount--;
    if(glfwCount == 0){
        glfwTerminate();
    }
}
void Window::create(){
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window = glfwCreateWindow(640, 720, "YAVG", nullptr, nullptr);
}
void Window::close(){
    glfwDestroyWindow(window);
    window = nullptr;
}
bool Window::update(){
    assert(window);
    return !glfwWindowShouldClose(window);
}
