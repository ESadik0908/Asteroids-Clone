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

float Player::ConstrainAngle(float _angle){
    _angle = fmod(_angle,360);
    if (_angle < 0)
        _angle += 360;
    return _angle;
}

void Player::Decelerate(double delta_time) {
    std::string vel_x = std::to_string(velocity.x);
    std::string vel_y = std::to_string(velocity.y);

    std::string str = "velocity_x: " + vel_x + " Velocity_y: " + vel_y;

    SDL_Log(str.c_str());

    if(abs(velocity.x) < 0.001){
        velocity.x = 0;
    }

     if(abs(velocity.y) < 0.001){
        velocity.y = 0;
    }

    if(velocity.x > 0){
        velocity.x -= friction * delta_time;
    }

    if(velocity.y > 0){
        velocity.y -= friction * delta_time;
    }

    if(velocity.x < 0){
        velocity.x += friction * delta_time;
    }

    if(velocity.y < 0){
        velocity.y += friction * delta_time;
    }
}

void Player::Update(double delta_time){

    if(input[SDL_SCANCODE_RIGHT]){
        angle += rotation_speed * delta_time;
    }

    if(input[SDL_SCANCODE_LEFT]){
        angle -= rotation_speed * delta_time;
    }

    angle = ConstrainAngle(angle);

    float angleRadians = angle * M_PI / 180.0;

    int sign_x = Sign(sin(angleRadians));
    int sign_y = Sign(cos(angleRadians));

    direction.x = sign_x * pow(sin(angleRadians), 2);
    direction.y = -(sign_y * pow(cos(angleRadians), 2));


    if(input[SDL_SCANCODE_UP]){
        velocity.x += direction.x * move_speed * delta_time;
        velocity.y += direction.y * move_speed * delta_time;
        if(abs(velocity.x) + abs(velocity.y) >= max_speed){

            velocity.x -= direction.x * move_speed * delta_time;
            velocity.y -= direction.y * move_speed * delta_time;

            velocity.x = lerp(velocity.x, direction.x * velocity.x, delta_time);
            velocity.y = lerp(velocity.y, direction.y * velocity.y, delta_time);
        }        
    }
    if(!input[SDL_SCANCODE_UP])
    {
        Decelerate(delta_time);
    }

    position += velocity;
    UpdatePoints();
}