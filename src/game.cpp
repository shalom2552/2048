#include "../inc/game.hpp"
#include "../inc/utils/input.hpp"

#include <cstddef>      // std::size_t

Game::Game(std::size_t size)
    : m_board(size)
{
}

void Game::run()
{
    while (1) {
        m_board.render();
        InputEvent input = get_input();
    }
}

