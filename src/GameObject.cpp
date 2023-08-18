#include "GameObject.hpp"
#include "SDL.h"

GameObject::GameObject(): x(100), y(100)
{
}

GameObject::GameObject(int _x, int _y): x(_x), y(_y)
{
}

GameObject::~GameObject()
{

}