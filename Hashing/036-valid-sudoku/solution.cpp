#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    vector<unordered_set<char>> rows(9); 
    vector<unordered_set<char>> cols(9);
    vector<unordered_set<char>> boxes(9);
    for(int r = 0; r < 9; r++)
    {
        for(int c = 0; c < 9; c++){
            int boxIndex = (r / 3) * 3 + (c / 3);
            if(board[r][c] == '.'){
                continue;
            }
          if(rows[r].count(board[r][c])){
            return false;
          }
          else{
            rows[r].insert(board[r][c]);
          }
          if(cols[c].count(board[r][c])){
            return false;
          }
          else{
             cols[c].insert(board[r][c]); 
          }
          if(boxes[boxIndex].count(board[r][c])){
            return false;
          }
          else{
               boxes[boxIndex].insert(board[r][c]);   
          }  
        }
    }
    return true;
}
};
