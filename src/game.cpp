#include "../inc/game.hpp"
#include <cstddef>

Game::Game(std::size_t size)
    : m_board(size)
{
}

void Game::run()
{
    m_board.render();
}

