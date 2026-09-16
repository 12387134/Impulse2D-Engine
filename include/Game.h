#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class Game {
    private:
        int width{};
        int height{};
        bool active{};

    public:
        Game (int width, int height, bool active=true) : 
        width{width},
        height{height},
        active{active}
        {}

        void run() {

        }

        void end() {
            active = false;
        }

        bool running() const {
            return active;
        }
};
