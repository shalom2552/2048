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

    std::size_t count_empty_cells() const;

    void generate_new_cell();

private:
    void place_empty_cell(std::size_t i);

private:
    std::size_t m_size;
    std::vector<std::vector<Cell>> m_board;
};

#endif // BOARD_HPP

