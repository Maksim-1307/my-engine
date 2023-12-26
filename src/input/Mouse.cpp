#include "Mouse.h"

using namespace input;

Mouse::Mouse(renderer::Window& window) : window(window){
    this->window = window;
}

vec2 Mouse::update(){

    vec2 moving;

    glfwGetCursorPos(window.get_glfw_window(), &xpos, &ypos);
    glfwSetCursorPos(window.get_glfw_window(), window.get_width()/2, window.get_height()/2);

    moving.x = speed * float(window.get_width()/2 - xpos );
    moving.y = speed * float( window.get_height()/2 - ypos );

    return moving;

}