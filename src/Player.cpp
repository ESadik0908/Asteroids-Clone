#include <math.h>
#include "Player.hpp"
#include "SDL_image.h"
#include "SDL.h"
#include "string"
#include "Vector2.hpp"
#include <iostream>
#include <string>

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
    SDL_SetRenderDrawColor(renderer, 255 , 0, 0, 255);
    SDL_RenderDrawRect(renderer, &hitbox);
    SDL_SetRenderDrawColor(renderer, 255 , 255, 255, 255);
    SDL_RenderDrawPoint(renderer, hitbox.x, hitbox.y);
    SDL_RenderDrawPoint(renderer, position.x, position.y);
}

int Player::ConstrainAngle(int _angle){
    _angle = fmod(_angle,360);
    if (_angle < 0)
        _angle += 360;
    return _angle;
}

void Player::Update(){

    if(velocity.x != 0){
        velocity.x -= 0.5;
    }

    if(velocity.y != 0){
        velocity.y -= 0.5;
    }



    if(input[SDL_SCANCODE_RIGHT]){
        angle += rotation_speed;
        
        angle = ConstrainAngle(angle);
    }

    if(input[SDL_SCANCODE_LEFT]){
        angle -= rotation_speed;
        angle = ConstrainAngle(angle);
    }
    

    direction.x = cos(angle);

    std::string str = std::to_string(direction.x);
    SDL_Log(str.c_str());

    direction.y = sin(angle);

    if(input[SDL_SCANCODE_UP]){
        if(velocity.x + velocity.y < max_speed){
            velocity.x += (moves_speed * direction.x);
            velocity.y += (moves_speed * direction.y);
        }
    }

    position += velocity;

    UpdatePoints();
}