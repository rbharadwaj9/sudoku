/* Board.cpp */

/* File implements the sudoku board class. */ 

/* 13 June, 2020 */
/* Rajiv Bharadwaj */

#include "Board.h"

Board::Board() : state(std::vector<std::vector<bool> >(9, std::vector<bool>(9, false))),
    occupied_grid(std::vector<std::vector<Coordinate> >(9, std::vector<Coordinate>()))
{
    for (size_t i = 0; i < 9; ++i)
        occupied_grid[i].reserve(9);
}

Board::Board(std::istream &file)
{
    *this = Board();
    
    std::string line;
    getline(file, line);

    unsigned char val;
    for (uint8_t i = 0; i < 9; ++i)
    {
        for (uint8_t j = 0; j < 9; ++j)
        {
            file >> val;

            if (val == 'x')
                continue;
            if (!is_number(val))
                throw BoardException::InvalidInput(val);
            this->occupied_grid[(val-'0')-1].emplace_back(i,j);
            state[i][j] = true;
        }
    }
}

bool Board::is_number(unsigned char &c)
{
    if (c >= '1' && c <= '9')
        return true;
    return false;
}
