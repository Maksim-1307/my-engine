
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
#include "input/Mouse.h"
#include "input/KeyHandler.h"
#include "graphics/Texture.h"
#include "time/FPSCounter.h"
#include "graphics/Sprite.h"


int main(int argc, char** argv){

    myutils::setCurrentDirectory(argv);

    renderer::WindowArgs windowArgs;
    windowArgs.name = "myEngine";

    renderer::Window window( windowArgs );


    GLfloat vertices[] = {
        0, 0, 0,
        1, 0, 0,
        1, 0, 1,
        0, 0, 1,
        0, 1, 0,
        1, 1, 0,
        1, 1, 1,
        0, 1, 1
    };
    GLuint indices[] = { 
        0, 1, 2,
        0, 3, 2,
        0, 4, 3,
        4, 7, 3,
        3, 7, 2,
        7, 2, 6,
        0, 1, 4,
        4, 1, 5,
        4, 5, 6,
        4, 6, 7,
        1, 2, 5,
        5, 2, 6
    };  

    GLfloat colors[]{
        1.0f, 0.f, 0.f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f
    };

    GLfloat texCoords[]{
        0, 0,
        1, 0,
        1, 1,
        0, 1,
        0, 0,
        1, 0,
        1, 1,
        0, 1,
    };

    std::string vShaderSource;
    std::string fShaderSource;

    myutils::readFile(SHADERS_PATH "shader-v.glsl", &vShaderSource);
    myutils::readFile(SHADERS_PATH "shader-f.glsl", &fShaderSource);

    renderer::ShaderProgram shaderProgram(vShaderSource, fShaderSource);



    graphics::Texture texture("res/textures/mytexture.jpg", 0);


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

    GLuint texture_VBO;
    glGenBuffers(1, &texture_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, texture_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);

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

    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, texture_VBO);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_TRUE, 2 * sizeof(GLfloat), (GLvoid*)0);

    glBindVertexArray(0); 


    renderer::Camera camera(window);
    input::Mouse mouse(window);


    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    model = glm::rotate(model, glm::radians(90.0f) , glm::vec3(1.0f, 0.0f, 0.0f));

    timemanager::FPSCounter fpsCounter(window, 10);


    std::string vShaderSource_2D;
    std::string fShaderSource_2D;

    myutils::readFile(SHADERS_PATH "shader2D-v.glsl", &vShaderSource_2D);
    myutils::readFile(SHADERS_PATH "test-f.glsl", &fShaderSource_2D);

    renderer::ShaderProgram shaderProgram2D(vShaderSource_2D, fShaderSource_2D);


    graphics::Texture testTexture("res/textures/mytexture2.jpg", 0);
    graphics::Sprite testSprite(testTexture, shaderProgram2D, glm::vec2(1, 1), FILL);
    testSprite.set_position(vec2(0.3f, -0.1f));


    while(!glfwWindowShouldClose(window.get_glfw_window())){

        fpsCounter.update();

        float deltaTime = fpsCounter.deltaTime;

        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        testSprite.render();

        shaderProgram.Use();

        glm::vec2 cameraRotation = mouse.update();

        camera.rotate(cameraRotation.x * deltaTime, cameraRotation.y * deltaTime, 0);


        input::process_keys(window, camera, deltaTime);


        view = camera.getView();
        projection = camera.getProjection();
        model = glm::rotate(model, glm::radians(10.0f) * deltaTime , glm::vec3(1.0f, 1.0f, 0.0f));

        shaderProgram.set_matrix4("model", model);
        shaderProgram.set_matrix4("view", view);
        shaderProgram.set_matrix4("projection", projection);

        shaderProgram.set_texture("Texture", texture.get_ID());

        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        glfwSwapBuffers(window.get_glfw_window());

    }

    glfwTerminate();

    return 0;
}

