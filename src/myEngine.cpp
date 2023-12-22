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

#include "myutils/fileReader.h"
#include "renderer/ShaderProgram.h"
#include "renderer/Window.h"
#include "renderer/Camera.h"



int window_width = 640;
int window_height = 480;


struct camData{
    glm::vec3 position = glm::vec3(0,0,3);
    glm::vec3 front;
    glm::vec3 right;
    glm::vec3 up;
    glm::vec3 dir;
    float fov = 45.0f;
    float zoom = 1.0f;

    glm::mat4 rotation = glm::mat4(1.0f);
};


void updateVectors(camData& camData){
	camData.front = vec3(camData.rotation * vec4(0,0,-1,1));
	camData.right = vec3(camData.rotation * vec4(1,0,0,1));
	camData.up = vec3(camData.rotation * vec4(0,1,0,1));
	camData.dir = vec3(camData.rotation * vec4(0,0,-1,1));
	camData.dir.y = 0;
	float len = length(camData.dir);
	if (len > 0.0f){
		camData.dir.x /= len;
		camData.dir.z /= len;
	}
}

void move(camData& camData, glm::vec3 movement){
    camData.position = camData.position + movement;
}

void rotate(camData& camData, float x, float y, float z){
    camData.rotation = glm::rotate(camData.rotation, x, glm::vec3(1,0,0));
    camData.rotation = glm::rotate(camData.rotation, y, glm::vec3(0,1,0));
    camData.rotation = glm::rotate(camData.rotation, z, glm::vec3(0,0,1));
}

int main(int argc, char** argv){

    myutils::setCurrentDirectory(argv);

    renderer::WindowArgs windowArgs;
    windowArgs.name = "myEngine";

    renderer::Window window( windowArgs );

    glewExperimental = GL_TRUE;
    GLenum gl_err = glewInit();
    if (gl_err != GLEW_OK) {
        std::cerr << "ERROR: failed to initialize GLEW" << std::endl;
        exit(-1);
    }

    glClearColor(0.0f, .0f, 0.0f, 0.0f);

    renderer::Window& testWin = window;

    GLfloat vertices[] = {
        0.5f,  0.5f, 0.0f, 
        0.5f, -0.5f, 0.5f, 
        -0.5f, -0.5f, 0.0f, 
        -0.5f,  0.5f, 0.0f,
        0.5f,  0.5f, 0.0f, 
        0.5f, -0.5f, 0.5f, 
        -0.5f, -0.5f, 0.0f, 
        -0.5f,  0.5f, 0.0f   
    };
    GLuint indices[] = { 
        0, 1, 3,   
        1, 2, 3,
        3, 1, 0,   
        3, 2, 1   
    };  

    GLfloat colors[]{
        1.0f, 0.f, 0.f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f
    };

    std::string vShaderSource;
    std::string fShaderSource;

    myutils::readFile(SHADERS_PATH "shader-v.glsl", &vShaderSource);
    myutils::readFile(SHADERS_PATH "shader-f.glsl", &fShaderSource);

    const GLchar * vShaderSourceStr = vShaderSource.c_str();
    const GLchar * fShaderSourceStr = fShaderSource.c_str();

    renderer::ShaderProgram shaderProgram(vShaderSource, fShaderSource);

    glEnable(GL_DEPTH_TEST);

    GLuint EBO;
    glGenBuffers(1, &EBO);

    GLuint vertex_VBO;
    glGenBuffers(1, &vertex_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLuint color_VBO;
    glGenBuffers(1, &color_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, color_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 3 * sizeof(GLfloat), (GLvoid*)0);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, color_VBO);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

    glBindVertexArray(0); 


    //Camera data



    renderer::Camera camera(5); //data


    while(!glfwWindowShouldClose(window.get_glfw_window())){
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram.Use();


        camera.move(0,0,0.001f);


        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));


        glm::mat4 view = glm::mat4(1.0f);

        view = camera.getView();


        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 600.0f / 480.0f, 0.01f, 100.0f);


        GLuint modelLoc = glGetUniformLocation(shaderProgram.getID(), "model");
        GLuint viewLoc = glGetUniformLocation(shaderProgram.getID(), "view");
        GLuint projectionLoc = glGetUniformLocation(shaderProgram.getID(), "projection");

        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        glfwSwapBuffers(window.get_glfw_window());
    }

    glfwTerminate();

    return 0;
}

