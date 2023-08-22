#pragma once
#include "string"
#include "SDL.h"
#include "GameObject.hpp"
#include "Vector2.hpp"
#include "Consts.hpp"

class Player : public GameObject
{
private:
    const Uint8* input = SDL_GetKeyboardState(nullptr);
    int angle = 0;
    Vector2 velocity = VECTOR2_ZERO;

    int move_speed = 1;
    int rotation_speed = 5;
    int max_speed = 10;

    Vector2 direction = VECTOR2_UP;
public:
    Player(SDL_Renderer *renderer ,std::string imagePath, int width, int height, Vector2 _center);
    ~Player();

    void Draw(SDL_Renderer *renderer) override;

    void Update() override;

    int ConstrainAngle(int _angle);

    void Decelerate();
};

