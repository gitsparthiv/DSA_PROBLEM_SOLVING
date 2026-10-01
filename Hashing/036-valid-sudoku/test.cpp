#include <iostream>
#include <vector>
#include <string>
#include "solution.cpp"

using namespace std;

void runTestCase(int testNum, vector<vector<char>> board, bool expected) {
    Solution sol;
    bool actual = sol.isValidSudoku(board);
    
    bool passed = (actual == expected);
    cout << "Test Case " << testNum << ": ";
    if (passed) {
        cout << "[PASSED]\n";
    } else {
        cout << "[FAILED]\n";
        cout << "  Expected: " << (expected ? "true" : "false") << "\n";
        cout << "  Actual:   " << (actual ? "true" : "false") << "\n";
    }
}

int main() {
    cout << "=== Running Tests for 36. Valid Sudoku ===\n\n";

    // Example 1: Valid board
    vector<vector<char>> board1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    runTestCase(1, board1, true);

    // Example 2: Invalid board (duplicate 8 in top-left 3x3 box)
    vector<vector<char>> board2 = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    runTestCase(2, board2, false);

    return 0;
}
