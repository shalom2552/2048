#include "../../inc/display/board_display.hpp"
#include "../../inc/display/common_display.hpp"
#include "../../inc/constants.hpp"
#include "../../inc/board.hpp"
#include "../../inc/types.hpp"

#include <cmath>    // std::log2
#include <cstddef>  // std::size_t
#include <iostream> // std::cout
#include <string>   // std::string
#include <vector>   // std::vector

void print_score(int score, int moves)
{
    using namespace std::string_literals;
    std::string sscore = std::to_string(score);
    std::string smoves = std::to_string(moves);
    std::string stats = "Score: "s + sscore + "\t Moves: "s + smoves;
    print_padded_line(SCORE_PADDING, stats);
}

void print_board(Board const& board)
{
    std::size_t size = board.size();
    print_board_top_border(size);
    for (std::size_t i = 0; i < size; ++i) {
        if (i > 0) print_board_border_row(size);
        print_board_buffer_row(size);  // add height to the board
        print_board_row(size, board.get_board()[i]);
        print_board_buffer_row(size);
    }
    print_board_bottom_border(size);
}

std::string get_cell_color(int value)
{
    if (value == 0) return ANSI_COLOR_RESET;
    int color_index = static_cast<int>(std::log2(value)) - 1;
    return CELL_COLORS[color_index];
}

void print_board_cell(int value)
{
    std::string svalue = std::to_string(value);
    if (svalue == "0") svalue = " ";

    // print cell with padding
    int padding = BOX_CELL_WIDTH - svalue.size();
    int left = padding / 2;
    int right = padding - left;

    print_char(ANSI_COLOR_BOLD + get_cell_color(value));
    std::cout << std::string(left, ' ') << svalue << std::string(right, ' ');
    print_char(ANSI_COLOR_RESET);
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

    print_left_padding(BOX_LEFT_PADNG);
    print_char(ANSI_BOX_VR);
    for (std::size_t i = 1; i < size - 1; ++i) {

        // cell value
        if ((i + 2) % (BOX_CELL_WIDTH + 1) == 0) {
            int value = row[cell_idx].value;
            print_board_cell(value);
        }
        // new cell - add vertival border
        else if (i % (BOX_CELL_WIDTH + 1) == 0) {
            print_char(ANSI_BOX_VR);
            ++cell_idx;
        }
    }
    print_char(ANSI_BOX_VR);
    print_char("\n");
}

void print_board_row(std::size_t size, Ansi left, Ansi sep, Ansi mid, Ansi right)
{
    size = get_printable_size(size);
    print_left_padding(BOX_LEFT_PADNG);
    print_char(left);
    for (std::size_t i = 1; i < size - 1; ++i) {
        if (i % (BOX_CELL_WIDTH + 1) == 0) print_char(sep);
        else print_char(mid);
    }
    print_char(right);
    print_char("\n");
}

void print_board_top_border(std::size_t size)
{
    print_board_row(size, ANSI_BOX_TL, ANSI_BOX_TM, ANSI_BOX_HZ, ANSI_BOX_TR);
}

void print_board_bottom_border(std::size_t size)
{
    print_board_row(size, ANSI_BOX_BL, ANSI_BOX_BM, ANSI_BOX_HZ, ANSI_BOX_BR);
}

void print_board_border_row(std::size_t size)
{
    print_board_row(size, ANSI_BOX_VR, ANSI_BOX_CR, ANSI_BOX_HZ, ANSI_BOX_VR);
}

void print_board_buffer_row(std::size_t size)
{
    print_board_row(size, ANSI_BOX_VR, ANSI_BOX_VR, " ", ANSI_BOX_VR);
}

