#include "SDL.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
#include <thread>
#include <string>

#include "SdlWindow.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "Consts.hpp"


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

void SdlWindow::RenderGameObjects(std::vector<GameObject*> game_objects, double delta_time){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    for (GameObject* obj : game_objects) {
            obj->Update(delta_time);
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

    Player* player = new Player(renderer, "../res/player.png", 50, 50, {SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2});

    game_objects.push_back(player);

    double lastTime = getCurrentTime();
    while(!(event.type == SDL_QUIT)){
        SDL_PollEvent(&event);  // Catching the poll event. 
        double current = getCurrentTime();
        double delta_time = current - lastTime;
        RenderGameObjects(game_objects, delta_time);
        lastTime = current;
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); //60fps = 16ms, 30fps = 33ms

    }
    delete(player);
}
