#include "Player.hpp"
#include "SDL_image.h"
#include "SDL.h"
#include "string"

Player::Player(
    SDL_Renderer *renderer ,
    std::string imagePath, 
    int _width, 
    int _height, 
    SDL_FPoint _center) :
    GameObject(_width, _height, _center)
{
    UpdatePoints();
    this->surface = IMG_Load(imagePath.c_str());
    this->texture = SDL_CreateTextureFromSurface(renderer, surface);
}

Player::~Player()
{
    SDL_FreeSurface(this->surface);
}

void Player::Draw(SDL_Renderer *renderer){
    // SDL_RenderSetViewport(renderer, &hitbox);
    // SDL_RenderCopy(renderer, this->texture, NULL, NULL);
    SDL_SetRenderDrawColor(renderer, 255 , 0, 0, 255);
    SDL_RenderDrawRect(renderer, &hitbox);
    SDL_SetRenderDrawColor(renderer, 255 , 255, 255, 255);
    SDL_RenderDrawPoint(renderer, hitbox.x, hitbox.y);
    SDL_RenderDrawPoint(renderer, center.x, center.y);
}



void Player::Update(){
    if(input[SDL_SCANCODE_UP]){
        center.y--;
        UpdatePoints();

    }
}