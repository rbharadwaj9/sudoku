/* Board.cpp */

/* File implements the sudoku board class. */ 

/* 13 June, 2020 */
/* Rajiv Bharadwaj */

#include "Board.h"

Board::Board() : status(std::vector<std::vector<bool> >(9, std::vector<bool>(9, false))),
    grid(std::vector<std::vector<Coordinate> >(9, std::vector<Coordinate>()))
{
    for (size_t i = 0; i < 9; ++i)
        grid[i].reserve(9);
}
