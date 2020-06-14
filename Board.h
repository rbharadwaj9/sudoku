/* Board.h */

/* File defines the sudoku board class. */ 

/* 13 June, 2020 */
/* Rajiv Bharadwaj */

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

using Coordinate = std::pair<char, char>;

class Board
{
    public:
        Board();
    private:
        std::vector<std::vector<bool> > status;
        std::vector<std::vector<Coordinate> > grid;
};

#endif
