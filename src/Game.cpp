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

void Game::draw(RigidBody& RigidBody) {
    SDL_SetRenderDrawColor(renderer, RigidBody.getColor().r, RigidBody.getColor().g, RigidBody.getColor().b, RigidBody.getColor().a);
        SDL_FRect thisRigidBody{
        RigidBody.getPosition().x,
        RigidBody.getPosition().y,
        RigidBody.getDimensions().x,
        RigidBody.getDimensions().y
        };
        
        SDL_RenderFillRect(renderer, &thisRigidBody);
}

RigidBody firstBox{1, 1, {255, 0, 0, 255}, {0, 0}, {150, 150}, {0, 0}};
Vector2D change{20, 20};

void Game::run() {
    while (active) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT: end(); break;
                case SDL_EVENT_KEY_DOWN: firstBox.pushVelocity(change); break;
            }
        }

    // Main Processes
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderClear(renderer);

        draw(firstBox);

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