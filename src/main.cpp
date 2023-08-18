#include <iostream>
#include "SDL.h"
#include "SdlWindow.hpp"
#include "Consts.hpp"

int main(int argc, char* argv[]){
    
    SdlWindow sdlWindow(SCREEN_WIDTH,SCREEN_HEIGHT);
    sdlWindow.GameLoop();

    return 0;
}
