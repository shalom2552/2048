#include "../../inc/utils/display.hpp"
#include "../../inc/constants.hpp"
#include "../../inc/board.hpp"

#include <cstddef>  // std::size_t
#include <iostream> // std::cout

void print_board(Board const& board)
{
    print_top_boarder(board.size());

    print_bottom_boarder(board.size());
}

std::size_t get_printable_size(std::size_t size)
{
    // 3 palaces for cell and 1 for separator (|_0_|)
    return 4 * size + 1;
}

void print_char(std::string c)
{
    std::cout << c;
}

void print_top_boarder(std::size_t size)
{
    size = get_printable_size(size);
    print_char(BOX_TL);
    for (std::size_t i = 1; i < size - 1; ++i) {
        if (i % 4 == 0) {
            print_char(BOX_TM);
        } else {
            print_char(BOX_HZ);
        }
    }
    print_char(BOX_TR);
    print_char("\n");
}

void print_bottom_boarder(std::size_t size)
{
    size = get_printable_size(size);
    print_char(BOX_BL);
    for (std::size_t i = 1; i < size - 1; ++i) {
        if (i % 4 == 0) {
            print_char(BOX_BM);
        } else {
            print_char(BOX_HZ);
        }
    }
    print_char(BOX_BR);
    print_char("\n");
}

