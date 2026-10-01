# 128. Longest Consecutive Sequence

**Difficulty:** Medium  
**Topic:** Hashing / HashSet  
**LeetCode Link:** [128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)

---

## Problem Statement

Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in **$O(n)$** time.

---

### Examples

#### Example 1:
- **Input:** `nums = [100, 4, 200, 1, 3, 2]`
- **Output:** `4`
- **Explanation:** The longest consecutive elements sequence is `[1, 2, 3, 4]`. Therefore its length is 4.

#### Example 2:
- **Input:** `nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]`
- **Output:** `9`

#### Example 3:
- **Input:** `nums = [1, 0, 1, 2]`
- **Output:** `3`

---

### Constraints

- $0 \le \text{nums.length} \le 10^5$
- $-10^9 \le \text{nums}[i] \le 10^9$

---

## My Approach

1. **Insert into `unordered_set`:**
   - Convert `nums` into an `unordered_set<int>` in $O(n)$ time using range construction `(nums.begin(), nums.end())`.
   - This eliminates all duplicates and enables $O(1)$ average-time lookups.

2. **Identify Sequence Starters:**
   - Iterate over the unique elements in `numSet` using a range-based `for (int num : numSet)` loop.
   - A number `num` is the **start** of a sequence if and only if `num - 1` is **NOT** present in `numSet` (`numSet.find(num - 1) == numSet.end()`).

3. **Count the Streak:**
   - For every sequence starter, initialize `currentNum = num` and `currentStreak = 1`.
   - Use a `while` loop to check if `currentNum + 1` exists in `numSet`. If found, increment `currentNum` and `currentStreak`.
   - Update `maxstreak = max(currentStreak, maxstreak)`.

---

## Key Insight

- Only sequence **starters** initiate streak expansion. Non-starters (numbers with `num - 1` in the set) are immediately skipped in $O(1)$ time.
- Because each element is traversed in the `while` loop at most once across the entire execution, the total number of operations remains strictly linear.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxstreak = 0;
        
        for (int num : numSet) {
            // Check if 'num' is the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;
                
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }
                
                maxstreak = max(currentStreak, maxstreak);
            }
        }
        return maxstreak;
    }
};
```

---

## Complexity

- **Time Complexity:** $O(n)$
  - Constructing `numSet`: $O(n)$
  - Outer loop visits each unique element: $O(u)$ where $u \le n$.
  - Total `while` loop iterations across all starters: $O(u) \le O(n)$.
  - Total Time: $O(n) + O(n) = O(n)$.
- **Space Complexity:** $O(n)$
  - `unordered_set` stores at most $n$ elements.

---

## Mistakes I Made & Learnings

1. **Iterating over `nums` vs `numSet` (TLE trap):**
   - Iterating over `nums` causes repeated nested loop expansions on arrays with large numbers of duplicates (e.g. 100,000 zeros), causing Time Limit Exceeded ($O(n^2)$ worst case).
   - *Fix:* Always iterate directly over the unique elements in `numSet`.
2. **Starter Condition Confusion:**
   - Confused `find() != end()` (found) with `find() == end()` (not found).
   - *Rule:* Starter exists when `numSet.find(num - 1) == numSet.end()`.
3. **Loop Construction:**
   - Learned how and when to use Range-based `for` loops (`for (int num : numSet)`).
