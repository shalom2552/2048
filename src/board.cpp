#include "../inc/board.hpp"
#include "../inc/utils/display.hpp"

#include <cstddef>  // std::size_t
#include <vector>   // std::vector

Board::Board(std::size_t size)
    : m_size(size)
    , m_board(size, std::vector<Cell>(size))
{
}

std::size_t Board::size() const
{
    return m_size;
}

void Board::render()
{
    print_board(*this);
}

