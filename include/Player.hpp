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
    float angle = 0;
    Vector2 velocity = VECTOR2_ZERO;

    float move_speed = 5;
    float rotation_speed = 300;
    int max_speed = 20;
    float friction = 3;

    Vector2 direction = VECTOR2_UP;
public:
    Player(SDL_Renderer *renderer ,std::string imagePath, int width, int height, Vector2 _center);
    ~Player();

    void Draw(SDL_Renderer *renderer) override;

    void Update(double delta_time) override;

    float ConstrainAngle(float _angle);

    void Decelerate(double delta_time);
};

