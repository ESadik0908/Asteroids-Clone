#include "Quad.hpp"
#include "SDL.h"


Quad::Quad(){

}

Quad::Quad(int height, int width, SDL_FPoint _center): center(_center)
{
    float half_height = (height / 2);
    float half_width = (width / 2);
    bottom_left_vertex = {center.x - half_width, center.y + half_height};
    top_left_vertex = {center.x - half_width, center.y - half_height};
    bottom_right_vertex = {center.x + half_width, center.y + half_height};
    top_right_vertex = {center.x + half_width, center.y - half_height};
}

Quad::~Quad(){
    
}