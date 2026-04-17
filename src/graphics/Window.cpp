#include "Window.hpp"

int64_t glfwCount;


Window::Window(InstanceSettings& settings)
{
    if(glfwCount == 0){
        glfwInit();
    }
    glfwCount++;

    // add extensions to wishlist:
    uint32_t glfwExtensionCount = 0;
    auto glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    settings.extensions.insert(settings.extensions.end(),glfwExtensions,glfwExtensions+glfwExtensionCount);

    // check if the extensions are available
    vk::raii::Context context;
    auto extensionProperties = context.enumerateInstanceExtensionProperties();
    for (uint32_t i = 0; i < glfwExtensionCount; ++i)
    {
        if (std::ranges::none_of(extensionProperties,
                                [glfwExtension = glfwExtensions[i]](auto const& extensionProperty)
                                { return strcmp(extensionProperty.extensionName, glfwExtension) == 0; }))
        {
            throw std::runtime_error("Required GLFW extension not supported: " + std::string(glfwExtensions[i]));
        }
    }
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
    window = glfwCreateWindow(640, 720, "YAVoG", nullptr, nullptr);
    glfwSetWindowUserPointer(window,(void*)this);

    glfwSetCursorPosCallback(window,[](GLFWwindow* window,double xpos, double ypos){
        auto self = (Window*)glfwGetWindowUserPointer(window);
        self->onCursorPos( xpos,ypos);
    });
}
void Window::close(){
    glfwDestroyWindow(window);
    window = nullptr;
}
bool Window::update(){
    assert(window);
    return !glfwWindowShouldClose(window);
}
void Window::onCursorPos(double xpos, double ypos){
}
