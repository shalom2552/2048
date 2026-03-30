#include "../../inc/utils/display.hpp"
#include "../../inc/constants.hpp"
#include "../../inc/board.hpp"

#include <cstddef>  // std::size_t
#include <iostream> // std::cout
#include <string>
#include <vector>   // std::vector

void print_board(Board const& board)
{
    std::size_t size = board.size();
    print_top_border(size);
    for (std::size_t i = 0; i < size; ++i) {
        if (i > 0) print_border_row(size);
        print_row(size, board.get_board()[i]);
    }
    print_bottom_border(size);
}

std::size_t get_printable_size(std::size_t size)
{
    // 3 palaces for cell and 1 for separator (|_0_|)
    return 4 * size + 1;
}

void print_char(std::string const& c)
{
    std::cout << c;
}

void print_top_border(std::size_t size)
{
    size = get_printable_size(size);
    print_char(BOX_TL);
    for (std::size_t i = 1; i < size - 1; ++i) {
        if (i % 4 == 0) print_char(BOX_TM);
        else print_char(BOX_HZ);
    }
    print_char(BOX_TR);
    print_char("\n");
}

void print_row(std::size_t size, std::vector<Cell> const& row)
{
    size = get_printable_size(size);
    print_char(BOX_VR);
    for (std::size_t i = 1; i < size - 1; ++i) {
        if ((i + 2) % 4 == 0) print_char(std::to_string(row[i % 4].value));
        else if (i % 4 == 0) print_char(BOX_VR);
        else print_char(" ");
    }
    print_char(BOX_VR);
    print_char("\n");
}

void print_border_row(std::size_t size)
{
    size = get_printable_size(size);
    print_char(BOX_VR);
    for (std::size_t i = 1; i < size - 1; ++i) {
        if (i % 4 == 0) print_char(BOX_CR);
        else print_char(BOX_HZ);
    }
    print_char(BOX_VR);
    print_char("\n");
}

void print_bottom_border(std::size_t size)
{
    size = get_printable_size(size);
    print_char(BOX_BL);
    for (std::size_t i = 1; i < size - 1; ++i) {
        if (i % 4 == 0) print_char(BOX_BM);
        else print_char(BOX_HZ);
    }
    print_char(BOX_BR);
    print_char("\n");
}

