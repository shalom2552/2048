#ifndef UTILS_DISPLAY_HPP
#define UTILS_DISPLAY_HPP

#include "../board.hpp"

#include <cstddef>  // std::size_t
#include <string>   // std::string

void print_board(Board const& Board);

void print_char(std::string c);

void print_top_boarder(std::size_t size);

void print_bottom_boarder(std::size_t size);

#endif // !UTILS_DISPLAY_HPP

