#ifndef BOARD_HPP
#define BOARD_HPP

#include "types.hpp"

#include <cstddef>  // std::size_t
#include <vector>   // std::vector

/* board cell */
struct Cell {
    int value = 0;
};

class Board {
public:
    explicit Board(std::size_t size);

    /* display the board */
    void render();

    /* return the size of the board (#rows * #cols) */
    std::size_t size() const;

    /* return a const reference of the board */
    const std::vector<std::vector<Cell>>& get_board() const;

    /* return the sum of all cells */
    unsigned int get_score();

    /* return the number of empty cells in the board */
    std::size_t count_empty_cells() const;

    /* adds a value new value to a random empty cell */
    void generate_new_cell();

    /* return true if there is a valid move or false otherwise */
    bool has_valid_move();

    /* collase all lines acording to the input direction */
    void collapse_move(InputEvent);

    /* return true if last move changed the board */
    bool changed();

private:

    /* write new value to an empty cell */
    void place_empty_cell(std::size_t i);

    /* extract line from the board to a vector */
    std::vector<int> extract_line(std::size_t index, bool is_row);

    /* write a line to the board */
    void write_line(std::size_t index, bool is_row, std::vector<int>& line);

    /* collapse a vector in place to the begining or to the end */
    void collapse_line(std::vector<int>& line, bool forward);

private:
    std::size_t m_size;
    std::vector<std::vector<Cell>> m_board;

    bool m_changed;
};

#endif // BOARD_HPP

