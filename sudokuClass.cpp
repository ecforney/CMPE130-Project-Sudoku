#include "sudokuClass.h"
#include <iostream>
using namespace std;

SudokuBoard::SudokuBoard(const vector<vector<int>>& initialBoard) {
    board = initialBoard;
}

bool SudokuBoard::solve() {
    int row, col;

    if(!findEmptyCell(row, col)) {          //Puzzle is solved
        return true;             
    }

    for(int num = 1; num <= 9; num++) {
        if(isValid(row, col, num)) {        //If num is valid at current cell
            board[row][col] = num;          //Assign num to current cell

            if(solve()) {                   //Recursively call solve() to solve puzzle
                return true;
            }

            board[row][col] = 0;            //If not solved, reset cell and try a diff num
        }
    }
    return false;                           //Backtrack if no num is valid
}

bool SudokuBoard::isValid(int row, int col, int num) {
    for(int i = 0; i < 9; i++) {            //Test if num is in row or col
        if(board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    
    int subRow = row - (row % 3);           //Test if num is in the 3x3 sub grid
    int subCol = col - (col % 3);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i + subRow][j + subCol] == num) {
                return false;
            }
        }
    }
    return true;                            //Return true if num passes all 3 tests
}

bool SudokuBoard::findEmptyCell(int& row, int& col) {
    for(row = 0; row < 9; row++) {
        for(col = 0; col < 9; col++) {
            if(board[row][col] == 0) {
                return true;                //Empty cell found at row,col
            }
        }
    }
    return false;                           //No empty cells found, board solved
}

void SudokuBoard::printBoard() {
    for(const auto& row : board) {           
        for(int num : row) {                    
            cout << num << " ";
        }
        cout << endl;
    }
}

