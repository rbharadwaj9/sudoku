/* Board.h */

/* File defines the sudoku board class. */ 

/* 13 June, 2020 */
/* Rajiv Bharadwaj */

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <exception>
#include <cstdint>

using Coordinate = std::pair<uint8_t, uint8_t>;

class Board
{
    public:
        Board();
        Board(std::istream &file);
    private:
        bool is_number(char &c);
        std::vector<std::vector<bool> > status;
        std::vector<std::vector<Coordinate> > grid;
};

struct BoardException
{
    class InvalidInput : std::exception
    {
        public:
            InvalidInput(char &msg_in) : msg(msg_in)
            {}

            const char* what() const noexcept
            {
                std::string retval = "InvalidInputException: Not a valid input - ";
                retval.push_back(msg);
                return retval.c_str();
            }
        private:
            char msg;
    };
};

#endif
