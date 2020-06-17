/* Solve.h */

/* File declares definitions related to solving the puzzle. */

/* Some conventions: */
/* A square is the 1x1 square where one unique number goes in. */
/* A box is one of nine 3x3 squares on the board where one must check for uniqueness */

/* 15 June, 2020 */
/* Rajiv Bharadwaj */

#ifndef SOLVE_H
#define SOLVE_H

#include <iostream>
#include <cstdint>

#include "Board.h"

using Coordinate = std::pair<uint8_t, uint8_t>;

class Solve
{
    public:
        Solve(Board &board_in);

    private:
        bool is_promising(const Coordinate c1, uint8_t number);
        uint8_t _get_box_id(const Coordinate c);
        Board &board;
};

struct SolveException
{
    class CoordinateException : std::exception
    {
        public:
            CoordinateException(const Coordinate c) : msg(c)
            {}

            const char* what() const noexcept
            {
                std::string retval = "CoordinateException: Not a valid coordinate: (";
                retval += std::to_string(msg.first);
                retval += ",";
                retval += std::to_string(msg.second);
                retval += ")";
                return retval.c_str();
            }
        private:
            const Coordinate msg;
    };
};

#endif
