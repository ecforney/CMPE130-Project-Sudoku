#ifndef sudokuClass_h
#define sudokuClass_h

#include <vector>
#include <string>
using namespace std;

class SudokuBoard{
private:
    vector<vector<int>> board;
    double runtime;
public:
    SudokuBoard();
    bool solve();
    bool isValid(int row, int col, int num);
    bool findEmptyCell(int& row, int&col);

    void readBoardFromFile(string filename);
    void printBoardToFile(string filename);
    void setRuntime(double time);
};

#endif