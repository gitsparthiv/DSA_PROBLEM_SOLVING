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

unordered_set<int> s;

// 1. Insert
s.insert(10);
s.insert(20);

// 2. Search (The Golden Idiom)
if (s.find(x) != s.end()) {
    // x WAS found
}
if (s.find(x) == s.end()) {
    // x was NOT found
}

// 3. Or using count()
if (s.count(x)) {
    // x exists (returns 1 or 0)
}

// 4. Erase
s.erase(10);
```

### Problem Pattern: Contains Duplicate (LC 217)
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

---

## 4. Essential HashMap (`unordered_map`) Syntax & Pitfalls

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

## 5. Sorting a HashMap by Value (Important Pattern)

You **cannot** sort a hashmap directly with `std::sort()`.

### The Idiom: Convert to `vector<pair<K, V>>`:
```cpp
unordered_map<int, int> mp; // e.g. {num, freq}

// 1. Copy map entries into a vector of pairs
vector<pair<int, int>> v(mp.begin(), mp.end());

// 2. Sort by frequency (second) descending
sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
    return a.second > b.second;
});
```
