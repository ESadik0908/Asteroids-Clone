#pragma once
#include "string"
#include "SDL.h"
#include "GameObject.hpp"
#include "Quad.hpp"

class Player : public GameObject
{
private:
    Quad hitbox;
public:
    Player(SDL_Renderer *renderer ,std::string imagePath, int width, int height, SDL_FPoint center);
    ~Player();

    void Draw(SDL_Renderer *renderer) override;

    void Update() override;
};

