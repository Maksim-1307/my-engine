#include "Camera.h"

#include <glm/ext.hpp>

namespace renderer{

Camera::Camera(){
    updateVectors();
}

void Camera::updateVectors(){

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
    updateVectors();
    return lookAt(position, position + front, up);
}

}