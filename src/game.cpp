#include "../inc/game.hpp"
#include "../inc/types.hpp"
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
    m_board.generate_new_cell();
    m_board.render();
    while (m_running) {
        // if (is_game_over()) handle_game_over();
        InputEvent input = get_input();
        handle_input(input);

        if (!m_board.changed()) continue;
        m_board.generate_new_cell();
        m_board.render();
    }
}

void Game::handle_input(InputEvent input)
{
    switch (input) {
        case INPUT_UP:
        case INPUT_DOWN:
        case INPUT_RIGHT:
        case INPUT_LEFT: 
            handle_move(input);
            break;
        case INPUT_QUIT:
            handle_quit();
            break;
    }
}

void Game::handle_move(InputEvent direction)
{
    m_board.collapse_move(direction);
}

void Game::handle_quit()
{
    m_running = false;
}

