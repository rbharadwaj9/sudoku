/* Solve.cpp */

/* File implements functions that solve the sudoku puzzle. */

/* 15 June, 2020 */
/* Rajiv Bharadwaj */

#include "Solve.h"

Solve::Solve(Board &board_in) : board(board_in)
{}

uint8_t Solve::_get_box_id(const Coordinate c)
{
    uint8_t row = c.first;
    uint8_t col = c.second;
    if (row < 3 && col < 3)
        return 0;
    else if (row < 3 && (col >= 3 && col < 6))
        return 1;
    else if (row < 3 && (col >= 6 && col < 9))
        return 2;
    else if ((row >= 3 && row < 6) && col < 3)
        return 3;
    else if ((row >= 3 && row < 6) && (col >= 3 && col < 6))
        return 4;
    else if ((row >= 3 && row < 6) && (col >= 6 && col < 9))
        return 5;
    else if ((row >= 6 && row < 9) && col < 3)
        return 6;
    else if ((row >= 6 && row < 9) && (col >= 3 && col < 6))
        return 7;
    else if ((row >= 6 && row < 9) && (col >= 6 && col < 9))
        return 8;
    throw SolveException::CoordinateException(c);
}

bool Solve::is_promising(const Coordinate c1, uint8_t number)
{
    uint8_t c1_box = _get_box_id(c1);
    for (const auto c2 : board.occupied_grid[number])
    {
        uint8_t c2_box = _get_box_id(c2); 
        if ((c1_box == c2_box) || (c1.first == c2.first) || (c1.second == c2.second))
            return false;
    }
    return true;
}

int main()
{
    Board b = Board(std::cin);
    Coordinate c = {0,1};
    Solve s = Solve(b);
    s.stuff(c);
}
