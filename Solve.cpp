/* Solve.cpp */

/* File implements functions that solve the sudoku puzzle. */

/* 15 June, 2020 */
/* Rajiv Bharadwaj */

#include "Solve.h"

Solve::Solve(Board &board_in) : board(board_in)
{}

void Solve::solve(const Coordinate curr_coordinate, uint8_t possible_number)
{
    /* #ifdef DEBUG */
    /*     if (curr_coordinate.first == 0) */
    /*     { */
    /*         board.print_state(); */
    /*         board.print_occupancy_grid(); */
    /*         board.print_solution(); */
    /*         std::cout << "BREAKPOINT" << std::endl; */
    /*     } */
    /* #endif */
    if (is_promising(curr_coordinate, possible_number))
    {
        board.state[curr_coordinate.first][curr_coordinate.second] = true;
        board.occupied_grid[possible_number].emplace_back(curr_coordinate.first, 
                curr_coordinate.second);
        if (is_solution())
        {
            std::cout << "FOUND SOLUTION" << std::endl;
            throw SolveException::SolutionFound();
        }
        else
        {
            const Coordinate next_coordinate = _get_next_coodinate(curr_coordinate);
            for (uint8_t num = 0; num < 9; ++num)
                solve(next_coordinate, num);
            board.state[curr_coordinate.first][curr_coordinate.second] = false;
            board.occupied_grid[possible_number].pop_back();
        }
    }
}

const Coordinate Solve::get_start_coordinate()
{
    Coordinate origin = {0,0};
    if (board.state[0][0])
        return _get_next_coodinate(origin);
    return origin;
}

bool Solve::_is_empty_coordinate(const Coordinate c)
{
    if (board.state[c.first][c.second])
        return false;
    return true;
}

const Coordinate Solve::_get_unchecked_coordinate(const Coordinate c1)
{
    if (c1.first > 8 || c1.second > 8)
        throw SolveException::NextCoordinateException(); 

    if (c1.second == 8)
        return {c1.first+1, 0};
    return {c1.first, c1.second+1};
}

const Coordinate Solve::_get_next_coodinate(Coordinate c1)
{
    while (true)
    {
        const Coordinate retval = _get_unchecked_coordinate(c1);
        if (_is_empty_coordinate(retval))
            return retval;
        c1 = retval;
    }
}

bool Solve::is_solution()
{
    for (const auto &row : board.state)
        for (auto col : row)
            if (!col)
                return false;
    return true;
}
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

void Solve::print_solution()
{
    board.print_solution();
}
