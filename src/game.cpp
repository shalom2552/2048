#include "../inc/game.hpp"
#include "../inc/types.hpp"
#include "../inc/terminal.hpp"
#include "../inc/display/board_display.hpp"
#include "../inc/display/common_display.hpp"

#include <iostream>     // std::cout
#include <memory>       // std::make_unique

Game::Game(GameSettings settings)
    : m_board(std::make_unique<Board>(settings.board_size))
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
        InputEvent input = Terminal::get_input();
        handle_input(input);

        // skip if no board change
        if (m_board->changed()){
            m_board->generate_new_cell();
            update_score();
            render_game();
            if (is_game_over()) handle_game_over();
        }
    }
}

void Game::handle_input(InputEvent input)
{
    switch (input) {
        case InputEvent::UP:
            handle_move(Direction::UP);
            break;
        case InputEvent::DOWN:
            handle_move(Direction::DOWN);
            break;
        case InputEvent::RIGHT:
            handle_move(Direction::RIGHT);
            break;
        case InputEvent::LEFT:
            handle_move(Direction::LEFT);
            break;
        case InputEvent::QUIT:
            handle_quit();
            break;
        default: break;
    }
}

void Game::handle_move(Direction dir)
{
    m_board->collapse_move(dir);
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
    print_line("No available moves. Game over!");
}

void Game::end_game()
{
    m_running = false;
}

