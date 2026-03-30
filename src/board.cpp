#include "../inc/board.hpp"
#include "../inc/utils/display.hpp"

#include <cstddef>  // std::size_t
#include <vector>   // std::vector

Board::Board(std::size_t size)
    : m_size(size)
    , m_board(size, std::vector<Cell>(size))
{
}

void Board::render()
{
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
