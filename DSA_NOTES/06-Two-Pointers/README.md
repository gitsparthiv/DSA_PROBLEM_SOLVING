# Two-Pointers Technique Handbook

---

## 1. What is the Two-Pointers Technique?

The **Two-Pointers** pattern uses two integer index variables (pointers) to traverse a linear data structure (array, string, or linked list) simultaneously.

### Common Configurations:
1. **Opposite Ends (Converging):** `left = 0`, `right = n - 1` moving toward each other (`while (left < right)`).
   - Used for: Palindromes, Two Sum in Sorted Arrays, Container with Most Water.
2. **Same Direction (Fast & Slow):** `slow = 0`, `fast = 0` moving forward at different speeds or conditions.
   - Used for: Remove duplicates in-place, linked list middle/cycle detection.

---

## 2. Character & String Utilities (`<cctype>`)

When processing strings for palindromes, anagrams, or alphanumeric validation:

```cpp
#include <cctype> // Or <bits/stdc++.h>

char c = 'A';

// 1. Check if character is letter or digit ('a'-'z', 'A'-'Z', '0'-'9')
bool valid = isalnum(c);  // true

// 2. Check letter only
bool isLetter = isalpha(c);

// 3. Check digit only
bool isNum = isdigit(c);

// 4. Convert case
char lower = tolower('A'); // 'a'
char upper = toupper('b'); // 'B'
```

---

## 3. Converging Pointers Pattern: Valid Palindrome (LC 125)

- **Goal:** Validate palindrome in-place in $\mathcal{O}(n)$ time and $\mathcal{O}(1)$ auxiliary space.

```cpp
bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;
    
    while (left < right) {
        // Skip non-alphanumeric characters
        if (!isalnum(s[left])) {
            left++;
            continue;
        }
        if (!isalnum(s[right])) {
            right--;
            continue;
        }
        
        // Case-insensitive comparison
        if (tolower(s[left]) != tolower(s[right])) {
            return false; // Mismatch found
        }
        
        // Match found -> advance both
        left++;
        right--;
    }
    return true;
}
```

### Key Takeaways:
- Condition `while (left < right)` ensures clean termination for both odd- and even-length strings.
- Using `continue` after pointer movement skips invalid characters without requiring extra nested loops.
- Avoids allocating a separate filtered string, achieving **$\mathcal{O}(1)$ space**.
