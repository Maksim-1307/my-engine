#include "Camera.h"

#include <glm/ext.hpp>

namespace renderer{

Camera::Camera(int test){
    updateVectors();
    std::cout << "camera created" << std::endl;
}

void Camera::updateVectors(){
    front = vec3(rotation * vec4(0,0,-1,1));
	right = vec3(rotation * vec4(1,0,0,1));
	up = vec3(rotation * vec4(0,1,0,1));
	dir = vec3(rotation * vec4(0,0,-1,1));
    dir.y = 0;
	float len = length(dir);
	if (len > 0.0f){
		dir.x /= len;
		dir.z /= len;
	}
}

void Camera::rotate(float x, float y, float z){
    rotation = glm::rotate(rotation, x, glm::vec3(1,0,0));
    rotation = glm::rotate(rotation, y, glm::vec3(0,1,0));
    rotation = glm::rotate(rotation, z, glm::vec3(0,0,1));
}

void Camera::move(float x, float y, float z){
    position = position + vec3(x, y, z);
}

mat4 Camera::getView(){
    updateVectors();
    return lookAt(position, position + front, up);
}

}