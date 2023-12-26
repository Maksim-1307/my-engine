#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../renderer/Window.h"

namespace timemanager{
    class FPSCounter{
        public:

        FPSCounter(renderer::Window& window, unsigned int interval);

        // interval for calculating frames per second (in ms)
        unsigned int FPSinterval = 100;
        renderer::Window& window;

        // must be calling every frame
        void update();

        float get_FPS(){
            return this->FPS;
        };

        float lastTime = 0.0f;
        float currentTime = 0.0f;

        float deltaTime = 0.0f;

        private:
        unsigned int FPS = 0;
        unsigned int frames = 0;

        float llastTime = 0;

        // in seconds
        float timeSum = 0.0f;

    };
}