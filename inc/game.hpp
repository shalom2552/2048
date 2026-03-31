#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"
#include "types.hpp"

#include <cstddef>      // std::size_t

class Game {
public:
    Game(std::size_t size = 4);

    /* main game loop */
    void run();

private:
    /* generate value 2 in a random empty cell */
    void generate_new_cell();

    /* move dispatcher */
    void handle_input(InputEvent input);

    void handle_move(InputEvent driection);
    void handle_quit();

    bool is_game_over();
    void handle_game_over();
    void end_game();

private:
    Board m_board;

    unsigned int m_score;
    bool m_running;
};

#endif // GAME_HPP

