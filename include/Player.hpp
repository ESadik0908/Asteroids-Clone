#pragma once
#include "string"
#include "SDL.h"
#include "GameObject.hpp"

class Player : public GameObject
{
private:
    /* data */
public:
    Player(SDL_Renderer *renderer ,std::string imagePath);
    ~Player();

    void Draw(SDL_Renderer *renderer) override;

    void Update() override;
};

