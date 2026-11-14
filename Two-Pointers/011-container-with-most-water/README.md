# 11. Container With Most Water

**Difficulty:** Medium  
**Topic:** Two-Pointers / Greedy  
**LeetCode Link:** [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/)

---

## Problem Statement

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the $i^{\text{th}}$ line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

**Notice:** You may not slant the container.

---

### Examples

#### Example 1:
- **Input:** `height = [1,8,6,2,5,4,8,3,7]`
- **Output:** `49`
- **Explanation:** The vertical lines are represented by array `[1,8,6,2,5,4,8,3,7]`. Max area is between index `1` (`height = 8`) and index `8` (`height = 7`):
  $$\text{Area} = \min(8, 7) \times (8 - 1) = 7 \times 7 = 49$$

#### Example 2:
- **Input:** `height = [1,1]`
- **Output:** `1`
- **Explanation:** $\min(1, 1) \times (1 - 0) = 1 \times 1 = 1$.

---

### Constraints

- $n == \text{height.length}$
- $2 \le n \le 10^5$
- $0 \le \text{height}[i] \le 10^4$

---

## My Approach

1. **Initialize Two Pointers at Extreme Ends:**
   - Place `left = 0` at the first line and `right = height.size() - 1` at the last line.
   - This provides the maximum possible container width right from the start.

2. **Calculate Area and Update Global Maximum:**
   - In each step of a `while (left < right)` loop:
     $$\text{currentArea} = (\text{right} - \text{left}) \times \min(\text{height}[\text{left}], \text{height}[\text{right}])$$
     $$\text{maxWater} = \max(\text{maxWater}, \text{currentArea})$$

3. **Greedy Pointer Movement:**
   - Water volume is bottlenecked by the shorter wall.
   - Since moving any pointer inward strictly reduces the width by 1, keeping the shorter wall could never lead to a larger area.
   - Therefore, discard the shorter wall:
     - If `height[left] < height[right]`, advance `left++`.
     - Otherwise (`height[left] >= height[right]`), advance `right--`.

---

## Key Insight

- The area is determined by $\text{width} \times \min(\text{height}[L], \text{height}[R])$.
- As pointers converge, width monotonically decreases. To find a potentially larger area with a smaller width, we must find a taller boundary. Moving the taller wall guarantees an area smaller than or equal to currentArea. Hence, we greedily discard the shorter wall.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        
        while (left < right) {
            int currentArea = (right - left) * min(height[left], height[right]);
            maxWater = max(maxWater, currentArea);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};
```

---

## Complexity

- **Time Complexity:** $\mathcal{O}(n)$
  - Both pointers converge across the array of length $n$; each element is visited at most once.
- **Space Complexity:** $\mathcal{O}(1)$
  - Constant auxiliary space using only primitive pointer and area integer variables.

---

## Mistakes I Made & Learnings

1. **Handling Equal Heights (`height[left] == height[right]`):**
   - Writing separate non-exhaustive `if (height[left] < height[right])` and `if (height[left] > height[right])` causes an infinite loop when heights are equal because neither pointer advances.
   - *Fix:* Use an `else` branch to advance `right--` (or `left++`) when heights are equal.
2. **Missing Return Statement:**
   - Remember to return `maxWater;` after the while loop finishes.
