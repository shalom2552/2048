#ifndef BOARD_HPP
#define BOARD_HPP

#include "types.hpp"

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

    bool has_valid_move();

    /* collase all lines acording to the input direction */
    void collapse_move(InputEvent);

    /* return true if last move changed the board */
    bool changed();

private:
    void place_empty_cell(std::size_t i);

    std::vector<int> extract_line(std::size_t index, bool is_row);
    void write_line(std::size_t index, bool is_row, std::vector<int>& line);
    void collapse_line(std::vector<int>& line, bool forward);

private:
    std::size_t m_size;
    std::vector<std::vector<Cell>> m_board;

    bool m_changed;
};

#endif // BOARD_HPP

