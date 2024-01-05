#include "SpriteData.h"

using namespace graphics;


SpriteData::SpriteData(int vertices_len, GLfloat* vertices, int indices_len, GLuint* indices, int uv_len, GLfloat* uv, Texture& texture){
    this->vertices_len = vertices_len;
    this->indices_len = indices_len;
    this->uv_len = uv_len;
    this->vertices = vertices;
    this->indices = indices;
    this->uv = uv;
}

SpriteData::SpriteData(){}
SpriteData::~SpriteData(){

}

