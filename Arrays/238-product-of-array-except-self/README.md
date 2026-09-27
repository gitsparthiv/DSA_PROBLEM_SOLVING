# 238. Product of Array Except Self

**Difficulty:** Medium  
**Topic:** Arrays / Prefix & Suffix Products  
**LeetCode Link:** [238. Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)

---

## Problem Statement

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

The product of any prefix or suffix of `nums` is guaranteed to fit in a **32-bit** integer.

You must write an algorithm that runs in **$O(n)$** time and **without using the division operation**.

---

### Examples

#### Example 1:
- **Input:** `nums = [1, 2, 3, 4]`
- **Output:** `[24, 12, 8, 6]`

#### Example 2:
- **Input:** `nums = [-1, 1, 0, -3, 3]`
- **Output:** `[0, 0, 9, 0, 0]`

---

### Constraints

- $2 \le \text{nums.length} \le 10^5$
- $-30 \le \text{nums}[i] \le 30$
- The input is generated such that `answer[i]` is **guaranteed** to fit in a **32-bit** integer.

---

## My Approach

1. **Prefix Products (`pref`):**
   - Create an array `pref` of size `n` where `pref[i]` stores the product of all elements to the left of index `i`.
   - Base case: `pref[0] = 1`.
   - Transition: `pref[i] = pref[i - 1] * nums[i - 1]` for `i` from `1` to `n - 1`.

2. **Suffix Products (`suff`):**
   - Create an array `suff` of size `n` where `suff[i]` stores the product of all elements to the right of index `i`.
   - Base case: `suff[n - 1] = 1`.
   - Transition: `suff[i] = suff[i + 1] * nums[i + 1]` for `i` from `n - 2` down to `0`.

3. **Compute Result:**
   - For every index `i`, `res[i] = pref[i] * suff[i]`.

---

## Key Insight

For any index `i`, the product of all numbers except `nums[i]` is simply:
$$\text{productExceptSelf}(i) = (\text{product of all elements to the left of } i) \times (\text{product of all elements to the right of } i)$$
By precomputing the prefix and suffix products, each position can be calculated in $O(1)$ time without requiring division.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> pref(nums.size());
        vector<int> suff(nums.size());
        vector<int> res;        
        pref[0] = 1;
        suff[(nums.size() - 1)] = 1;
        for(int i = 1; i < nums.size(); i++){
            pref[i] = pref[i - 1] * nums[i - 1];
        }
        for(int i = nums.size() - 2; i >= 0; i--){
            suff[i] = suff[i + 1] * nums[i + 1];
        }
        for(int i = 0; i < nums.size(); i++){
            res.push_back(pref[i] * suff[i]);
        }
        return res;
    }
};
```

---

## Complexity

- **Time Complexity:** $O(n)$
  - Building `pref`: $O(n)$
  - Building `suff`: $O(n)$
  - Combining results: $O(n)$
  - Total time is linear with 3 passes.
- **Space Complexity:** $O(n)$
  - Extra arrays `pref` and `suff` of size $n$.

---

## Mistakes I Made
- None.

---

## What I Learned
- Breaking down a cumulative product into independent left (prefix) and right (suffix) components avoids the need for division entirely and handles zeros cleanly.

---

## Alternative Approach ($O(1)$ Extra Space)
Instead of two separate arrays for `pref` and `suff`, we can compute the prefix product directly inside the result array `res`, and maintain a running variable `suffix_prod` while traversing backwards.
