#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.hpp"

#include "Texture.h"

using namespace graphics;

Texture::Texture(std::string path, unsigned int uniformID){

    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    this->id = load_texture(path);

}

Texture::~Texture(){
    glDeleteTextures(1, &id);
}

GLuint Texture::load_texture(std::string path){

    GLuint textureID = this->id;

    stbi_set_flip_vertically_on_load(true); 

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);

    unsigned char* pixels = stbi_load(path.c_str(), &width, &height, &channels, STBI_rgb);

    if (!pixels) {
        std::cout << "Can't load image\n";
        exit(-1);
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


    if (!textureID){
        std::cout << "Can't load a texture\n";
        exit(-1);
    }

    stbi_image_free(pixels);
    glBindTexture(GL_TEXTURE_2D, 0);

    return textureID;

}

void Texture::bind_texture(){

    glActiveTexture(GL_TEXTURE0);

    glBindTexture(GL_TEXTURE_2D, id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

}