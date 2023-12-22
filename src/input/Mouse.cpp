#include "Mouse.h"

using namespace input;

Mouse::Mouse(GLFWwindow* window){
    this->window = window;
}

vec2 Mouse::update(){

    vec2 moving;

    glfwGetCursorPos(window, &xpos, &ypos);
    glfwSetCursorPos(window, screen_w/2, screen_h/2);

    moving.x = speed * float(screen_w/2 - xpos );
    moving.y = speed * float( screen_h/2 - ypos );

    return moving / 100.0f;

}