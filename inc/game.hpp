#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"
#include "types.hpp"

#include <cstddef>      // std::size_t
#include <memory>       // std::unique_ptr

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

    /* update the score and moves */
    void update_score();

    /* prints the game to the terminal */
    void render_game();

    /* return true if there is no valid move */
    bool is_game_over();

    /* print game results and end the game */
    void handle_game_over();

    /* terminates the game */
    void end_game();

private:
    std::unique_ptr<Board> m_board;

    bool m_running;
    unsigned int m_score;
    unsigned int m_moves;
};

#endif // GAME_HPP

