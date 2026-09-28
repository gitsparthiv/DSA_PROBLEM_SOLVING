# Time & Space Complexity Analysis

---

## 1. What is Time Complexity?

Time complexity describes how the amount of work performed scales as input size $n$ grows.
> **Core Idea:** We measure growth rate of operations, not physical seconds.

---

## 2. Big-O Complexity Hierarchy

$$\mathcal{O}(1) < \mathcal{O}(\log n) < \mathcal{O}(n) < \mathcal{O}(n \log n) < \mathcal{O}(n^2) < \mathcal{O}(n^3) < \mathcal{O}(2^n) < \mathcal{O}(n!)$$

| Complexity | Meaning / Growth | Typical Example | LeetCode Constraint Feasibility |
| :--- | :--- | :--- | :--- |
| $\mathcal{O}(1)$ | Constant work | Access `arr[i]`, push to stack | Any $n$ |
| $\mathcal{O}(\log n)$ | Halves search space repeatedly | Binary search | $n \le 10^9$ |
| $\mathcal{O}(n)$ | Single or multiple sequential passes | Linear scan, prefix array | $n \le 10^7$ |
| $\mathcal{O}(n \log n)$ | Linear work per logarithmic level | Merge sort, `std::sort()` | $n \le 10^5 \sim 10^6$ |
| $\mathcal{O}(n^2)$ | Every element compared with all others | Nested loops, bubble sort | $n \le 5000$ |
| $\mathcal{O}(2^n)$ | Choices double at each step | Subsets / Combinations | $n \le 20 \sim 25$ |

---

## 3. Two Essential Rules of Big-O

### Rule 1: Drop Constant Factors
$$\mathcal{O}(3n) \rightarrow \mathcal{O}(n)$$
$$\mathcal{O}(n + n + n) = \mathcal{O}(3n) \rightarrow \mathcal{O}(n)$$
> **Crucial insight:** Having multiple sequential loops is **still $\mathcal{O}(n)$**, not $\mathcal{O}(n^2)$.

### Rule 2: Drop Lower-Order Terms
$$\mathcal{O}(n^2 + n + 10) \rightarrow \mathcal{O}(n^2)$$
$$\mathcal{O}(n + \log n) \rightarrow \mathcal{O}(n)$$
Keep only the dominant term as $n \to \infty$.

---

## 4. Sequential vs. Nested Loops

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

## 5. Space Complexity

Space complexity measures **extra auxiliary memory** allocated relative to $n$:

```cpp
// O(1) Extra Space: only fixed variables
int count = 0, sum = 0;

// O(n) Extra Space: dynamically growing structure
vector<int> pref(n);
unordered_set<int> s;
```

---

## 6. Code Analysis Checklist
1. What represents $n$?
2. Does the search space get halved ($\mathcal{O}(\log n)$)?
3. Are the loops sequential ($\mathcal{O}(n)$) or nested ($\mathcal{O}(n^2)$)?
4. Are you calling `std::sort` ($\mathcal{O}(n \log n)$)?
5. What auxiliary arrays/hash tables are created ($\text{Space Complexity}$)?
