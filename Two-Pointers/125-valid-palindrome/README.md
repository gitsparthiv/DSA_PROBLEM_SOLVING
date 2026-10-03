# 125. Valid Palindrome

**Difficulty:** Easy  
**Topic:** Two-Pointers / String  
**LeetCode Link:** [125. Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)

---

## Problem Statement

A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` if it is a palindrome, or `false` otherwise.

---

### Examples

#### Example 1:
- **Input:** `s = "A man, a plan, a canal: Panama"`
- **Output:** `true`
- **Explanation:** `"amanaplanacanalpanama"` is a palindrome.

#### Example 2:
- **Input:** `s = "race a car"`
- **Output:** `false`
- **Explanation:** `"raceacar"` is not a palindrome.

#### Example 3:
- **Input:** `s = " "`
- **Output:** `true`
- **Explanation:** `s` is an empty string `""` after removing non-alphanumeric characters. Since an empty string reads the same forward and backward, it is a palindrome.

---

### Constraints

- $1 \le \text{s.length} \le 2 \times 10^5$
- `s` consists only of printable ASCII characters.

---

## My Approach

1. **Two Pointers Setup:**
   - Initialize `left = 0` (pointing to the start) and `right = s.size() - 1` (pointing to the end).
   - Use a `while (left < right)` loop to converge both pointers toward each other.

2. **Skipping Non-Alphanumeric Characters:**
   - If `!isalnum(s[left])`, increment `left++` and `continue`.
   - If `!isalnum(s[right])`, decrement `right--` and `continue`.

3. **Comparison & Case Insensitivity:**
   - Compare `tolower(s[left])` and `tolower(s[right])`.
   - If they match: advance both pointers (`left++`, `right--`).
   - If they do NOT match: immediately `return false`.

4. **Termination:**
   - If the pointers meet or cross without any character mismatch, `return true`.

---

## Key Insight

- Using two converging pointers allows in-place checking without allocating any extra string or auxiliary memory.
- `isalnum()` and `tolower()` allow seamless character filtration and case-insensitive comparison on the fly.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
                continue;
            }
            if (!isalnum(s[right])) {
                right--;
                continue;
            }
            if (tolower(s[left]) == tolower(s[right])) {
                left++;
                right--;
                continue;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }   
        }
        return true;
    }
};
```

---

## Complexity

- **Time Complexity:** $\mathcal{O}(n)$
  - Each pointer traverses at most $n$ characters once. (Beats 100% on LeetCode)
- **Space Complexity:** $\mathcal{O}(1)$
  - In-place evaluation with two integer pointer variables; zero extra memory allocated. (Beats 93% on LeetCode)

---

## What I Learned
- Two-pointer technique for in-place string symmetry checking.
- Using built-in `<cctype>` functions (`isalnum()`, `tolower()`) to filter and normalize input directly.
