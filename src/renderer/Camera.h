#include <iostream>

#define GLM_FORCE_CTOR_INIT

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

namespace renderer{

    class Camera{

        void updateVectors();

        public:

        vec3 position = vec3(0,0,3);
        vec3 front;
        vec3 right;
        vec3 up;
        vec3 dir;
        float fov = 45.0f;
        float zoom = 1.0f;

        mat4 rotation = mat4(1.0f);

        Camera();

        mat4 getView();

        mat4 getProjection();

        void move(float x, float y, float z);

        void rotate(float x, float y, float z);


    };

}