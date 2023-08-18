#include "SDL.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
#include <thread>

#include "SdlWindow.hpp"
#include "GameObject.hpp"
#include "Player.hpp"


SdlWindow::SdlWindow(int height_, int width_): height(height_), width(width_){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

SdlWindow::~SdlWindow(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SdlWindow::RenderGameObjects(std::vector<GameObject*> gameObjects){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    for (GameObject* obj : gameObjects) {
            obj->Update();
            obj->Draw(renderer);
    }

    SDL_RenderPresent(renderer);
}


double SdlWindow::getCurrentTime() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
               std::chrono::system_clock::now().time_since_epoch()
           ).count() / 1000.0;
}

void SdlWindow::GameLoop(){

    Player* player = new Player(renderer, "../res/player.png", 10, 10, {100, 100});

    gameObjects.push_back(player);

    double lastTime = getCurrentTime();
    while(!(event.type == SDL_QUIT)){
        SDL_PollEvent(&event);  // Catching the poll event. 
        double current = getCurrentTime();
        double elapsed = current - lastTime;
        RenderGameObjects(gameObjects);
        lastTime = current;
        std::this_thread::sleep_for(std::chrono::milliseconds(33));

    }
}
