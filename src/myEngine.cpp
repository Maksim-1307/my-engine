
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

#include "voxels/Block.h"
#include "voxels/BlockFace.h"
#include "world/Chunk.h"

using namespace graphics;

BlockFace emptyBf;

BlockFace stoneFaces[]{
    BlockFace(),
    BlockFace(),
    BlockFace(),
    BlockFace(),
    BlockFace(),
    BlockFace()
};

void make_buffers(graphics::Mesh & mesh, GLuint & VBO, GLuint & VAO, GLuint & EBO){
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size() * sizeof(GLfloat), &mesh.vertices[0], GL_STATIC_DRAW);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_TRUE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

    glBindVertexArray(0); 
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() * sizeof(GLuint), &mesh.indices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void draw(GLuint & VAO, GLuint & EBO, int size){
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

int main(int argc, char **argv)
{

    myutils::setCurrentDirectory(argv);

    renderer::WindowArgs windowArgs;
    windowArgs.name = "myEngine";

    renderer::Window window(windowArgs);

    graphics::Mesh cubeMesh;

    Chunk chunk;
    chunk.generate();
    chunk.updateVoxels();


    // Block Air(0, getFaceAir);
    // Block Stone(1, getFaceStone);

    GLfloat* vertices;
    GLuint* indices;

    //setFaces();


    // BlockFace faceTop = Stone.getFace(0, Air.voxel);
    // vertices = &(faceTop.vertices[0]);
    // indices = &(faceTop.indices[0]);
    // int vertices_len = face.vertices.size();
    // int indices_len = face.indices.size();

    // for (int i = 0; i < 6; i++){
    //     Stone.getFace(i, Air.voxel, cubeMesh);
    // }

    GLuint vao;
    GLuint vbo;
    GLuint ebo;

    make_buffers(chunk.mesh, vbo, vao, ebo);



    std::string vShaderSource;
    std::string fShaderSource;
    myutils::readFile(SHADERS_PATH "shader-v.glsl", &vShaderSource);
    myutils::readFile(SHADERS_PATH "shader-f.glsl", &fShaderSource);

    renderer::ShaderProgram shaderProgram(vShaderSource, fShaderSource);

    graphics::Texture texture("res/textures/mytexture.jpg", 0);

    renderer::Camera camera(window);
    input::Mouse mouse(window);

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    model = glm::rotate(model, glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    timemanager::FPSCounter fpsCounter(window, 10);

    while (!glfwWindowShouldClose(window.get_glfw_window()))
    {

        fpsCounter.update();

        float deltaTime = fpsCounter.deltaTime;

        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram.Use();

        draw(vao, ebo, chunk.mesh.vertices.size());

        glm::vec2 cameraRotation = mouse.update();

        camera.rotate(cameraRotation.x * deltaTime, cameraRotation.y * deltaTime, 0);

        input::process_keys(window, camera, deltaTime);

        view = camera.getView();
        projection = camera.getProjection();
        //model = glm::rotate(model, glm::radians(10.0f) * deltaTime, glm::vec3(1.0f, 1.0f, 0.0f));

        shaderProgram.set_matrix4("model", model);
        shaderProgram.set_matrix4("view", view);
        shaderProgram.set_matrix4("projection", projection);
        shaderProgram.set_texture("Texture", texture.get_ID());

        std::cout << fpsCounter.get_FPS() << std::endl;

        glfwSwapBuffers(window.get_glfw_window());
    }

    glfwTerminate();

    return 0;
}
