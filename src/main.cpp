#include <iostream>
#include "SDL.h"
#include "SdlWindow.hpp"

int main(int argc, char* argv[]){
    
    SdlWindow sdlWindow(1080,1920);
    sdlWindow.GameLoop();

    return 0;
}
