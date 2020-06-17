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

void Board::print_solution()
{
    std::vector<std::vector<uint8_t> > soln(9, std::vector<uint8_t>(8, '.'));
    for (size_t i = 0; i < 9; ++i)
    {
        for (const auto coord : occupied_grid[i])
        {
            soln[coord.first][coord.second] = static_cast<uint8_t>(i);
        }
    }
    for (const auto &row : soln)
    {
        for (auto col : row)
            std::cout << static_cast<char>(col+'0') << " ";
        std::cout << "\n";
    }
}

void Board::print_state()
{
    for (const auto &row : state)
    {
        for (auto col : row)
            std::cout << col << " ";
        std::cout << "\n";
    }
}

void Board::print_occupancy_grid()
{
    for (size_t i = 0; i < 9; ++i)
    {
        std::cout << "Number: " << i << std::endl;
        for (size_t j = 0; j < occupied_grid[i].size(); ++j)
        {
            std::cout << "(" << occupied_grid[i][j].first-0 << "," <<
                occupied_grid[i][j].second-0 << ")";
        }
        std::cout << "\n";
    }
}
