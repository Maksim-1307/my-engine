#include "Camera.h"

#include <glm/ext.hpp>

namespace renderer{

Camera::Camera(Window& window) : window(window){
    std::cout << "horizontalRot is: " << horizontalRot << std::endl;
    this->window = window;
    updateVectors();
    std::cout << "horizontalRot after is: " << horizontalRot << std::endl;
}

void Camera::updateVectors(){

    std::cout << "horizontalRot is: " << horizontalRot << std::endl;

    front.x = cos(glm::radians(horizontalRot)) * cos(glm::radians(verticalRot));
    front.y = sin(glm::radians(verticalRot));
    front.z = sin(glm::radians(horizontalRot)) * cos(glm::radians(verticalRot));

    front = glm::normalize(front);
    right = glm::normalize(glm::cross(front, absoluteUp));
    up    = glm::normalize(glm::cross(right, front));

}

void Camera::rotate(float x, float y, float z){
    horizontalRot -= x;
    verticalRot += y;

    if (verticalRot < -89.99f){
        verticalRot = -89.99f;
    } else if (verticalRot > 89.99f){
        verticalRot = 89.99f;
    }
    
    updateVectors();
}

void Camera::move(float x, float y, float z){
    position = position - front * z;
    position = position + right * x;
    position = position + vec3(0,y,0);
    updateVectors();
}

mat4 Camera::getView(){
    return lookAt(position, position + front, up);
}

mat4 Camera::getProjection(){
    return perspective(glm::radians(fov), (float)window.get_width() / (float)window.get_height(), 0.01f, 1500.0f);
}

}