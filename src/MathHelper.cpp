#include "MathHelper.hpp"

int Sign(float x){
    if(x < 0) return -1;
    if(x > 0) return 1;
    return 0;
}

float lerp(float a, float b, float f)
{
    return a * (1.0 - f) + (b * f);
}