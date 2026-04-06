#include "../../inc/display/common_display.hpp"
#include "../../inc/constants.hpp"

#include <iostream>     // std::cout
#include <string>

void clear_screen()
{
    print_char(ANSI_CLEAR);
}

void print_char(std::string const& c)
{
    std::cout << c;
}

void print_line(std::string const& line)
{
    std::cout << line << "\n";
}

void print_padded_line(int padding, std::string const& line)
{
    print_left_padding(padding);
    print_line(line);
}

void print_padding(int padding)
{
    std::cout << std::string(padding, '\t');
}

void print_empty_lines(int lines)
{
    print_char(std::string(lines, '\n'));
}

void print_left_padding(unsigned int padding)
{
    print_char(std::string(padding, '\t'));
}

void print_header()
{
    print_empty_lines(3);
    int padding = HEADER_PAADING;
    print_padded_line(padding, "██████╗  ██████╗ ██╗  ██╗ █████╗ ");
    print_padded_line(padding, "╚════██╗██╔═████╗██║  ██║██╔══██╗");
    print_padded_line(padding, " █████╔╝██║██╔██║███████║╚█████╔╝");
    print_padded_line(padding, "██╔═══╝ ████╔╝██║╚════██║██╔══██╗");
    print_padded_line(padding, "███████╗╚██████╔╝     ██║╚█████╔╝");
    print_padded_line(padding, "╚══════╝ ╚═════╝      ╚═╝ ╚════╝ ");
    print_empty_lines(3);
}

void print_footer()
{
    print_empty_lines(3);
    std::string footer = "Made by shalom2552";
    print_padded_line(FOOTER_PADDING, footer);
}

