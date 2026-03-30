#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"

#include <cstddef>      // std::size_t

class Game {
public:
    Game(std::size_t size = 4);

    void run();

private:
    Board m_board;
};

#endif // GAME_HPP

