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

        this->height = args.height;
        this->width = args.width;

        this->GLFWwindow = glfwCreateWindow(width, height, args.name.c_str(), nullptr, nullptr);

        if (!GLFWwindow){
            std::cerr << "ERROR: failed to create a GLFW window" << std::endl;
            exit(-1);
        }

        glfwMakeContextCurrent(GLFWwindow);
        glfwSetWindowSizeCallback(GLFWwindow, windowSizeCallback);

        glewExperimental = GL_TRUE;
        GLenum gl_err = glewInit();
        if (gl_err != GLEW_OK) {
            std::cerr << "ERROR: failed to initialize GLEW" << std::endl;
            exit(-1);
        }

        glClearColor(0.3f, 0.3f, 0.5f, 1.0f);

        glfwSetInputMode(this->GLFWwindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
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