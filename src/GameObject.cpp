#include "GameObject.hpp"
#include "SDL.h"
#include "Consts.hpp"

GameObject::GameObject():
    center({SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2}),
    width(100),
    height(100)
{
    UpdatePoints();
}

GameObject::GameObject(int _width, int _height, SDL_FPoint _center):
    center(_center),
    width(_width),
    height(_height)
{
    UpdatePoints();
}

GameObject::~GameObject()
{

}

void GameObject::UpdatePoints(){
    hitbox.x = center.x - (width / 2);
    hitbox.y = center.y - (height / 2);
    hitbox.w = width;
    hitbox.h = height;
}