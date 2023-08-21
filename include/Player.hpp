#pragma once
#include "string"
#include "SDL.h"
#include "GameObject.hpp"


class Player : public GameObject
{
private:

    const Uint8* input = SDL_GetKeyboardState(nullptr);
public:
    Player(SDL_Renderer *renderer ,std::string imagePath, int width, int height, SDL_FPoint center);
    ~Player();

    void Draw(SDL_Renderer *renderer) override;

    void Update() override;


};

