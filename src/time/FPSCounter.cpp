#include "FPSCounter.h"

using namespace timemanager;

FPSCounter::FPSCounter(renderer::Window& window, unsigned int interval) : window(window){
    this->window = window;
    this->FPSinterval = interval;
    this->llastTime = glfwGetTime();
} 

void FPSCounter::update(){
    lastTime = currentTime;
    currentTime = glfwGetTime();
    deltaTime = currentTime - lastTime;
    timeSum += deltaTime;
    frames += 1;
    if (timeSum >= (float)FPSinterval / 1000){
        FPS = (float)frames / timeSum;
        frames = 0;
        timeSum = 0;
    }

}

/*

FPS: 109
alternative FPS: 87.167
FPS: 109
alternative FPS: 196.17
FPS: 109
alternative FPS: 86.627
FPS: 109
alternative FPS: 184.763
FPS: 109
alternative FPS: 88.9906
FPS: 109
alternative FPS: 200.627
FPS: 109
alternative FPS: 85.6382
FPS: 109
alternative FPS: 197.101
FPS: 109
alternative FPS: 86.3986
FPS: 109
alternative FPS: 194.316
FPS: 109

*/