# Range-Based For Loops & Container Traversal in C++

---

## 1. What is a Range-Based For Loop?

A **range-based for loop** (introduced in C++11) allows you to iterate through every element in any C++ container or array without manually maintaining iterators or index counters.

### Syntax:
```cpp
for (declaration : container) {
    // operations on element
}
```
Think of the `:` character as the word **"in"**:
> *"For each `declaration` in `container`..."*

---

## 2. Comparison: 3 Ways to Loop Over Containers

### Example: Vector
```cpp
vector<int> nums = {10, 20, 30};

// Method 1: Traditional Index (Only works on indexed containers like vector, deque, array)
for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
}

// Method 2: Traditional Iterators (Works on all STL containers, but verbose)
for (auto it = nums.begin(); it != nums.end(); it++) {
    cout << *it << " ";
}

// Method 3: Range-Based Loop (Cleanest & Idiomatic C++)
for (int num : nums) {
    cout << num << " ";
}
```

---

## 3. When MUST You Use Range-Based Loops / Iterators?

Unordered containers like **`unordered_set`**, **`set`**, **`unordered_map`**, and **`map`** **do NOT support indexing** (`numSet[i]` is a compiler error).

### Traversing an `unordered_set`:
```cpp
unordered_set<int> numSet = {5, 10, 15};

// Best approach:
for (int num : numSet) {
    cout << num << "\n";
}
```

### Traversing an `unordered_map`:
Each element in a map is a `pair<const Key, Value>`:
```cpp
unordered_map<string, int> freq = {{"apple", 3}, {"banana", 2}};

// By value copy:
for (auto pair : freq) {
    cout << pair.first << " -> " << pair.second << "\n";
}

// By const reference (efficient, avoids copying):
for (const auto& [key, value] : freq) {
    cout << key << " -> " << value << "\n";
}
```

---

## 4. Value vs Reference in Range Loops

| Syntax | Description | When to use |
| :--- | :--- | :--- |
| `for (int x : vec)` | **By Value** (makes a copy of each element) | Primitive types (`int`, `char`, `bool`) where you only read. |
| `for (int& x : vec)` | **By Reference** (allows modifying the original container elements) | When you want to update `vec[i]` in-place. |
| `for (const auto& x : vec)` | **By Const Reference** (no copy, read-only) | Objects, `string`, `vector<vector<int>>`, or large structs to avoid expensive copies. |

```cpp
// Example: Modifying elements in-place using reference (&)
vector<int> v = {1, 2, 3};
for (int& x : v) {
    x *= 2; // Doubled in-place
}
// v is now: [2, 4, 6]
```
