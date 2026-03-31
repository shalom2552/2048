#ifndef DISPLAY_COMMON_DISPLAY_HPP
#define DISPLAY_COMMON_DISPLAY_HPP

#include <string>   // std::string

/* print ansii clear_screen code */
void clear_screen();

/* print songle characther string to the board */
void print_char(std::string const& c);

/* add padding to the board from the left */
void print_left_padding(unsigned int padding);

#endif // !DISPLAY_COMMON_DISPLAY_HPP

