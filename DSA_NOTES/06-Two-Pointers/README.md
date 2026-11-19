# Two-Pointers Technique Handbook

---

## 1. What is the Two-Pointers Technique?

The **Two-Pointers** pattern uses two integer index variables to traverse linear structures (arrays, strings, linked lists) simultaneously.

### Common Configurations:
1. **Opposite Ends (Converging):** `left = 0`, `right = n - 1` moving toward each other (`while (left < right)`).
   - Used for: Palindromes, Two Sum in Sorted Arrays, Container with Most Water, 3Sum inner scan, Trapping Rain Water.
2. **Same Direction (Fast & Slow):** `slow = 0`, `fast = 0` moving forward at different speeds or conditions.
   - Used for: Remove duplicates in-place, sliding windows, linked list middle/cycle detection.

---

## 2. Character & String Utilities (`<cctype>`)

```cpp
#include <cctype>

char c = 'A';
bool valid = isalnum(c);   // Letter or digit
bool isLetter = isalpha(c);
bool isNum = isdigit(c);
char lower = tolower('A');  // 'a'
char upper = toupper('b');  // 'B'
```

---

## 3. Pattern 1: Converging Pointers — Valid Palindrome (LC 125)

```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (!isalnum(s[left])) { left++; continue; }
        if (!isalnum(s[right])) { right--; continue; }
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++;
        right--;
    }
    return true;
}
```
- **Complexity:** Time $\mathcal{O}(n)$, Space $\mathcal{O}(1)$.

---

## 4. Pattern 2: Two Sum II - Input Array Is Sorted (LC 167)

### Key Invariant:
Because the array is sorted in non-decreasing order:
- Moving `left++` strictly non-decreases the sum.
- Moving `right--` strictly non-increases the sum.
- This monotonicity eliminates the need for any hash map storage.

```cpp
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
        int currentsum = numbers[left] + numbers[right];
        if (currentsum == target) {
            return {left + 1, right + 1}; // 1-based indexing
        } else if (currentsum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {-1, -1};
}
```
- **Complexity:** Time $\mathcal{O}(n)$, Space $\mathcal{O}(1)$.

---

## 5. Pattern 3: 3Sum / Triplets with Zero Sum (LC 15)

### Problem:
Find all unique triplets `[a, b, c]` such that `a + b + c == 0` without duplicates in $\mathcal{O}(n^2)$ time.

### The 3-Step Mental Framework:
1. **Sort First:** `sort(nums.begin(), nums.end())` (Enables two-pointer search and clusters identical values together).
2. **Fix `nums[i]`:** 
   - Skip duplicate `i` values: `if (i > 0 && nums[i] == nums[i - 1]) continue;`
   - Target sum for the remaining pair: `complement = -nums[i]`.
3. **Two-Pointer Scan on Subarray (`left = i + 1`, `right = n - 1`):**
   - If `nums[left] + nums[right] < complement` $\rightarrow$ `left++`
   - If `nums[left] + nums[right] > complement` $\rightarrow$ `right--`
   - If `nums[left] + nums[right] == complement`:
     - Add `{nums[i], nums[left], nums[right]}` to result.
     - Advance both `left++` and `right--`.
     - Fast-forward duplicate `left` and `right` elements without using extra hash sets:
       ```cpp
       while (left < right && nums[left] == nums[left - 1]) left++;
       while (left < right && nums[right] == nums[right + 1]) right--;
       ```

### Template Code:
```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        int complement = -nums[i];
        int left = i + 1, right = nums.size() - 1;
        
        while (left < right) {
            int res = nums[left] + nums[right];
            if (res == complement) {
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            } else if (res < complement) {
                left++;
            } else {
                right--;
            }
        }
    }
    return result;
}
```
- **Complexity:** Time $\mathcal{O}(n^2)$, Space $\mathcal{O}(1)$ auxiliary.

---

## 6. Pattern 4: Container With Most Water (LC 11)

### The Greedy Choice:
- Place pointers at outer ends (`left = 0`, `right = n - 1`) for maximum initial width.
- In each step:
  $$\text{currentArea} = (\text{right} - \text{left}) \times \min(\text{height}[left], \text{height}[right])$$
  $$\text{maxWater} = \max(\text{maxWater}, \text{currentArea})$$
- **Why discard the shorter wall?**
  - Moving either pointer inward strictly reduces width by 1.
  - Keeping the shorter wall cannot increase the water height (still limited by that shorter wall), so area can never increase.
  - Discarding the shorter wall is the ONLY way to potentially find a taller wall and achieve a larger area.

```cpp
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;
    
    while (left < right) {
        int currentArea = (right - left) * min(height[left], height[right]);
        maxWater = max(maxWater, currentArea);
        
        if (height[left] < height[right]) {
            left++;
        } else {
            right--; // Handles both > and ==
        }
    }
    return maxWater;
}
```
- **Complexity:** Time $\mathcal{O}(n)$, Space $\mathcal{O}(1)$.

---

## 7. Pattern 5: Trapping Rain Water (LC 42)

### Dynamic Bottleneck Tracking:
- Water above any bar $i$ is strictly governed by:
  $$\text{Water at } i = \max(0, \min(\text{maxLeft}, \text{maxRight}) - \text{height}[i])$$
- Outer bars `0` and `n - 1` can never hold water (act as initial boundaries).
- At any point, compare `maxLeft` and `maxRight`:
  - If `maxLeft <= maxRight`, the left side is the bottleneck! Any unvisited inner bars are $\ge \text{maxRight} \ge \text{maxLeft}$, meaning the water level over the left bar is strictly dictated by `maxLeft`.
  - Advance `left++`: if `height[left] > maxLeft`, update `maxLeft`; otherwise, add `maxLeft - height[left]` to `totalwater`.
  - Symmetrically for the right side when `maxRight < maxLeft`.
- This eliminates $\mathcal{O}(n)$ prefix/suffix arrays for optimal **$\mathcal{O}(1)$ space** and **0 ms (100% beats)** runtime.

```cpp
int trap(vector<int>& height) {
    int totalwater = 0;
    int left = 0, right = height.size() - 1;
    int maxLeft = height[left], maxRight = height[right];
    
    while (left < right) {
        if (maxLeft <= maxRight) {
            left++;
            if (height[left] > maxLeft) {
                maxLeft = height[left];
            } else {
                totalwater += maxLeft - height[left];
            }
        } else {
            right--;
            if (height[right] > maxRight) {
                maxRight = height[right];
            } else {
                totalwater += maxRight - height[right];
            }
        }
    }
    return totalwater;
}
```
- **Complexity:** Time $\mathcal{O}(n)$, Space $\mathcal{O}(1)$.
