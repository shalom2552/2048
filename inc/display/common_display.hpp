#ifndef DISPLAY_COMMON_DISPLAY_HPP
#define DISPLAY_COMMON_DISPLAY_HPP

#include <string>   // std::string

/* print ansii clear_screen code */
void clear_screen();

/* print single characther string to the screen */
void print_char(std::string const& c);

/* print single line string to the screen */
void print_line(std::string const& line);

/* print single line string to the screen */
void print_padded_line(int padding, std::string const& line);

/* prints #liens empty lines for vertical padding */
void print_empty_lines(int lines);

/* add padding to the board from the left */
void print_left_padding(unsigned int padding);

/* prints the game header for all screens */
void print_header();

/* prints the game footer for all screens */
void print_footer();

#endif // !DISPLAY_COMMON_DISPLAY_HPP

