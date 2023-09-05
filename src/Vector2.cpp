#include "Vector2.hpp"

Vector2::Vector2(/* args */)
{
}

Vector2::Vector2(float _x, float _y): x(_x), y(_y)
{
}

Vector2::~Vector2()
{
}

void Vector2::operator+=(const Vector2 &b){
    this->x += b.x;
    this->y += b.y;
}

void Vector2::operator*(const double &b){
    this->x * b;
    this->y * b;
}