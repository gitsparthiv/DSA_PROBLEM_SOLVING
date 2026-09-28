# Arrays & Dynamic Arrays Notes

---

## 1. Vector Memory & Sizing Model (Critical Mistake Prevention)

### The Two Vector Declarations:

```cpp
// 1. Empty Vector (size = 0)
vector<int> v;
// v[0] = 10;   // ❌ RUNTIME ERROR / SEGFAULT! Index 0 does not exist!
v.push_back(10); // ✅ Correct: adds element to back, size becomes 1

// 2. Pre-sized Vector (size = n, default initialized to 0)
vector<int> v(5); // [0, 0, 0, 0, 0]
v[3] = 50;        // ✅ Correct: index 3 already exists!
```

### The Rule:
- **`v[i] = val`**: Only use when index `i` is **already allocated**.
- **`v.push_back(val)`**: Use when dynamically growing an empty or unsized container.

---

## 2. Core Array Patterns

### Pattern 1: Finding Min/Max in a Single Pass without Extra Storage
```cpp
int small = nums[0];
for (int i = 1; i < nums.size(); i++) {
    if (nums[i] < small) {
        small = nums[i];
    }
}
// Time: O(n), Space: O(1)
```

---

### Pattern 2: Prefix & Suffix Products (LeetCode 238)
- **Problem:** Compute product of all elements except self in $\mathcal{O}(n)$ without division.
- **Mental Model:**
$$\text{result}[i] = (\text{product of all elements to LEFT of } i) \times (\text{product of all elements to RIGHT of } i)$$

```cpp
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> pref(n), suff(n), res(n);
    
    // Step 1: Prefix products
    pref[0] = 1;
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] * nums[i - 1];
    }
    
    // Step 2: Suffix products
    suff[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = suff[i + 1] * nums[i + 1];
    }
    
    // Step 3: Combine
    for (int i = 0; i < n; i++) {
        res[i] = pref[i] * suff[i];
    }
    return res;
}
```
- **Complexity:** Time $\mathcal{O}(n)$, Space $\mathcal{O}(n)$.
