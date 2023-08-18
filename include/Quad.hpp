#pragma once
#include "SDL.h"
#include "vector"

class Quad
{
private:

    SDL_FPoint center;
public:
    SDL_FPoint bottom_left_vertex;
    SDL_FPoint top_left_vertex;
    SDL_FPoint bottom_right_vertex;
    SDL_FPoint top_right_vertex;
    
    Quad();
    Quad(int width, int height, SDL_FPoint _center);
    ~Quad();

};

