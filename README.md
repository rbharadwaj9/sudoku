# Sudoku Solver

Rajiv Bharadwaj - rajivbh@umich.edu  
June 2020

### Just a simple backtracking algorithm based sudoku solver.
Using a self written backtracking algorithm, this solver is able to solve most puzzles within 5 seconds. Some example boards are given under `boards/`

## Compiling and running the program
Compiling:
```bash
$ make
```

Running:
```bash
$ ./sudoku < [Name of board file]
```

## Board formatting
A simple text file is passed in as the clue puzzle. 
The first line is always a comment describing the puzzle.
Second line onwards must describe the board, and must contain only the numbers 1-9 and "x" for empty spaces.

```txt
# boards/board.1.easy.txt
4 x 3 2 x x x x x
9 x x 7 x 5 x 4 8
x 6 x x x 8 2 3 1
x x 7 x 2 x x 9 6
x x x 3 x 7 5 1 x
6 5 4 x 8 1 x x x
x x 1 6 x x 3 x x
x 7 x x 4 9 x 5 2
8 2 x x 5 x 4 x 7
```

## Future Developments
I want to try and build a generator, a front end, and an inputtable solver so that this project is a full fledged sudoku game. This will also involve integration with multiple languages if possible because that's something I haven't done before!


