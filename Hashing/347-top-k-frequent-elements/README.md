# 347. Top K Frequent Elements

**Difficulty:** Medium  
**Topic:** Arrays & Hashing / Bucket Sort / Heap  
**LeetCode Link:** [347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)  
**Performance:** **4 ms (Beats 31.74%)** | **19.95 MB (Beats 16.99%)**

---

## Problem Statement

Given an integer array `nums` and an integer `k`, return the `k` **most frequent elements**. You may return the answer in **any order**.

---

### Examples

#### Example 1:
- **Input:** `nums = [1,1,1,2,2,3], k = 2`
- **Output:** `[1,2]`

#### Example 2:
- **Input:** `nums = [1], k = 1`
- **Output:** `[1]`

---

### Constraints

- $1 \le \text{nums.length} \le 10^5$
- $-10^4 \le \text{nums}[i] \le 10^4$
- `k` is in the range `[1, the number of unique elements in the array]`.
- It is **guaranteed** that the answer is unique.

**Follow-up:** Your algorithm's time complexity must be better than $\mathcal{O}(n \log n)$, where $n$ is the array's size.

---

## My Approach (Bucket Sort - O(N) Linear Time)

1. **Phase 1: Frequency Counting:**
   - Use an `unordered_map<int, int> count` to count how many times each number appears in `nums` (`number -> frequency`).

2. **Phase 2: Bounded Frequency Buckets:**
   - In an array of size $N$, no element can appear more than $N$ times. The frequencies are strictly bounded integers between $1$ and $N$.
   - Create a 2D dynamic vector `vector<vector<int>> buckets(nums.size() + 1);` where the **index** represents the frequency ($0$ to $N$), and each slot holds a list of numbers sharing that frequency.
   - Iterate through `count` and push each number `pair.first` into `buckets[pair.second]`.

3. **Phase 3: Reverse Extraction:**
   - Since the highest frequencies sit at the end of the array, walk backwards from `i = nums.size()` down to `1`.
   - For each number in `buckets[i]`, append it to `result`.
   - Stop and return as soon as `result.size() == k`.

---

## Key Insight

- Standard comparison sorting by frequency takes $\mathcal{O}(N \log N)$.
- Because frequencies are **strictly bounded by the array length $N$**, we can exploit **Bucket Sort**:
  - The array index acts as the sorted frequency key.
  - No comparison sorting is needed, reducing the entire time complexity from $\mathcal{O}(N \log N)$ to strictly **$\mathcal{O}(N)$ linear time**.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> buckets(nums.size() + 1); 
        
        // 1. Count frequencies
        for (int num : nums) {
            count[num]++;
        }
        
        // 2. Group numbers by frequency index
        for (auto& pair : count) {
            buckets[pair.second].push_back(pair.first);
        }
        
        // 3. Extract top k numbers from highest frequency down to 1
        vector<int> result;
        for (int i = nums.size(); i >= 1; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        
        return result;
    }
};
```

---

## Complexity

- **Time Complexity:** $\mathcal{O}(N)$
  - Counting frequencies takes $\mathcal{O}(N)$.
  - Populating the buckets takes $\mathcal{O}(M)$ where $M \le N$ is unique elements.
  - Traversing the buckets backwards takes at most $\mathcal{O}(N)$ operations total (the inner loop only runs once for each unique number).
  - Overall Time: $\mathcal{O}(N)$ strictly linear time.
- **Space Complexity:** $\mathcal{O}(N)$
  - Hash map holds at most $N$ unique entries.
  - `buckets` array of vectors holds at most $N$ numbers across all buckets combined.
  - Overall Space: $\mathcal{O}(N)$.

---

## Mistakes I Made & Learnings

1. **Pre-allocated Zeros vs. Empty Vector:**
   - Writing `vector<int> result(k);` pre-allocates $k$ zeros in memory (`[0, 0]`), causing subsequent `.push_back(num)` calls to append after the zeros (`[0, 0, 1, 2]`) and making `result.size() == k` fail.
   - *Fix:* Always initialize an empty vector `vector<int> result;` when building output via `.push_back()`.
2. **Bucket Sizing Bounds:**
   - An array of size $N$ can have a frequency of $N$. To safely access index $N$, the outer vector must be sized to `N + 1` (`vector<vector<int>> buckets(nums.size() + 1)`).
3. **2D Vector Semantics:**
   - `vector<vector<int>>` is a dynamic list of lists, where each bucket `buckets[freq]` independently grows via `.push_back(num)`.
