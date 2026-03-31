#ifndef DISPLAY_BOARD_DISPLAY_HPP
#define DISPLAY_BOARD_DISPLAY_HPP

#include "../board.hpp"     // Board
#include "../types.hpp"     // Ansi

#include <cstddef>  // std::size_t
#include <string>   // std::string

/* print ansii clear_screen code */
void clear_screen();

/* print songle characther string to the board */
void print_char(std::string const& c);

/* main function to print the board */
void print_board(Board const& Board);

/* prints cell with padding */
void print_cell(int value);

/* calculate the width of the pritable board including seprators */
std::size_t get_printable_size(std::size_t size);

/* print an actual board row with the values */
void print_board_row(std::size_t size, std::vector<Cell> const& row);

/* generic function to print any row type of the board */
void print_box_row(std::size_t size, Ansi left, Ansi sep, Ansi mid, Ansi right);

/* print the top seprator of the board */
void print_top_border(std::size_t size);

/* print the bottom seprator of the board */
void print_bottom_border(std::size_t size);

/* print seprator row between board lines */
void print_border_row(std::size_t size);

/* print an empty row with vertivcal seprators to add height */
void print_buffer_row(std::size_t size);

/* add padding to the board from the left */
void print_left_padding();

#endif // !DISPLAY_BOARD_DISPLAY_HPP

