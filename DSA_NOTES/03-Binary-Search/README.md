# Binary Search Handbook

---

## 1. The Core Mental Model

Binary Search works on a **monotonically ordered / partitioned search space**. At each step, we eliminate half the candidates, achieving **$\mathcal{O}(\log n)$** time complexity.

> **Crucial Rule:** Binary search deals with **indices**, not values. Always calculate `mid` from indices, then compare `nums[mid]` with `target`.

---

## 2. Standard Binary Search Template (LC 704)

```cpp
int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    
    while (low <= high) {
        // Prevents integer overflow vs (low + high) / 2
        int mid = low + (high - low) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Not found
}
```

---

## 3. Key Patterns & Variations

### Pattern 1: Search Insert Position (LC 35)
When target is not found, **`low` always ends up at the correct insertion index**!
```cpp
int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return low; // Point of insertion
}
```

---

### Pattern 2: Integer Square Root / Search on Answer (LC 69)
```cpp
int mySqrt(int x) {
    if (x <= 1) return x;
    int low = 1, high = x / 2, ans = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long sq = 1LL * mid * mid;
        
        if (sq == x) return mid;
        else if (sq < x) {
            ans = mid;    // Store possible floor answer
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans; // Or return high
}
```

---

### Pattern 3: 2D Matrix as a 1D Array (LC 74)
- An $m \times n$ matrix where each row is sorted and `row[i][0] > row[i-1][last]` can be mapped directly to 1D index from `0` to `m * n - 1`.
- **Coordinate Conversion:**
  $$\text{row} = \text{mid} / n, \quad \text{col} = \text{mid} \% n$$

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = m * n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int val = matrix[mid / n][mid % n];
        
        if (val == target) return true;
        else if (val < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
```

---

### Pattern 4: Find Minimum in Rotated Sorted Array (LC 153)
- Compare `nums[mid]` with `nums[high]`:
  - If `nums[mid] > nums[high]` $\rightarrow$ Minimum is strictly in the **right half** (`low = mid + 1`).
  - If `nums[mid] < nums[high]` $\rightarrow$ Minimum is at `mid` or in the **left half** (`high = mid`).

```cpp
int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return nums[low];
}
```
