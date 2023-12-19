#include "Window.h"

namespace renderer{

    Window::Window( WindowArgs args ){
        if (!glfwInit()) {
            std::cerr << "ERROR: failed to initialize GLFW" << std::endl;
            exit(-1);
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        this->GLFWwindow = glfwCreateWindow(600, 400, args.name.c_str(), nullptr, nullptr);

        if (!GLFWwindow){
            std::cerr << "ERROR: failed to create a GLFW window" << std::endl;
            exit(-1);
        }

        glfwMakeContextCurrent(GLFWwindow);
        glfwSetWindowSizeCallback(GLFWwindow, windowSizeCallback);
    }
    Window::~Window(){
        glfwTerminate();
    }

    void windowSizeCallback(GLFWwindow* pWindow, int width, int height){
        int window_width = width;
        int window_height = height;
        glfwGetFramebufferSize(pWindow, &window_width, &window_height);
        glViewport(0, 0, window_width, window_height);
    }

}