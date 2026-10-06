# Time & Space Complexity Analysis

---

## 1. How to Read LeetCode Constraints (Predict Expected Complexity)

In competitive programming and LeetCode, an execution environment allows roughly **$10^7$ to $10^8$ operations per second** before throwing **Time Limit Exceeded (TLE)**.

Use the table below to immediately know what time complexity the problem setter expects based on $n$ (input size):

| Input Size ($n$) | Expected Optimal Complexity | Feasible Algorithm Categories |
| :--- | :--- | :--- |
| **$n \le 10 \sim 12$** | $\mathcal{O}(n!)$ | Permutations, Travelling Salesman, Exhaustive Search |
| **$n \le 20 \sim 25$** | $\mathcal{O}(2^n)$ or $\mathcal{O}(n \cdot 2^n)$ | Subsets generation, Backtracking, Bitmask DP |
| **$n \le 100 \sim 500$** | $\mathcal{O}(n^3)$ | 3 nested loops, Floyd-Warshall (all-pairs shortest path), Matrix multiplication |
| **$n \le 1000 \sim 3000$** | $\mathcal{O}(n^2)$ | 2 nested loops, Two-Pointers inside a loop (e.g. **3Sum**), Bubble/Insertion Sort, 2D DP |
| **$n \le 10^5 \sim 10^6$** | $\mathcal{O}(n \log n)$ or $\mathcal{O}(n)$ | Sorting (`std::sort`), Divide and Conquer, Trees, Heaps, Hashing, Single pass |
| **$n \le 10^9$** | $\mathcal{O}(\log n)$ or $\mathcal{O}(1)$ | Binary Search, Math / Number Theory, Bitwise operations, GCD |

---

## 2. How to Read Space Constraints

| Memory Limit | Bytes Available | Maximum Vector / Array Size |
| :--- | :--- | :--- |
| **Standard 256 MB** | $\approx 2.5 \times 10^8$ bytes | $\approx 6 \times 10^7$ `int` elements (since `sizeof(int) = 4` bytes) |
| **Follow-up: $\mathcal{O}(1)$ Extra Space** | A few variables | Only integer pointers / counters; no dynamically growing vectors, sets, or recursion trees. |

> **Crucial Rule:** The return container (e.g., `vector<vector<int>> res` in 3Sum) does **not** count towards auxiliary space complexity unless requested by the interviewer.

---

## 3. Big-O Complexity Hierarchy

$$\mathcal{O}(1) < \mathcal{O}(\log n) < \mathcal{O}(n) < \mathcal{O}(n \log n) < \mathcal{O}(n^2) < \mathcal{O}(n^3) < \mathcal{O}(2^n) < \mathcal{O}(n!)$$

| Complexity | Meaning / Growth | Typical Example |
| :--- | :--- | :--- |
| $\mathcal{O}(1)$ | Constant work | Access `arr[i]`, push to stack |
| $\mathcal{O}(\log n)$ | Halves search space repeatedly | Binary search |
| $\mathcal{O}(n)$ | Single or multiple sequential passes | Linear scan, prefix array |
| $\mathcal{O}(n \log n)$ | Linear work per logarithmic level | Merge sort, `std::sort()` |
| $\mathcal{O}(n^2)$ | Every element compared with all others | Nested loops over $n$ |
| $\mathcal{O}(2^n)$ | Choices double at each step | Subsets / Combinations |

---

## 4. Two Essential Rules of Big-O

### Rule 1: Drop Constant Factors
$$\mathcal{O}(3n) \rightarrow \mathcal{O}(n)$$
$$\mathcal{O}(n + n + n) = \mathcal{O}(3n) \rightarrow \mathcal{O}(n)$$
> **Crucial insight:** Having multiple sequential loops is **still $\mathcal{O}(n)$**, not $\mathcal{O}(n^2)$.

### Rule 2: Drop Lower-Order Terms
$$\mathcal{O}(n^2 + n + 10) \rightarrow \mathcal{O}(n^2)$$
$$\mathcal{O}(n + \log n) \rightarrow \mathcal{O}(n)$$
Keep only the dominant term as $n \to \infty$.

---

## 5. Sequential vs. Nested Loops

```cpp
// Sequential Loops -> O(n) + O(n) = O(2n) = O(n)
for (int i = 0; i < n; i++) { /* work */ }
for (int i = 0; i < n; i++) { /* work */ }

// Nested Loops -> O(n * n) = O(n^2)
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        /* work */
    }
}
```

---

## 6. Code Analysis Checklist
1. What represents $n$? Check the constraint table to set the target complexity.
2. Does the search space get halved ($\mathcal{O}(\log n)$)?
3. Are the loops sequential ($\mathcal{O}(n)$) or nested ($\mathcal{O}(n^2)$)?
4. Are you calling `std::sort` ($\mathcal{O}(n \log n)$)?
5. What auxiliary arrays/hash tables are created ($\text{Space Complexity}$)?
