#include "Game.h"
#include "RigidBody.h"
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

void Game::end() {
    active = false;
}

void Game::draw(float x, float y, float n, float z) {

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_FRect rectangle1{
        x,
        y,
        n,
        z };
        SDL_RenderFillRect(renderer, &rectangle1);
}

void Game::run() {
    while (active) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT: end(); break;
                case SDL_EVENT_KEY_DOWN: end(); break;
            }
        }

    // Main Processes
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderClear(renderer);

        draw(200, 200, 200, 200);
        draw(0, 0, 40, 40);

        SDL_RenderPresent(renderer);

    }
}

bool Game::running() const {
    return active;
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}