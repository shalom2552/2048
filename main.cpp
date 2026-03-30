#include "inc/game.hpp"
#include "inc/utils/input.hpp"

int main () {
    input_steup();

    Game game(4);
    game.run();

    cleanup();
    return 0;
}
