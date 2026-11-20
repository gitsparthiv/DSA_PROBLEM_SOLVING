# 49. Group Anagrams

**Difficulty:** Medium  
**Topic:** Arrays & Hashing / Sorting / String  
**LeetCode Link:** [49. Group Anagrams](https://leetcode.com/problems/group-anagrams/)  
**Performance:** **20 ms (Beats 43.77%)** | **26.30 MB (Beats 30.15%)**

---

## Problem Statement

Given an array of strings `strs`, group the **anagrams** together. You can return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

---

### Examples

#### Example 1:
- **Input:** `strs = ["eat","tea","tan","ate","nat","bat"]`
- **Output:** `[["bat"],["nat","tan"],["ate","eat","tea"]]`

#### Example 2:
- **Input:** `strs = [""]`
- **Output:** `[[""]]`

#### Example 3:
- **Input:** `strs = ["a"]`
- **Output:** `[["a"]]`

---

### Constraints

- $1 \le \text{strs.length} \le 10^4$
- $0 \le \text{strs}[i]\text{.length} \le 100$
- `strs[i]` consists of lowercase English letters.

---

## My Approach

1. **Identify the Invariant (Canonical Key):**
   - Two strings are anagrams if and only if their sorted versions are identical (e.g. `"eat"` $\rightarrow$ `"aet"`, `"tea"` $\rightarrow$ `"aet"`).
   - Use a hash map `unordered_map<string, vector<string>> map` where each key is the sorted canonical string, and the value is a list of original words sharing that key.

2. **Iterate and Bucket:**
   - Loop through `strs`:
     - Make a local copy of each string `strs[i]`.
     - Sort the copy using `sort(str.begin(), str.end())`.
     - Push the original word `strs[i]` into `map[str]`. C++ automatically creates the bucket if the key does not exist yet.

3. **Extract Groups:**
   - Iterate through `map` using `for (auto& pair : map)` and append each group (`pair.second`) to `result`.
   - Return `result`.

---

## Key Insight

- Rather than performing pairwise $\mathcal{O}(N^2)$ comparisons between strings, sorting each string into a canonical signature allows $\mathcal{O}(1)$ average hash map lookup and grouping.
- Preserving a separate copy of the string to sort avoids modifying the original words in place, allowing clean collection into the final output.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> result;
        
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            map[str].push_back(strs[i]);
        }
        
        for (auto& pair : map) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};
```

---

## Complexity

- **Time Complexity:** $\mathcal{O}(N \cdot K \log K)$
  - Let $N$ be the number of strings in `strs`, and $K$ be the maximum length of a string.
  - Sorting each string takes $\mathcal{O}(K \log K)$ time.
  - Doing this for all $N$ strings takes $\mathcal{O}(N \cdot K \log K)$.
  - Collecting values from the map takes $\mathcal{O}(N \cdot K)$ time.
  - Overall Time: $\mathcal{O}(N \cdot K \log K)$.
- **Space Complexity:** $\mathcal{O}(N \cdot K)$
  - The hash map stores all $N$ strings of length up to $K$, plus the unique sorted keys.

---

## Mistakes I Made & Learnings

1. **In-place Mutation vs Copying:**
   - Sorting `strs[i]` directly in place would overwrite the original word with its sorted letters (`"eat"` becomes `"aet"`).
   - *Fix:* Create a separate copy `string str = strs[i]` to sort and use as the map key while keeping the original string intact.
2. **Hash Map Automatic Insertion:**
   - C++'s `operator[]` on `unordered_map` default-constructs an empty vector if the key is missing, eliminating the need for boilerplate `find()` checks before appending.
