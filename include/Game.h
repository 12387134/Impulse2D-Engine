#pragma once
#include <SDL3/SDL.h>
#include <string>
#include "RigidBody.h"
#include "rgba.h"

class Game {
    private:
        int width{};
        int height{};
        bool active{};
        RGBA color{};
        SDL_Window* window{};
        SDL_Renderer* renderer{};

    public:
        Game (int width, int height, RGBA color, bool active=true);
        ~Game();
        void initialize();
        void run();
        void end();
        void draw(const RigidBody& RigidBody);
        bool running() const;
}; // rgba, position, dimensions 
