#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace renderer{

    struct WindowArgs {
        std::string name = "window";
        GLuint width = 600;
        GLuint height = 480;
        bool isResizable = true;
    };

    class Window {

        public: 

        Window(WindowArgs args);
        ~Window();

        GLFWwindow* get_glfw_window(){
            return GLFWwindow;
        }

        bool is_OK(){
            return isOK;
        }

        private:

        GLuint width;
        GLuint height;

        GLFWwindow* GLFWwindow;
        bool isOK = false;

        

    };

    void windowSizeCallback(GLFWwindow* pWindow, int width, int height);

};