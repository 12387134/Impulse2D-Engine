#include "Game.h"

int main() {
    RGBA color = {200, 100, 100, 200};
    Game game{500, 500, {color}};
    game.initialize();

    if (game.running()) {
        game.run(); 
    }

    return 0;
}