#ifndef DISPLAY_BOARD_DISPLAY_HPP
#define DISPLAY_BOARD_DISPLAY_HPP

#include "../board.hpp"     // Board
#include "../types.hpp"     // Ansi

#include <cstddef>  // std::size_t

/* prints the game score */
void print_score(int score, int moves);

/* main function to print the board */
void print_board(Board const& Board);

/* prints cell with padding */
void print_board_cell(int value);

/* calculate the width of the pritable board including seprators */
std::size_t get_board_printable_size(std::size_t size);

/* print an actual board row with the values */
void print_board_row(std::size_t size, std::vector<Cell> const& row);

/* generic function to print any row type of the board */
void print_board_row(std::size_t size, Ansi left, Ansi sep, Ansi mid, Ansi right);

/* print the top seprator of the board */
void print_board_top_border(std::size_t size);

/* print the bottom seprator of the board */
void print_board_bottom_border(std::size_t size);

/* print seprator row between board lines */
void print_board_border_row(std::size_t size);

/* print an empty row with vertivcal seprators to add height */
void print_board_buffer_row(std::size_t size);

#endif // !DISPLAY_BOARD_DISPLAY_HPP

