#pragma once

#include <iostream>

#include "../renderer/ShaderProgram.h"

namespace graphics{
    class Texture{
        public:

        Texture(std::string path, unsigned int uniformID);
        ~Texture();


        GLuint id;

        int width;
        int height;
        int channels;

        GLuint get_ID(){
            return id;
        }

        private:
        GLuint load_texture(std::string path);

    };
};