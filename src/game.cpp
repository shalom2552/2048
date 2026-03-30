#include "../inc/game.hpp"
#include "../inc/utils/input.hpp"

#include <cstddef>      // std::size_t
#include <cstdlib>      // rand

Game::Game(std::size_t size)
    : m_board(size)
    , m_score(0)
    , m_running(true)
{
}

void Game::run()
{
    while (m_running) {
        m_board.generate_new_cell();
        m_board.render();

        InputEvent input = get_input();

        (void)input;
        // handle_move(input);
    }
}


// void Game::handle_move(InputEvent input)
// {
//     switch (input) {
//         case INPUT_UP: handle_up();
//         case INPUT_DOWN: handle_down();
//         case INPUT_RIGHT: handle_right();
//         case INPUT_LEFT: handle_left();
//         case INPUT_QUIT: handle_quit();
//     }
// }

