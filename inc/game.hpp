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

    /* input dispatcher */
    void handle_input(InputEvent input);

    /* update the board based on the user move */
    void handle_move(InputEvent driection);

    /* call end game */
    void handle_quit();

    /* return true if there is no valid move */
    bool is_game_over();

    /* print game results and end the game */
    void handle_game_over();

    /* terminates the game */
    void end_game();

private:
    Board m_board;

    unsigned int m_score;
    bool m_running;
};

#endif // GAME_HPP

