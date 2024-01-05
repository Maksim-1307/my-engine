#include "Mouse.h"

using namespace input;

Mouse::Mouse(renderer::Window& window) : window(window){
    this->window = window;

    glfwPollEvents();
    set_in_center();
}

vec2 Mouse::update(){

    vec2 moving;

    glfwGetCursorPos(window.get_glfw_window(), &xpos, &ypos);
    set_in_center();

    moving.x = speed * float(window.get_width()/2 - xpos );
    moving.y = speed * float( window.get_height()/2 - ypos );

    return moving;

}

void Mouse::set_in_center(){
    glfwSetCursorPos(window.get_glfw_window(), window.get_width() / 2, window.get_height() / 2);
}