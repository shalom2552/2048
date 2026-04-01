#include "../inc/game.hpp"
#include "../inc/types.hpp"
#include "../inc/input.hpp"
#include "../inc/display/board_display.hpp"
#include "../inc/display/common_display.hpp"

#include <cstddef>      // std::size_t
#include <cstdlib>      // rand
#include <iostream>     // std::cout
#include <memory>       // std::make_unique

Game::Game(std::size_t size)
    : m_board(std::make_unique<Board>(size))
    , m_running(true)
    , m_score(0)
    , m_moves(0)
{
}

void Game::run()
{
    m_board->generate_new_cell();
    render_game();

    while (m_running) {
        InputEvent input = get_input();
        handle_input(input);

        // skip if no board change
        if (m_board->changed()){
            if (is_game_over()) handle_game_over();
            m_board->generate_new_cell();
            update_score();
            render_game();
        }
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
    m_board->collapse_move(direction);
}

void Game::update_score()
{
    ++m_moves;
    m_score = m_board->get_score();
}

void Game::render_game()
{
    clear_screen();
    print_header();
    print_board(*m_board);
    print_score(m_score, m_moves);
    print_footer();
}

void Game::handle_quit()
{
    std::cout << "See ya!";
    end_game();
}

bool Game::is_game_over()
{
    return !m_board->has_valid_move();
}

void Game::handle_game_over()
{
    end_game();
}

void Game::end_game()
{
    m_running = false;
}

