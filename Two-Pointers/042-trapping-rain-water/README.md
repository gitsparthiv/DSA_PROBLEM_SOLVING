# 42. Trapping Rain Water

**Difficulty:** Hard  
**Topic:** Two-Pointers / Array / Dynamic Programming  
**LeetCode Link:** [42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)  
**Performance:** **0 ms (Beats 100.00%)** | **25.99 MB (Beats 74.46%)**

---

## Problem Statement

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

---

### Examples

#### Example 1:
- **Input:** `height = [0,1,0,2,1,0,1,3,2,1,2,1]`
- **Output:** `6`
- **Explanation:** The above elevation map is represented by array `[0,1,0,2,1,0,1,3,2,1,2,1]`. In this case, 6 units of rain water are trapped.

#### Example 2:
- **Input:** `height = [4,2,0,3,2,5]`
- **Output:** `9`

---

### Constraints

- `n == height.length`
- $1 \le n \le 2 \times 10^4$
- $0 \le \text{height}[i] \le 10^5$

---

## My Approach

1. **Outer Boundary Realization:**
   - The bars at the extreme ends (`index 0` and `index n - 1`) can never trap water on top of themselves because there are no outer walls to hold water; they act strictly as initial boundary walls.
   - Initialize `left = 0`, `right = height.size() - 1`, `maxLeft = height[left]`, and `maxRight = height[right]`.

2. **Dynamic Bottleneck Selection (`while (left < right)`):**
   - At each step, compare the current boundary heights:
     - **If `maxLeft <= maxRight`:** The left boundary is the bottleneck. Any unvisited inner bars cannot lower the water level below `maxLeft`. Advance `left++`:
       - If `height[left] > maxLeft`, update `maxLeft = height[left]` (a new peak forms, trapping no water above itself).
       - Otherwise, calculate trapped water: `min(maxLeft, maxRight) - height[left]` and add to `totalwater`.
     - **If `maxRight < maxLeft`:** The right boundary is the bottleneck. Advance `right--`:
       - If `height[right] > maxRight`, update `maxRight = height[right]`.
       - Otherwise, calculate trapped water: `min(maxLeft, maxRight) - height[right]` and add to `totalwater`.

3. **Return Cumulative Water:**
   - Return `totalwater` after the pointers meet.

---

## Key Insight

- The water trapped directly above any bar `i` is strictly determined by:
  $$\text{Water at } i = \max(0, \min(\text{maxLeft}, \text{maxRight}) - \text{height}[i])$$
- In a naive or dynamic programming approach, computing prefix and suffix max arrays requires $\mathcal{O}(n)$ auxiliary space.
- By using **Two Pointers converging from both ends**, we only ever need to know the bottleneck of the two boundaries. If `maxLeft <= maxRight`, we are 100% guaranteed that the right boundary is tall enough, so the left bar's water level is dictated strictly by `maxLeft`. 
- This collapses the space complexity to $\mathcal{O}(1)$ while traversing the array in a single $\mathcal{O}(n)$ pass, achieving a **0 ms (100% beats)** runtime.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int totalwater = 0;
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = height[left];
        int maxRight = height[right];
        while(left < right){
            int currentwater = 0;
            if(maxLeft <= maxRight){
                left++;
                if(height[left] > maxLeft){
                    maxLeft = height[left];
                }
                else{
                    currentwater = min(maxLeft, maxRight) - height[left];
                }
            }
            else if(maxRight < maxLeft){
                right--;
                if(height[right] > maxRight){
                    maxRight = height[right];
                }
                else{
                    currentwater = min(maxLeft, maxRight) - height[right];
                }
            }
            if(currentwater > 0){
                totalwater = totalwater + currentwater;
            }
        }
        return totalwater;
    }
};
```

---

## Complexity

- **Time Complexity:** $\mathcal{O}(n)$
  - Each element in `height` is visited at most once by either `left` or `right` as they converge.
- **Space Complexity:** $\mathcal{O}(1)$
  - No auxiliary arrays or stacks used; only integer pointer and max tracking variables.

---

## Mistakes I Made & Learnings

1. **Persisting Wall State Across Iterations:**
   - Initially declared `maxLeft` and `maxRight` inside the loop re-assigning them to `height[left]` / `height[right]`, which wiped out the memory of previous peaks.
   - *Fix:* Declare `maxLeft` and `maxRight` outside the while loop and update them only when a strictly higher peak is encountered.
2. **Exhaustive Condition Handling:**
   - Handled `<` and `>` separately without covering equality (`==`), which could cause an infinite loop where neither pointer advances.
   - *Fix:* Use `<=` on one branch and `<` (or plain `else`) on the other to guarantee pointer movement every iteration.
3. **Index Mirroring in Symmetric Branches:**
   - In the right-advancing branch, accidentally subtracted `height[left]` instead of `height[right]`.
   - *Fix:* Carefully audited the symmetrical branch to ensure `height[right]` was subtracted.
