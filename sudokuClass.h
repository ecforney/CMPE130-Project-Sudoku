#ifndef sudokuClass_h
#define sudokuClass_h

#include <vector>
using namespace std;

class SudokuBoard{
private:
    vector<vector<int>> board;
public:
    SudokuBoard(const vector<vector<int>>& initialBoard);
    bool solve();
    bool isValid(int row, int col, int num);
    bool findEmptyCell(int& row, int&col);
    void printBoard();
};

#endif