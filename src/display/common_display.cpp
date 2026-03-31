#include "../../inc/display/common_display.hpp"
#include "../../inc/constants.hpp"

#include <iostream>     // std::cout

void clear_screen()
{
    print_char(ANSI_CLEAR);
}

void print_char(std::string const& c)
{
    std::cout << c;
}

void print_left_padding(unsigned int padding)
{
    std::cout << std::string(padding, ' ');
}

