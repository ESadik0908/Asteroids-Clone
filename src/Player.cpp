#include "Player.hpp"
#include "SDL_image.h"
#include "string"

Player::Player(SDL_Renderer *renderer ,std::string imagePath)
{
    this->surface = IMG_Load(imagePath.c_str());
    this->texture = SDL_CreateTextureFromSurface(renderer, surface);
}

Player::~Player()
{
    SDL_FreeSurface(this->surface);
}

void Player::Draw(SDL_Renderer *renderer){
    // SDL_RenderCopy(renderer, this->texture, NULL, NULL);
}

void Player::Update(){

}