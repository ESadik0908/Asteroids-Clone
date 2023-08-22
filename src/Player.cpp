#include <cmath>
#include <algorithm>
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

void Player::Decelerate() {


    if (velocity.x < 0) {
        velocity.x++;
    } else if (velocity.x > 0) {
        velocity.x--;
    }

    if (velocity.y < 0) {
        velocity.y++;
    } else if (velocity.y > 0) {
        velocity.y--;
    }
}


void Player::Update(){

    std::string str1 = std::to_string(velocity.x);
    std::string str2 = std::to_string(velocity.y);
    std::string str = "velocity x: " + str1 + " velocity y: " + str2;
    SDL_Log(str.c_str());

    if(input[SDL_SCANCODE_RIGHT]){
        angle += rotation_speed;
    }

    if(input[SDL_SCANCODE_LEFT]){
        angle -= rotation_speed;
    }

    double angleRadians = angle * M_PI / 180.0;
    
    // angle = ConstrainAngle(angle);
    direction.x = std::sin(angleRadians);



    direction.y = -cos(angleRadians);



    if(input[SDL_SCANCODE_UP]){
        velocity.x += (direction.x * move_speed);
        velocity.y += (direction.y * move_speed);
    }

    position += velocity;

    UpdatePoints();
}