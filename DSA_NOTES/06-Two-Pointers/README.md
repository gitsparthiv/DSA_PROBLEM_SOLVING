# Two-Pointers Technique Handbook

---

## 1. What is the Two-Pointers Technique?

The **Two-Pointers** pattern uses two integer index variables to traverse linear structures (arrays, strings, linked lists) simultaneously.

### Common Configurations:
1. **Opposite Ends (Converging):** `left = 0`, `right = n - 1` moving toward each other (`while (left < right)`).
   - Used for: Palindromes, Two Sum in Sorted Arrays, Container with Most Water, 3Sum inner scan.
2. **Same Direction (Fast & Slow):** `slow = 0`, `fast = 0` moving forward at different speeds or conditions.
   - Used for: Remove duplicates in-place, linked list middle/cycle detection.

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

---

## 4. Pattern 2: 3Sum / Triplets with Zero Sum (LC 15)

### Problem:
Find all unique triplets `[a, b, c]` such that `a + b + c == 0` in $\mathcal{O}(n^2)$ time and without duplicate triplets.

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
     - Fast-forward duplicate `left` and `right` elements:
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
        int left = i + 1;
        int right = nums.size() - 1;
        
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

## 5. Pattern 3: Container With Most Water (LC 11)

### Problem:
Find two vertical lines from an array `height` such that they form a container holding the maximum water.

### Mental Model & The Greedy Choice:
- Start with pointers at opposite ends (`left = 0`, `right = n - 1`) for maximum initial width.
- In each step:
  $$\text{currentArea} = (\text{right} - \text{left}) \times \min(\text{height}[left], \text{height}[right])$$
  $$\text{maxWater} = \max(\text{maxWater}, \text{currentArea})$$
- **Why discard the shorter wall?**
  - Moving either pointer inward reduces width by 1.
  - Moving the taller wall cannot increase the water height (still limited by the existing shorter wall), making a larger area mathematically impossible.
  - Moving the shorter wall is the ONLY way to potentially find a taller wall and achieve a larger area.

### Template Code:
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
