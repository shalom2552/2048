#include "inc/game.hpp"
#include "inc/input.hpp"

int main () {
    input_setup();

    Game game{6};
    game.run();

    cleanup();
    return 0;
}
