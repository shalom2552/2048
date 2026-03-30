#ifndef BOARD_HPP
#define BOARD_HPP

#include <cstddef>  // std::size_t
#include <vector>   // std::vector

struct Cell {
    int value = 0;
};

class Board {
public:
    explicit Board(std::size_t size);

    void render();

    std::size_t size() const;

    const std::vector<std::vector<Cell>>& get_board() const;

private:
    std::size_t m_size;
    std::vector<std::vector<Cell>> m_board;
};

#endif // BOARD_HPP

