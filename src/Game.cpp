#include "Game.h"

Game::Game(int width, int height, bool active) : 
    width{width},
    height{height},
    active{active} {
}

void Game::run() {
    SDL_Window* window = SDL_CreateWindow (
        "Impulse2D",
        width,
        height,
        0
    );

    SDL_Renderer* renderer = SDL_CreateRenderer (
        window,
        nullptr
    );

}

void Game::end() {
    active = false;
}

bool Game::running() const {
    return active;
}