
#include "GameFolder.hpp"
#include "graphics/Window.hpp"

int main() {
    Window window;
    GameFolder gf;

    window.create();

    while(window.update()){
        glfwPollEvents();   
    }



    return 0;
}