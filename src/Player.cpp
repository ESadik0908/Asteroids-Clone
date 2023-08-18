#include "Player.hpp"
#include "SDL_image.h"
#include "string"

Player::Player(SDL_Renderer *renderer ,std::string imagePath, int width, int height, SDL_FPoint center)
{
    hitbox = Quad(width, height, center);
    this->surface = IMG_Load(imagePath.c_str());
    this->texture = SDL_CreateTextureFromSurface(renderer, surface);
}

Player::~Player()
{
    SDL_FreeSurface(this->surface);
}

void Player::Draw(SDL_Renderer *renderer){
    // SDL_RenderCopy(renderer, this->texture, NULL, NULL);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderDrawLine(renderer, 
    hitbox.bottom_left_vertex.x, hitbox.bottom_left_vertex.y,
    hitbox.bottom_right_vertex.x, hitbox.bottom_right_vertex.y
    );

    SDL_RenderDrawLine(renderer, 
    hitbox.bottom_left_vertex.x, hitbox.bottom_left_vertex.y,
    hitbox.top_left_vertex.x, hitbox.top_left_vertex.y
    );


    SDL_RenderDrawLine(renderer, 
    hitbox.top_left_vertex.x, hitbox.top_left_vertex.y,
    hitbox.top_right_vertex.x, hitbox.top_right_vertex.y
    );

    SDL_RenderDrawLine(renderer, 
    hitbox.top_right_vertex.x, hitbox.top_right_vertex.y,
    hitbox.bottom_right_vertex.x, hitbox.bottom_right_vertex.y
    );
}

void Player::Update(){

}