#include "sudokuClass.cpp"
#include <iostream>
#include <chrono>

int main() {
    SudokuBoard sudoku;

    sudoku.readBoardFromFile("initialBoard.txt");

    auto start = chrono::high_resolution_clock::now();
    if (sudoku.solve()) {
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> runtime = end - start;
        sudoku.setRuntime(runtime.count());

        sudoku.printBoardToFile("solvedBoard.txt");
        cout << "Sudoku puzzle solved successfully.\n";
    } else {
        cout << "No solution exists for the given Sudoku puzzle.\n";
    }

    return 0;
}