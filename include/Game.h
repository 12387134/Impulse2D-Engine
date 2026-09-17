#pragma once
#include <SDL3/SDL.h>
#include <string>

struct RGBA {
    int r{};
    int g{};
    int b{};
    int a{};
};

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
        bool running() const;
};
