#include "../../inc/utils/display.hpp"
#include "../../inc/constants.hpp"
#include "../../inc/board.hpp"
#include "../../inc/types.hpp"

#include <cstddef>  // std::size_t
#include <iostream> // std::cout
#include <string>   // std::string
#include <vector>   // std::vector

void clear_screen()
{
    print_char(ANSI_CLEAR);
}

void print_char(std::string const& c)
{
    std::cout << c;
}

void print_board(Board const& board)
{
    std::size_t size = board.size();
    print_top_border(size);
    for (std::size_t i = 0; i < size; ++i) {
        if (i > 0) print_border_row(size);
        print_board_row(size, board.get_board()[i]);
    }
    print_bottom_border(size);
}

std::size_t get_printable_size(std::size_t size)
{
    // 3 palaces for cell and 1 for separator (|_0_|)
    return 4 * size + 1;
}

void print_board_row(std::size_t size, std::vector<Cell> const& row)
{
    print_char(ANSII_BOX_VR);
    size = get_printable_size(size);

    std::size_t cell_idx = 0;
    for (std::size_t i = 1; i < size - 1; ++i) {

        // cell value
        if ((i + 2) % 4 == 0) {
            std::string value = std::to_string(row[cell_idx].value);
            if (value == "0") value = " ";
            print_char(value);
        }
        // new cell - add vertival border
        else if (i % 4 == 0) {
            print_char(ANSII_BOX_VR);
            ++cell_idx;
        }
        else {
            print_char(" ");
        }
    }
    print_char(ANSII_BOX_VR);
    print_char("\n");
}

void print_top_border(std::size_t size)
{
    print_box_row(size, ANSII_BOX_TL, ANSII_BOX_TM, ANSII_BOX_HZ, ANSII_BOX_TR);
}

void print_bottom_border(std::size_t size)
{
    print_box_row(size, ANSII_BOX_BL, ANSII_BOX_BM, ANSII_BOX_HZ, ANSII_BOX_BR);
}

void print_border_row(std::size_t size)
{
    print_box_row(size, ANSII_BOX_VR, ANSII_BOX_CR, ANSII_BOX_HZ, ANSII_BOX_VR);
}

void print_box_row(std::size_t size, Ansi left, Ansi sep, Ansi mid, Ansi right)
{
    size = get_printable_size(size);
    print_char(left);
    for (std::size_t i = 1; i < size - 1; ++i) {
        if (i % 4 == 0) print_char(sep);
        else print_char(mid);
    }
    print_char(right);
    print_char("\n");
}

