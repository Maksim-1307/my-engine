#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../renderer/Window.h"
#include "../renderer/Camera.h"

namespace input{

static void process_keys(renderer::Window& window, renderer::Camera& camera){

    int wKey = glfwGetKey(window.get_glfw_window(), GLFW_KEY_W);
    if (wKey == GLFW_PRESS){
        camera.move(0,0,-0.01f);
    }
    int aKey = glfwGetKey(window.get_glfw_window(), GLFW_KEY_A);
    if (aKey == GLFW_PRESS){
        camera.move(-0.01f,0,0);
    }
    int sKey = glfwGetKey(window.get_glfw_window(), GLFW_KEY_S);
    if (sKey == GLFW_PRESS){
        camera.move(0,0,0.01f);
    }
    int dKey = glfwGetKey(window.get_glfw_window(), GLFW_KEY_D);
    if (dKey == GLFW_PRESS){
        camera.move(0.01f,0,0);
    }
    int spaceKey = glfwGetKey(window.get_glfw_window(), GLFW_KEY_SPACE);
    if (spaceKey == GLFW_PRESS){
        camera.move(0,0.01f,0);
    }
    int shiftKey = glfwGetKey(window.get_glfw_window(), GLFW_KEY_LEFT_SHIFT);
    if (shiftKey == GLFW_PRESS){
        camera.move(0,-0.01f,0);
    }
}
}