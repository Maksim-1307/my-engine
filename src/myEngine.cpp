
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
#include "voxels/ChunkRenderer.h"
#include "world/World.h"

using namespace graphics;
using namespace std;

BlockFace emptyBf;

BlockFace stoneFaces[]{
    BlockFace(),
    BlockFace(),
    BlockFace(),
    BlockFace(),
    BlockFace(),
    BlockFace()
};

void make_buffers(float * verticesPointer, int verticesLen, int * indicesPointer, int indicesLen, GLuint & VBO, GLuint & VAO, GLuint & EBO){
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, verticesLen * sizeof(GLfloat), verticesPointer, GL_STATIC_DRAW);

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
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesLen * sizeof(GLuint), indicesPointer, GL_STATIC_DRAW);
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
    chunk.x = 2;
    chunk.generate();

    cout << "\n";
    // for (int x = 1; x < CHUNK_WIDTH-1; x++){
    //     for (int y = 1; y < CHUNK_HEIGHT-1; y++){
    //         for (int z = 1; z < CHUNK_WIDTH-1; z++){
    //             cout << (int)chunk.blocksData[x][y][z].id;
    //         } cout << "\n";
    //     } cout << "\n\n";
    // }

    voxel vox;
    vox.id = 0;
    vox.state = 0;

    ChunkRenderer renderer;
    //renderer.render(chunk);

    // cout << "Voxels: " << renderer.vertexCount << "\n";
    // cout << "Indices: " << renderer.indicesCount << "\n";
    // for (int i = 0; i < renderer.vertexCount; i++){

    //     if (i % 5 == 0){
    //         cout << "\n";
    //     }
    //     cout << renderer.vertices[i] << " ";

    // }
    // cout << "\n\n\n";

    // for (int i = 0; i < renderer.indicesCount; i++){

    //     if (i % 3 == 0){
    //         cout << "\n";
    //     }
    //     cout << renderer.indices[i] << " ";

    // }


    //chunk.updateVoxels();

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

    // GLuint vao;
    // GLuint vbo;
    // GLuint ebo;

    //make_buffers(renderer.vertices, renderer.vertexCount, renderer.indices, renderer.indicesCount, vbo, vao, ebo);

    World world;


    std::string vShaderSource;
    std::string fShaderSource;
    myutils::readFile(SHADERS_PATH "shader-v.glsl", &vShaderSource);
    myutils::readFile(SHADERS_PATH "shader-f.glsl", &fShaderSource);

    renderer::ShaderProgram shaderProgram(vShaderSource, fShaderSource);

    graphics::Texture texture("res/textures/atlas.png", 0);

    renderer::Camera camera(window);
    input::Mouse mouse(window);

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    model = glm::rotate(model, glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    timemanager::FPSCounter fpsCounter(window, 10);

    int test = 0;

    // for (int x = -3; x < 4; x++){
    //     for (int z = -3; z < 4; z++){
    //         world.load_chunk(ivec2(x, z));
    //         break;
    //     }
    // }


    for (int i = -5; i < 6; i++){
        for (int j = -5; j < 6; j++){
            world.load_chunk(i, j);
            renderer.render(world.chunks[ivec2(i, j)]);
            world.chunks[ivec2(i,j)]->make_buffers();
        }
    }


    // ivec2 chunkCoords(0,0);

    // world.load_chunk(0,0);
    // cout << world.chunks[chunkCoords] <<"\n";
    // for (const auto & [key, value] : world.chunks){
    //     std::cout << key.x << key.y << " , value " << value << std::endl;
    // }
    // cout << "before\n";
    // world.chunks[chunkCoords]->print_blocks();
    // cout << "after\n";
    // renderer.render(world.chunks[ivec2(0, 0)]);
    // world.chunks[ivec2(0, 0)]->make_buffers();

    int tt = 6;

    while (!glfwWindowShouldClose(window.get_glfw_window()))
    {
        fpsCounter.update();

        float deltaTime = fpsCounter.deltaTime;

        glfwPollEvents();



        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram.Use();

        for (auto i : world.chunks){
            i.second->draw();
        }
        world.load_chunk(0, tt);
        renderer.render(world.chunks[ivec2(0, tt)]);
        // world.chunks[ivec2(0,tt)]->make_buffers();
        tt++;

        //chunk.generate();
        // renderer.render(chunk);
        // chunk.make_buffers();
        // chunk.draw();
        // make_buffers(renderer.vertices, renderer.vertexCount, renderer.indices, renderer.indicesCount, vbo, vao, ebo);
        // draw(vao, ebo, renderer.vertexCount);

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


/*


1 0 0  
1 0 1
1 1 0  
1 1 1

0 0 0
0 0 1
0 1 0
0 1 1 

0 1 0
0 1 1
1 1 0
1 1 1 

0 0 0
0 0 6  
1 0 0 
1 0 1

0 0 1
0 1 1
1 0 1
1 1 1 

0 0 0 
0 1 0
1 0 0
1 1 0


*/