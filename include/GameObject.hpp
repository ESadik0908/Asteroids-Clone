#pragma once
#include "SDL.h"
#include "SDL_image.h"
class GameObject
{
private:
    
public:
    SDL_FPoint center;
    int width, height;
    SDL_Rect hitbox;
    SDL_Surface* surface;
    SDL_Texture* texture;
    GameObject();
    GameObject(int width, int height, SDL_FPoint center);
    ~GameObject();

    virtual void Draw(SDL_Renderer *renderer) = 0;
    
    virtual void Update() = 0;

    void UpdatePoints();
};

