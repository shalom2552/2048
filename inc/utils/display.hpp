#ifndef UTILS_DISPLAY_HPP
#define UTILS_DISPLAY_HPP

#include "../board.hpp"

#include <cstddef>  // std::size_t
#include <string>   // std::string

void clear_screen();

void print_board(Board const& Board);

std::size_t get_printable_size(std::size_t size);

void print_char(std::string const& c);

void print_top_border(std::size_t size);

void print_row(std::size_t size, std::vector<Cell> const& row);

void print_border_row(std::size_t size);

void print_bottom_border(std::size_t size);

#endif // !UTILS_DISPLAY_HPP

