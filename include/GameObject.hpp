#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Vector2.hpp"

class GameObject
{
private:
    
public:
    Vector2 position;
    int width, height;
    SDL_Rect hitbox;
    SDL_Surface* surface;
    SDL_Texture* texture;
    GameObject();
    GameObject(int width, int height, Vector2 center);
    ~GameObject();

    virtual void Draw(SDL_Renderer *renderer) = 0;
    
    virtual void Update() = 0;

    void UpdatePoints();
};

