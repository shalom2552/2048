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
        print_buffer_row(size);
        print_board_row(size, board.get_board()[i]);
        print_buffer_row(size);
    }
    print_bottom_border(size);
}

void print_cell(int value)
{
    std::string svalue = std::to_string(value);
    if (svalue == "0") svalue = " ";
    int padding = BOX_CELL_WIDTH - svalue.size();
    int left = padding / 2;
    int right = padding - left;
    std::cout << std::string(left, ' ') << svalue << std::string(right, ' ');
}

std::size_t get_printable_size(std::size_t size)
{
    // 3 palaces for cell and 1 for separator (|_0_|)
    return (BOX_CELL_WIDTH + 1) * size + 1;
}

void print_board_row(std::size_t size, std::vector<Cell> const& row)
{
    size = get_printable_size(size);
    std::size_t cell_idx = 0;

    print_left_padding();
    print_char(ANSII_BOX_VR);
    for (std::size_t i = 1; i < size - 1; ++i) {

        // cell value
        if ((i + 2) % (BOX_CELL_WIDTH + 1) == 0) {
            int value = row[cell_idx].value;
            print_cell(value);
        }
        // new cell - add vertival border
        else if (i % (BOX_CELL_WIDTH + 1) == 0) {
            print_char(ANSII_BOX_VR);
            ++cell_idx;
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

void print_buffer_row(std::size_t size)
{
    print_box_row(size, ANSII_BOX_VR, ANSII_BOX_VR, " ", ANSII_BOX_VR);
}

void print_box_row(std::size_t size, Ansi left, Ansi sep, Ansi mid, Ansi right)
{
    size = get_printable_size(size);
    print_left_padding();
    print_char(left);
    for (std::size_t i = 1; i < size - 1; ++i) {
        if (i % (BOX_CELL_WIDTH + 1) == 0) print_char(sep);
        else print_char(mid);
    }
    print_char(right);
    print_char("\n");
}

void print_left_padding()
{
    std::cout << std::string(BOX_LEFT_PADNG, ' ');
}

