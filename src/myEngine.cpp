
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

#include "constants.h"
#include "myutils/fileReader.h"
#include "renderer/ShaderProgram.h"
#include "renderer/Window.h"
#include "renderer/Camera.h"
#include "input/Mouse.h"
#include "input/KeyHandler.h"
#include "graphics/Texture.h"
#include "time/FPSCounter.h"
#include "graphics/Sprite.h"
#include "graphics/Mesh.h"


int main(int argc, char** argv){

    myutils::setCurrentDirectory(argv);

    renderer::WindowArgs windowArgs;
    windowArgs.name = "myEngine";

    renderer::Window window( windowArgs );


    GLfloat vertices[] = {
    //  x  y  z    UV
        0, 0, 0,   0, 0,
        1, 0, 0,   1, 0,
        1, 0, 1,   1, 1,
        0, 0, 1,   0, 1,
        0, 1, 0,   0, 0,
        1, 1, 0,   1, 0,
        1, 1, 1,   1, 1,
        0, 1, 1,   0, 1,

        0, 0, 2,   0, 0,
        1, 0, 2,   1, 0,
        1, 0, 3,   1, 1,
        0, 0, 3,   0, 1,
        0, 1, 2,   0, 0,
        1, 1, 2,   1, 0,
        1, 1, 3,   1, 1,
        0, 1, 3,   0, 1,

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
        5, 2, 6,

        9, 10, 11, 
        9, 12, 11, 
        9, 13, 12, 
        13, 16, 12, 
        12, 16, 11, 
        16, 11, 15, 
        9, 10, 13, 
        13, 10, 14, 
        13, 14, 15, 
        13, 15, 16, 
        10, 11, 14, 
        14, 11, 15
    };  

    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 3; j++){
            std::cout << indices[i*3 + j] + 9 << ", ";
        } std::cout << std::endl;
    }


    std::string vShaderSource;
    std::string fShaderSource;

    myutils::readFile(SHADERS_PATH "shader-v.glsl", &vShaderSource);
    myutils::readFile(SHADERS_PATH "shader-f.glsl", &fShaderSource);

    renderer::ShaderProgram shaderProgram(vShaderSource, fShaderSource);



    graphics::Texture texture("res/textures/mytexture.jpg", 0);


    glEnable(GL_DEPTH_TEST);


    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, VERTEX_SIZE * sizeof(GLfloat), (GLvoid*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_TRUE, VERTEX_SIZE * sizeof(GLfloat), (GLvoid*)((VERTEX_SIZE - 2) * sizeof(GLfloat)));

    glBindVertexArray(0); 
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


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


    graphics::Texture testTexture("res/textures/mypng.png", 0);
    graphics::Sprite testSprite(testTexture, shaderProgram2D, glm::vec2(0.5, 0.5), FILL);
    testSprite.set_position(vec2(0.5f, 0.5f));

    graphics::Texture fontTexture("res/fonts/myfont/image.png", 0);
    graphics::Sprite fontSprite(fontTexture, shaderProgram2D, glm::vec2(0.05, 0.11), FILL);
    fontSprite.set_position(vec2(-1.0f, 0.8f));


    graphics::Mesh cubeMesh(texture, vertices, sizeof(vertices), indices, sizeof(indices));
    


    while(!glfwWindowShouldClose(window.get_glfw_window())){

        fpsCounter.update();

        float deltaTime = fpsCounter.deltaTime;

        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        testSprite.render();
        fontSprite.render();

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

        cubeMesh.draw();

        glfwSwapBuffers(window.get_glfw_window());

    }

    glfwTerminate();

    return 0;
}

