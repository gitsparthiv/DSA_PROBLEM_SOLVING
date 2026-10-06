# 15. 3Sum

**Difficulty:** Medium  
**Topic:** Two-Pointers / Array / Sorting  
**LeetCode Link:** [15. 3Sum](https://leetcode.com/problems/3sum/)

---

## Problem Statement

Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that $i \ne j$, $i \ne k$, and $j \ne k$, and $\text{nums}[i] + \text{nums}[j] + \text{nums}[k] == 0$.

Notice that the solution set **must not contain duplicate triplets**.

---

### Examples

#### Example 1:
- **Input:** `nums = [-1, 0, 1, 2, -1, -4]`
- **Output:** `[[-1, -1, 2], [-1, 0, 1]]`
- **Explanation:** 
  - $\text{nums}[0] + \text{nums}[1] + \text{nums}[2] = (-1) + 0 + 1 = 0$.
  - $\text{nums}[1] + \text{nums}[2] + \text{nums}[4] = 0 + 1 + (-1) = 0$.
  - $\text{nums}[0] + \text{nums}[3] + \text{nums}[4] = (-1) + 2 + (-1) = 0$.
  - Distinct triplets: `[-1, 0, 1]` and `[-1, -1, 2]`.

#### Example 2:
- **Input:** `nums = [0, 1, 1]`
- **Output:** `[]`

#### Example 3:
- **Input:** `nums = [0, 0, 0]`
- **Output:** `[[0, 0, 0]]`

---

### Constraints

- $3 \le \text{nums.length} \le 3000$
- $-10^5 \le \text{nums}[i] \le 10^5$

---

## My Approach

1. **Sort the Array:**
   - Call `sort(nums.begin(), nums.end())` ($O(n \log n)$). This orders elements and clusters duplicate values together.

2. **Fix the First Element (`nums[i]`):**
   - Iterate through `nums` with index `i`.
   - Skip duplicate first elements: `if (i > 0 && nums[i] == nums[i - 1]) continue;`.
   - Target sum for the remaining pair: `complement = -nums[i]`.

3. **Two-Pointer Search on Subarray (`i + 1` to `n - 1`):**
   - `left = i + 1`, `right = nums.size() - 1`.
   - While `left < right`:
     - If `nums[left] + nums[right] == complement`:
       - Record triplet `{nums[i], nums[left], nums[right]}`.
       - Move pointers: `left++`, `right--`.
       - Skip duplicate `left` values: `while (left < right && nums[left] == nums[left - 1]) left++;`.
       - Skip duplicate `right` values: `while (left < right && nums[right] == nums[right + 1]) right--;`.
     - If `nums[left] + nums[right] < complement`: `left++` (need larger sum).
     - If `nums[left] + nums[right] > complement`: `right--` (need smaller sum).

---

## Key Insight

- Transforming $a + b + c = 0$ into $b + c = -a$ reduces a 3-element search into a sorted Two-Sum problem.
- By searching strictly to the right (`left = i + 1`), we avoid duplicate permutations.
- Explicit `while` loops skipping adjacent identical elements upon finding a match completely eliminate duplicate triplets in $O(n^2)$ time without using a heavy `std::set`.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate first numbers
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int complement = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int res = nums[left] + nums[right];
                
                if (res == complement) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    
                    // Skip duplicates for left and right
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (res < complement) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;  
    }
};
```

---

## Complexity

- **Time Complexity:** $\mathcal{O}(n^2)$
  - Sorting: $\mathcal{O}(n \log n)$
  - Outer loop ($n$) $\times$ Inner Two-Pointers ($n$) = $\mathcal{O}(n^2)$.
  - Total Time: $\mathcal{O}(n \log n + n^2) = \mathcal{O}(n^2)$.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space (ignoring the output vector `result`). `std::sort` typically takes $\mathcal{O}(\log n)$ stack space.

---

## Mistakes I Made & Learnings

1. **Why `left = i + 1` instead of `0`:**
   - Any triplet with elements before `i` was already formed when `i` was at those earlier indices. Looking only forward prevents repeated work and duplicate permutations.
2. **Handling Duplicates at 2 Levels:**
   - Level 1: Outer loop `if (i > 0 && nums[i] == nums[i - 1]) continue;`.
   - Level 2: Inside match condition, skip identical adjacent `nums[left]` and `nums[right]`.
3. **Dual Pointer Movement on Match:**
   - After a match, moving only one pointer causes wasted comparisons; moving both and fast-forwarding is optimal.
