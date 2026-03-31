#include "../inc/board.hpp"
#include "../inc/utils/display.hpp"

#include <algorithm>    // std::reverse
#include <cstddef>      // std::size_t
#include <vector>       // std::vector

Board::Board(std::size_t size)
    : m_size(size)
    , m_board(size, std::vector<Cell>(size))
    , m_changed(false)
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

bool Board::has_valid_move()
{
    if (count_empty_cells() > 0) return true;

    // check for equal neighbors
    for (std::size_t row = 0; row < m_size; ++row) {
        for (std::size_t col = 0; col < m_size; ++col) {
            if (row + 1 < m_size && m_board[row + 1][col].value == m_board[row][col].value) return true;
            if (col + 1 < m_size && m_board[row][col + 1].value == m_board[row][col].value) return true;
        }
    }
    return false;
}

void Board::collapse_move(InputEvent direction)
{
    m_changed = false;
    bool is_row = (direction == INPUT_RIGHT || direction == INPUT_LEFT);
    bool forward = (direction == INPUT_LEFT || direction == INPUT_UP);

    for (std::size_t index = 0; index < m_size; ++index) {
        auto line = extract_line(index, is_row);
        collapse_line(line, forward);
        write_line(index, is_row, line);
    }
}

std::vector<int> Board::extract_line(std::size_t index, bool is_row)
{
    std::vector<int> line;
    for (std::size_t i = 0; i < m_size; ++i) {
        if (is_row)
            line.push_back(m_board[index][i].value);
        else
            line.push_back(m_board[i][index].value);
    }
    return line;
}

void Board::write_line(std::size_t index, bool is_row, std::vector<int>& line)
{
    for (std::size_t i = 0; i < m_size; ++i) {
        if (is_row)
            m_board[index][i].value = line[i];
        else
            m_board[i][index].value = line[i];
    }
}

void Board::collapse_line(std::vector<int>& line, bool forward)
{
    if ( !forward )
        std::reverse(line.begin(), line.end());

    std::vector<int> result(m_size, 0);
    std::size_t write = 0;
    bool merged = false;    // so we dont merge merged

    for (int row = 0; row < (int)m_size; ++row) {
        int value = line[row];
        if (value == 0) continue;

        // just write first value, nothing to compare
        if (write == 0) {
            result[write++] = value;

        } else if ( !merged && value == result[write - 1] ) {
            result[write - 1] += value;

        } else {
            result[write++] = value;
            merged = false;
        }
    }

    if (line != result) {
        m_changed = true;
    }

    if ( !forward ) {
        std::reverse(result.begin(), result.end());
    }

    line = result;
}

bool Board::changed()
{
    return m_changed;
}

