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



int window_width = 640;
int window_height = 480;



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

    glm::mat4 projectionTest = glm::perspective(glm::radians(45.0f), 600.0f / 480.0f, 0.0f, 10.0f);
    glm::mat4 modelTest = glm::translate(modelTest, glm::vec3(0.0f, 0.0f, 0.5f));

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << projectionTest[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 12; i++){
        glm::vec4 testVec = glm::vec4(vertices[i*3], vertices[i*3 + 1], vertices[i*3 + 2], 1.0f);
        testVec = projectionTest * testVec;

        std::cout << "X Y Z W" << std::endl;

        std::cout << testVec.x << " " << testVec.y << " " << testVec.z << " " << testVec.w << std::endl;
    }

    // отвязываем VAO
    glBindVertexArray(0); 

    float bias = -10.0f;


    while(!glfwWindowShouldClose(window.get_glfw_window())){
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram.Use();

        bias = bias + 0.01;

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, bias));

        glm::mat4 view = glm::mat4(1.0f);
        view = glm::lookAt   
            (   
                glm::vec3(0, 0, 3),
                glm::vec3(0, 0, 0),
                glm::vec3(0, 1, 0)
            );
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