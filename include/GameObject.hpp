#pragma once
#include "SDL.h"
#include "SDL_image.h"
class GameObject
{
private:
    
public:
    SDL_Surface* surface;
    SDL_Texture* texture;
    int x;
    int y;
    GameObject();
    GameObject(int _x, int _y);
    ~GameObject();

    virtual void Draw(SDL_Renderer *renderer) = 0;
    
    virtual void Update() = 0;
};

