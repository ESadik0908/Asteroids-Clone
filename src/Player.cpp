#include "Player.hpp"
#include "SDL_image.h"
#include "string"

Player::Player(SDL_Renderer *renderer ,std::string imagePath, int width, int height, SDL_FPoint center)
{
    hitbox.x = center.x;
    hitbox.y = center.y;
    hitbox.w = width;
    hitbox.h = height;
    this->surface = IMG_Load(imagePath.c_str());
    this->texture = SDL_CreateTextureFromSurface(renderer, surface);
}

Player::~Player()
{
    SDL_FreeSurface(this->surface);
}

void Player::Draw(SDL_Renderer *renderer){
    SDL_RenderSetViewport(renderer, &hitbox);
    SDL_RenderCopy(renderer, this->texture, NULL, NULL);
}

void Player::Update(){

}