#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"
#include "utils/input.hpp"

#include <cstddef>      // std::size_t

class Game {
public:
    Game(std::size_t size = 4);

    /* main game loop */
    void run();

private:
    /* generate value 2 in a random empty cell */
    void generate_new_cell();

    void handle_move(InputEvent input);

    void handle_up();

    void handle_down();

    void handle_right();

    void handle_left();

    void handle_quit();

private:
    Board m_board;

    unsigned int m_score;
    bool m_running;
};

#endif // GAME_HPP

