/* main.cpp */

/* Driver Program. At the moment it's not too complicated but this should be the endpoint */ 
/* to the algorithmic side of the project. */

/* 17 June, 2020 */
/* Rajiv Bharadwaj */

#include <iostream>
#include "Solve.h"

int main()
{
    Board board = Board(std::cin);
    Solve solver = Solve(board);
    Coordinate start = solver.get_start_coordinate();
    try
    {
        for (uint8_t i = 0; i < 9; ++i)
            solver.solve(start, i);
        std::cout << "Couldn't find a solution...\n";
    }
    catch (SolveException::SolutionFound &e)
    {
        solver.print_solution();
    }
}
