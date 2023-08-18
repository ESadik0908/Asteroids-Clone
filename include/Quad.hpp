#pragma once
#include "SDL.h"
#include "vector"

class Quad
{
private:
    SDL_FPoint bottom_left_vertex;
    SDL_FPoint top_left_vertex;
    SDL_FPoint bottom_right_vertex;
    SDL_FPoint top_right_vertex;
    SDL_FPoint center;
public:
    Quad(int width, int height, int );
    ~Quad();
};

