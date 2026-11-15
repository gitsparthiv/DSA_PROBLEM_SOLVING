# 167. Two Sum II - Input Array Is Sorted

**Difficulty:** Medium  
**Topic:** Two-Pointers / Array  
**LeetCode Link:** [167. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

---

## Problem Statement

Given a **1-indexed** array of integers `numbers` that is already **sorted in non-decreasing order**, find two numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index1]` and `numbers[index2]` where $1 \le \text{index1} < \text{index2} \le \text{numbers.length}$.

Return the indices of the two numbers, `index1` and `index2`, **added by one** as an integer array `[index1, index2]` of length 2.

The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.

Your solution must use only **$\mathcal{O}(1)$ extra space**.

---

### Examples

#### Example 1:
- **Input:** `numbers = [2,7,11,15], target = 9`
- **Output:** `[1,2]`
- **Explanation:** The sum of 2 and 7 is 9. Therefore, `index1 = 1`, `index2 = 2`. We return `[1, 2]`.

#### Example 2:
- **Input:** `numbers = [2,3,4], target = 6`
- **Output:** `[1,3]`
- **Explanation:** The sum of 2 and 4 is 6. Therefore `index1 = 1`, `index2 = 3`. We return `[1, 3]`.

#### Example 3:
- **Input:** `numbers = [-1,0], target = -1`
- **Output:** `[1,2]`
- **Explanation:** The sum of -1 and 0 is -1. Therefore `index1 = 1`, `index2 = 2`. We return `[1, 2]`.

---

### Constraints

- $2 \le \text{numbers.length} \le 3 \times 10^4$
- $-1000 \le \text{numbers}[i] \le 1000$
- `numbers` is sorted in **non-decreasing order**.
- $-1000 \le \text{target} \le 1000$
- The tests are generated such that there is **exactly one solution**.

---

## My Approach

1. **Initialize Converging Two Pointers:**
   - Initialize `left = 0` at the first element and `right = numbers.size() - 1` at the last element.
2. **Evaluate Current Sum:**
   - In each step of a `while (left < right)` loop, compute `currentsum = numbers[left] + numbers[right]`.
3. **Adjust Pointers Based on Target Comparison:**
   - If `currentsum == target`: Return the 1-based indices immediately `{left + 1, right + 1}`.
   - If `currentsum < target`: The sum is too small. Because the array is sorted, increment `left++` to explore larger values.
   - If `currentsum > target`: The sum is too large. Decrement `right--` to explore smaller values.
4. **Fallback:**
   - Return `{left + 1, right + 1}` after the loop as a fallback (though the problem guarantees exactly one solution).

---

## Key Insight

- Because the array is sorted in non-decreasing order:
  - Moving the `left` pointer to the right strictly non-decreases the sum.
  - Moving the `right` pointer to the left strictly non-increases the sum.
- This monotonicity eliminates the need for $\mathcal{O}(n^2)$ pairwise checking or $\mathcal{O}(n)$ hash map storage, allowing optimal $\mathcal{O}(n)$ time with $\mathcal{O}(1)$ auxiliary space.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right){
            int currentsum = numbers[left] + numbers[right]; 
            if(currentsum == target){
                return {left + 1, right + 1};
            }
            if(currentsum < target){
                left++;
            }
            else{
                right--;
            }
        }
        return {left + 1, right + 1};
    }
};
```

---

## Complexity

- **Time Complexity:** $\mathcal{O}(n)$
  - In each iteration, at least one pointer moves inward. At most $n$ iterations occur before the pair is found.
- **Space Complexity:** $\mathcal{O}(1)$
  - Only uses two integer pointers (`left` and `right`) and a sum variable, strictly adhering to the $\mathcal{O}(1)$ auxiliary space constraint.

---

## Mistakes I Made & Learnings

1. **Missing Equality Return Inside the Loop:**
   - Initially handled only `if (currentsum < target)` and `else`, which treated `currentsum == target` as greater than target (`right--`), bypassing the match.
   - *Fix:* Explicitly check `if (currentsum == target)` to return immediately when the match is found.
2. **C++ Initializer Syntax:**
   - Used Python/JS style `[left + 1, right + 1]` instead of C++ vector list initialization `{left + 1, right + 1}`.
3. **1-Based Indexing:**
   - Remembered to add `+ 1` to both `left` and `right` indices to satisfy the 1-indexed return specification.
