# Hashing: Set & Map Handbook

---

## 1. Quick Mental Model

| Structure | Syntax | What it stores | When to ask yourself this: |
| :--- | :--- | :--- | :--- |
| **HashSet** | `unordered_set<T>` | Unique values | *"Have I seen this element before?"* |
| **HashMap** | `unordered_map<K, V>` | `key -> value` | *"What information is associated with this key?"* |

---

## 2. Set vs. Map Comparison Table

| Feature | `std::set` | `std::unordered_set` | `std::map` | `std::unordered_map` |
| :--- | :--- | :--- | :--- | :--- |
| **Data Structure** | Red-Black Tree | Hash Table | Red-Black Tree | Hash Table |
| **Ordering** | Sorted ascending | No order guarantee | Sorted by Key | No order guarantee |
| **Search / Find** | $\mathcal{O}(\log n)$ | $\mathcal{O}(1)$ avg | $\mathcal{O}(\log n)$ | $\mathcal{O}(1)$ avg |
| **Insert / Erase**| $\mathcal{O}(\log n)$ | $\mathcal{O}(1)$ avg | $\mathcal{O}(\log n)$ | $\mathcal{O}(1)$ avg |
| **Worst-case** | $\mathcal{O}(\log n)$ | $\mathcal{O}(n)$ (collisions)| $\mathcal{O}(\log n)$ | $\mathcal{O}(n)$ |

---

## 3. Essential HashSet (`unordered_set`) Syntax & Pitfalls

```cpp
#include <unordered_set>
using namespace std;

// 1. Initializing from a vector in O(n)
unordered_set<int> numSet(nums.begin(), nums.end());

// 2. Insert
numSet.insert(10);

// 3. Search (The Golden Idiom)
if (numSet.find(x) != numSet.end()) {
    // x WAS found in set
}
if (numSet.find(x) == numSet.end()) {
    // x was NOT found in set (Sequence starter condition: num - 1 == end())
}

// 4. Using count()
if (numSet.count(x)) {
    // returns 1 if exists, 0 if not
}

// 5. Traversing an unordered_set (Range-based loop)
for (int num : numSet) {
    // num is each unique element
}
```

---

## 4. Vector / Array of HashSets (Multi-Category Tracking)

When you need multiple independent hash sets to track elements across distinct groups (e.g., each row, column, or grid sub-box in a matrix like Sudoku):

### Declaration:
```cpp
// Creates a vector containing 9 independent HashSets
vector<unordered_set<char>> rows(9);
vector<unordered_set<char>> cols(9);
vector<unordered_set<char>> boxes(9);

// Or static array syntax:
unordered_set<char> rows[9];
```

### Mental Model in Memory:
```text
rows[0] -> HashSet for Row 0
rows[1] -> HashSet for Row 1
...
rows[8] -> HashSet for Row 8
```

### Operations via Index:
```cpp
// Check if character '5' already exists in Row r
if (rows[r].count('5')) {
    return false; // duplicate found in row r!
}

// Insert character '5' into Row r
rows[r].insert('5');
```

---

## 5. Key Patterns

### Pattern 1: Contains Duplicate (LC 217)
```cpp
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int x : nums) {
        if (seen.find(x) != seen.end()) return true;
        seen.insert(x);
    }
    return false;
}
```

### Pattern 2: Longest Consecutive Sequence in $O(n)$ (LC 128)
- Put all elements into an `unordered_set`.
- Loop over `numSet` with `for (int num : numSet)`.
- Check if `num` is a starter: `numSet.find(num - 1) == numSet.end()`.
- Expand streak with `while (numSet.find(currentNum + 1) != numSet.end())`.
- Update `maxstreak = max(maxstreak, currentStreak)`.

> ⚠️ **Critical Trap Avoided:** Always loop over `numSet`, NOT `nums`. Looping over `nums` can trigger the starter loop repeatedly for duplicate values (e.g. 100,000 zeros) leading to $O(n^2)$ TLE.

---

## 6. Essential HashMap (`unordered_map`) Syntax & Pitfalls

```cpp
#include <unordered_map>
using namespace std;

unordered_map<int, int> mp;

// 1. Insert / Update
mp[key] = value;
mp['a']++; // If 'a' didn't exist, initializes to 0 then increments to 1

// 2. ⚠️ Critical Pitfall: mp[key] creates default entries!
// DO NOT use mp[key] just to check existence. Use .find() instead:
if (mp.find(key) != mp.end()) {
    // key exists
}

// 3. Iteration
for (auto& pair : mp) {
    cout << "Key: " << pair.first << ", Value: " << pair.second << "\n";
}
```

### How to Choose Key and Value:
1. **Key:** *What am I searching for later?* (e.g., complement number, character)
2. **Value:** *What information do I need when I find it?* (e.g., index, frequency count)

---

## 7. Sorting a HashMap by Value (Important Pattern)

Convert to `vector<pair<K, V>>`:
```cpp
unordered_map<int, int> mp; // e.g. {num, freq}

// 1. Copy map entries into a vector of pairs
vector<pair<int, int>> v(mp.begin(), mp.end());

// 2. Sort by frequency (second) descending
sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
    return a.second > b.second;
});
```

---

## 8. Bucket Sort Pattern: Bounded Range Sorting in $\mathcal{O}(N)$ Time (LC 347)

### What is Bucket Sort?
Standard comparison sorts (QuickSort, MergeSort, `std::sort`) take $\mathcal{O}(N \log N)$ time because elements could have any arbitrary values.
**Bucket Sort** exploits a special constraint: **when the values to be sorted lie within a small, known, bounded range** (such as frequencies from $1$ to $N$), we can sort in pure **$\mathcal{O}(N)$ linear time** without comparisons!

### Why `vector<vector<int>>` instead of primitive arrays?
- A standard 1D array `int arr[N]` can only store **one single number** per index. If two numbers have the same frequency, the second will overwrite the first!
- A fixed 2D array `int arr[N][M]` wastes huge memory because most frequencies have few or zero elements.
- **The Ideal Solution:** `vector<vector<int>> buckets(n + 1);`
  - An array of $N + 1$ buckets where the **index** is the frequency ($0, 1, 2, \dots, N$).
  - Each bucket `buckets[i]` is a dynamic `vector<int>` that can hold multiple numbers having that exact frequency.

### Mental Model & Diagram:
For `nums = [1, 1, 1, 2, 2, 3]`, $N = 6$:
- Frequencies: `1 -> 3`, `2 -> 2`, `3 -> 1`
- Buckets:
  - `Index 0:` `[]`
  - `Index 1:` `[3]`  (frequency 1)
  - `Index 2:` `[2]`  (frequency 2)
  - `Index 3:` `[1]`  (frequency 3)
  - `Index 4..6:` `[]`
- To get Top $k=2$, scan from index $6$ down to $1$:
  - Index 3 gives `1`
  - Index 2 gives `2`
  - Result: `[1, 2]` in $\mathcal{O}(N)$ time!

### Template Code:
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> count;
    for (int num : nums) count[num]++;
    
    // buckets[freq] holds a list of numbers with that frequency
    vector<vector<int>> buckets(n + 1);
    for (auto& pair : count) {
        buckets[pair.second].push_back(pair.first);
    }
    
    vector<int> result;
    // Iterate from highest possible frequency (n) down to 1
    for (int i = n; i >= 1; i--) {
        for (int num : buckets[i]) {
            result.push_back(num);
            if (result.size() == k) return result;
        }
    }
    return result;
}
```
- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(N)$
