#include <iostream>

#define GLEW_STATIC
#define GLM_FORCE_CTOR_INIT
#define SHADERS_PATH "res/shaders/"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

namespace input{

    class Mouse{

        public:

        Mouse(GLFWwindow* window);

        void set_mode(int mode){
            this->mode = mode;
        }

        int get_mode(){
            return mode;
        }

        // must be calling every frame
        vec2 update();

        double xpos, ypos;

        int screen_w = 640;
        int screen_h = 480;

        float speed = 10.0f;

        private:

        int mode = 0;


        GLFWwindow* window;

    };

}