#include "inc/game.hpp"
#include "inc/input.hpp"

int main () {
    input_setup();

    Game game{4};
    game.run();

    cleanup();
    return 0;
}
