#include "inc/game.hpp"
#include "inc/utils/input.hpp"

int main () {
    input_setup();

    Game game{5};
    game.run();

    cleanup();
    return 0;
}
