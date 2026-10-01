# 36. Valid Sudoku

**Difficulty:** Medium  
**Topic:** Hashing / Matrix  
**LeetCode Link:** [36. Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)

---

## Problem Statement

Determine if a $9 \times 9$ Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

1. Each row must contain the digits `1-9` without repetition.
2. Each column must contain the digits `1-9` without repetition.
3. Each of the nine $3 \times 3$ sub-boxes of the grid must contain the digits `1-9` without repetition.

**Note:**
- A Sudoku board (partially filled) could be valid but is not necessarily solvable.
- Only the filled cells need to be validated according to the mentioned rules.

---

### Examples

#### Example 1:
- **Input:**
```
[["5","3",".",".","7",".",".",".","."],
 ["6",".",".","1","9","5",".",".","."],
 [".","9","8",".",".",".",".","6","."],
 ["8",".",".",".","6",".",".",".","3"],
 ["4",".",".","8",".","3",".",".","1"],
 ["7",".",".",".","2",".",".",".","6"],
 [".","6",".",".",".",".","2","8","."],
 [".",".",".","4","1","9",".",".","5"],
 [".",".",".",".","8",".",".","7","9"]]
```
- **Output:** `true`

#### Example 2:
- **Input:** Same as Example 1, but top-left cell changed to `"8"`.
- **Output:** `false` (Two `"8"`s in the top-left $3 \times 3$ sub-box).

---

### Constraints

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j]` is a digit `'1'-'9'` or `'.'`.

---

## My Approach

1. **State Tracking with Vector of HashSets:**
   - Create 3 vectors of 9 `unordered_set<char>`:
     - `rows(9)`: Tracks digits seen in each row ($0$ to $8$).
     - `cols(9)`: Tracks digits seen in each column ($0$ to $8$).
     - `boxes(9)`: Tracks digits seen in each $3 \times 3$ sub-box ($0$ to $8$).

2. **Sub-box 1D Index Formula:**
   - Map 2D cell `(r, c)` to its corresponding $3 \times 3$ sub-box index ($0 \dots 8$) using:
     $$\text{boxIndex} = (r / 3) \times 3 + (c / 3)$$

3. **Single-Pass Validation:**
   - Traverse through the grid cell by cell `(r, c)`:
     - If `board[r][c] == '.'`, skip.
     - Check if `board[r][c]` exists in `rows[r]`, `cols[c]`, or `boxes[boxIndex]`.
     - If it exists in any of the three, return `false` immediately.
     - Otherwise, insert the character into all three sets.
   - If traversal completes without conflicts, return `true`.

---

## Key Insight

- Using an array/vector of `unordered_set<char>` allows simultaneous $\mathcal{O}(1)$ row, column, and sub-box uniqueness checks in a single pass.
- Integer division partitions the $9 \times 9$ grid into a $3 \times 3$ coordinate space of blocks $(r/3, c/3)$, which translates into index $0 \dots 8$ via $(r/3) \times 3 + (c/3)$.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9); 
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                int boxIndex = (r / 3) * 3 + (c / 3);
                
                if (board[r][c] == '.') {
                    continue;
                }
                
                if (rows[r].count(board[r][c])) {
                    return false;
                } else {
                    rows[r].insert(board[r][c]);
                }
                
                if (cols[c].count(board[r][c])) {
                    return false;
                } else {
                    cols[c].insert(board[r][c]); 
                }
                
                if (boxes[boxIndex].count(board[r][c])) {
                    return false;
                } else {
                    boxes[boxIndex].insert(board[r][c]);   
                }  
            }
        }
        return true;
    }
};
```

---

## Complexity

- **Time Complexity:** $\mathcal{O}(1)$ (or $\mathcal{O}(N^2)$ where $N=9$). Fixed $81$ iterations, each operation takes $\mathcal{O}(1)$ average time.
- **Space Complexity:** $\mathcal{O}(1)$ (or $\mathcal{O}(N^2)$). We store at most $3 \times 81$ characters across all hash sets.

---

## Mistakes I Made & Learnings

1. **Sub-box Indexing Formula:**
   - Learned how integer division $(r/3, c/3)$ maps 2D grid coordinates to a 1D index: `(r / 3) * 3 + (c / 3)`.
2. **Vector of HashSets:**
   - Learned how to manage multiple independent hash sets cleanly using `vector<unordered_set<char>> rows(9)`.
3. **Return Placement:**
   - Avoid placing `return true;` inside the row loop; ensure it is returned only after the complete grid is checked.
