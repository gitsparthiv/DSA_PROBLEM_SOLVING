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

## 4. Key Patterns

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

## 5. Essential HashMap (`unordered_map`) Syntax & Pitfalls

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

## 6. Sorting a HashMap by Value (Important Pattern)

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
