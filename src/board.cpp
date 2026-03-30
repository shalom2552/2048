#include "../inc/board.hpp"
#include "../inc/utils/display.hpp"

#include <cassert>
#include <cstddef>  // std::size_t
#include <vector>   // std::vector

Board::Board(std::size_t size)
    : m_size(size)
    , m_board(size, std::vector<Cell>(size))
{
}

void Board::render()
{
    clear_screen();
    print_board(*this);
}

std::size_t Board::size() const
{
    return m_size;
}

const std::vector<std::vector<Cell>>& Board::get_board() const
{
    return m_board;
}

std::size_t Board::count_empty_cells() const
{
    std::size_t count = 0;
    for (auto const& row : m_board) {
        for (Cell const& cell : row) {
            if (cell.value == 0) {
                ++count;
            }
        }
    }
    return count;
}

void Board::generate_new_cell()
{
    std::size_t count = count_empty_cells();
    if (count == 0) return;

    int random_cell = rand() % count;
    place_empty_cell(random_cell);
}

void Board::place_empty_cell(std::size_t i)
{
    for (auto& row : m_board) {
        for (Cell& cell : row) {
            if (cell.value == 0) {
                if (i == 0) {
                    cell.value = 2;
                    return;
                }
                --i;
            }
        }
    }
}

