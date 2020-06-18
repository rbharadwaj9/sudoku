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
        
        void solve(const Coordinate curr_coordinate, uint8_t possible_number);
        void print_solution();
        const Coordinate get_start_coordinate();

    private:
        bool is_solution();
        bool is_promising(const Coordinate c1, uint8_t number);
        uint8_t _get_box_id(const Coordinate c);
        const Coordinate _get_next_coodinate(const Coordinate c1);
        const Coordinate _get_unchecked_coordinate(const Coordinate c1);
        bool _is_empty_coordinate(const Coordinate c);
        Board &board;
};

struct SolveException
{
    class SolutionFound : std::exception
    {
        public:
            const char* what() const noexcept
            {
                return "Solution found!";
            }
    };

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

    class NextCoordinateException : std::exception
    {
        public:
            NextCoordinateException() : msg("Can't find next coordinate")
        {}
            const char *what() const noexcept
            {
                return msg.c_str();
            }
        private:
            std::string msg;
    };
};

#endif
