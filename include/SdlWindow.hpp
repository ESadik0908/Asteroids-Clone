#pragma once
#include "SDL.h"
#include "GameObject.hpp"
#include <stdio.h>
#include <vector>

class SdlWindow{
    public:
        SdlWindow();
        // Contructor which initialize the parameters.
        SdlWindow(int height_, int width_);

        // Destructor
        ~SdlWindow();

        void RenderGameObjects(std::vector<GameObject*> game_objects, double delta_time);

        void GameLoop();

        double getCurrentTime();

    private:
        int height;
        int width;
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;
        SDL_Event event;
        std::vector<GameObject*> game_objects;
};