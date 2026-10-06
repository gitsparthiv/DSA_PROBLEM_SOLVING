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
