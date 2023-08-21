#pragma once

class Vector2
{
private:
    /* data */
public:
    float x, y;

    Vector2(/* args */);
    Vector2(float x, float y);
    ~Vector2();

    void operator +=(const Vector2 &b);
};


