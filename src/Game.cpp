#include "Game.h"
#include <print>

Game::Game(int width, int height, RGBA color, bool active) : 
    width{width},
    height{height},
    color{color},
    active{active} {
}

void Game::initialize() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::println("{}", SDL_GetError());
        active = false;
        return;
    }

    window = SDL_CreateWindow (
        "Title",
        width,
        height,
        0
    );

    if (window == nullptr) {
        std::println("{}", SDL_GetError());
        active = false;
        return;
    }

    renderer = SDL_CreateRenderer (
        window,
        nullptr
    );

    if (renderer == nullptr) {
        std::println("{}", SDL_GetError());
        active = false;
    }

}

void Game::run() {
    while (active) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT: active = false; break;
                case SDL_EVENT_KEY_DOWN: active = false; break;
            }
        }

    // Main Processes
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);

    }
}

void Game::end() {
    active = false;
}

bool Game::running() const {
    return active;
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}