#include <iostream>
#include <fstream>
#include <vector>
#include "sudokuClass.h"

using namespace std;

const int N = 9;

// Constructor
SudokuBoard::SudokuBoard() {
    board.resize(N, vector<int>(N, 0));
}

void SudokuBoard::setRuntime(double time) {
    this->runtime = time;
}

// Function to check if it's safe to place a number in the given position
bool SudokuBoard::isValid(int row, int col, int num) {
    // Check if the number is not already present in the current row, column, and box
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num || board[row - row % 3 + i / 3][col - col % 3 + i % 3] == num) {
            return false;
        }
    }
    return true;
}

// Function to find an empty cell in the Sudoku grid
bool SudokuBoard::findEmptyCell(int& row, int& col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                return true; // Found an empty cell
            }
        }
    }
    return false; // No empty cell found
}

// Recursive function to solve the Sudoku puzzle
bool SudokuBoard::solve() {
    int row, col;

    // Check if there's any unassigned position
    if (!findEmptyCell(row, col)) {
        return true; // Puzzle solved
    }

    // Try placing numbers from 1 to 9
    for (int num = 1; num <= 9; num++) {
        // Check if it's safe to place 'num' in the current position
        if (isValid(row, col, num)) {
            // Assign 'num' to the current position
            board[row][col] = num;

            // Recur to solve the rest of the puzzle
            if (solve()) {
                return true;
            }

            // If assigning 'num' doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    // If no number can be placed in the current position, return false
    return false;
}

// Function to read the Sudoku board from file
void SudokuBoard::readBoardFromFile(string filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Unable to open the file.\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inputFile >> board[i][j];
        }
    }
    inputFile.close();
}

// Function to print the Sudoku grid to file
void SudokuBoard::printBoardToFile(string filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Error: Unable to create the file.\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            outputFile << board[i][j] << " ";
        }
        outputFile << endl;
    }
    outputFile << "\nRuntime: " << this->runtime << " seconds" << endl;

    outputFile.close();
}