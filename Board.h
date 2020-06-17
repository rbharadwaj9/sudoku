/* Board.h */

/* File defines the sudoku board class. */ 

/* Some conventions: */ 
/* Except for the input file, all numbers start from 0 to 8 */

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
        // Board(generate=true);
        void print_state();
        void print_occupancy_grid();
        std::vector<std::vector<bool> > state;
        std::vector<std::vector<Coordinate> > occupied_grid;

    private:
        bool is_number(unsigned char &c);
};

struct BoardException
{
    class InvalidInput : std::exception
    {
        public:
            InvalidInput(unsigned char &msg_in) : msg(msg_in)
            {}

            const char* what() const noexcept
            {
                std::string retval = "InvalidInputException: Not a valid input - ";
                retval.push_back(static_cast<char>(msg));
                return retval.c_str();
            }
        private:
            unsigned char msg;
    };
};

#endif
