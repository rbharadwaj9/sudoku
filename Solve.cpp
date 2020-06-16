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
    assert(false);
}
