#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include "Player.hpp"
#include "SDL_image.h"
#include "SDL.h"
#include "string"
#include "Vector2.hpp"
#include "MathHelper.hpp"


Player::Player(
    SDL_Renderer *renderer ,
    std::string imagePath, 
    int _width, 
    int _height, 
    Vector2 _center) :
    GameObject(_width, _height, _center)
{
    UpdatePoints();
    this->surface = IMG_Load(imagePath.c_str());
    this->texture = SDL_CreateTextureFromSurface(renderer, surface);
}

Player::~Player()
{
    SDL_FreeSurface(this->surface);
    SDL_DestroyTexture(this->texture);
}

void Player::Draw(SDL_Renderer *renderer){
    SDL_SetRenderTarget(renderer, texture);
    SDL_RenderCopyEx(renderer, texture, NULL, &hitbox, angle, NULL, SDL_FLIP_NONE);
}

int Player::ConstrainAngle(int _angle){
    _angle = fmod(_angle,360);
    if (_angle < 0)
        _angle += 360;
    return _angle;
}

void Player::Decelerate() {
    
    if(abs(velocity.x) < 0.1){
        velocity.x = 0;
    }

    if(abs(velocity.y) < 0.1){
        velocity.y = 0;
    }

    if(velocity.x != 0){
        velocity.x = lerp(velocity.x, 0, friction);
    }

    if(velocity.y !=  0){
       velocity.y = lerp(velocity.y, 0, friction);
    }
}

void Player::Update(){

    if(input[SDL_SCANCODE_RIGHT]){
        angle += rotation_speed;
    }

    if(input[SDL_SCANCODE_LEFT]){
        angle -= rotation_speed;
    }

    angle = ConstrainAngle(angle);

    float angleRadians = angle * M_PI / 180.0;

    int sign_x = Sign(sin(angleRadians));
    int sign_y = Sign(cos(angleRadians));

    direction.x = sign_x * pow(sin(angleRadians), 2);
    direction.y = -(sign_y * pow(cos(angleRadians), 2));


    if(input[SDL_SCANCODE_UP]){
        velocity.x += direction.x * move_speed;
        velocity.y += direction.y * move_speed;
        if(abs(velocity.x) + abs(velocity.y) >= max_speed){

            velocity.x -= direction.x * move_speed;
            velocity.y -= direction.y * move_speed;

            velocity.x = lerp(velocity.x, direction.x * max_speed, 0.05);
            velocity.y = lerp(velocity.y, direction.y * max_speed, 0.05);
        }        
    }
    else
    {
        Decelerate();
    }

    position += velocity;
    UpdatePoints();
}