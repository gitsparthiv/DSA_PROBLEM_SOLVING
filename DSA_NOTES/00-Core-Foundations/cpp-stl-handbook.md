# C++ Standard Template Library (STL) Handbook

A complete reference of STL containers, iterators, and utility functions for DSA.

---

## 1. Important Headers & Boilerplate

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility> // pair

using namespace std;
```

> **Note on `#include <bits/stdc++.h>`**: Includes all standard library headers. Commonly used in competitive programming and LeetCode.

---

## 2. Pointers & Reference Basics

```cpp
int x = 10;
int* p = &x; // p stores memory address of x
// *p dereferences the pointer (gives value 10)
```

| Expression | Meaning | Value |
| :--- | :--- | :--- |
| `x` | Value stored | `10` |
| `&x` | Address of `x` in memory | `0x7ffee...` |
| `p` | Stores address of `x` | `0x7ffee...` |
| `*p` | Value at the stored address | `10` |

---

## 3. Pair & Nested Pair

Stores two heterogeneous items together.

```cpp
// Basic Pair
pair<int, string> p = {10, "Raj"};
cout << p.first << " " << p.second; // 10 Raj

// Nested Pair
pair<int, pair<int, int>> np = {1, {3, 4}};
cout << np.first;          // 1
cout << np.second.first;   // 3
cout << np.second.second;  // 4

// Array of Pairs
pair<int, int> arr[3] = {{1, 2}, {3, 4}, {5, 6}};
cout << arr[1].first; // 3
```

---

## 4. Containers Reference Table

| Container | Underlying Structure | Unique / Duplicates | Ordering | Access / Lookup | Insert / Push | Delete / Pop |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **`vector<T>`** | Dynamic Array | Duplicates | Insertion order | $O(1)$ by index | $O(1)$ amortized | $O(1)$ pop back |
| **`list<T>`** | Doubly Linked List | Duplicates | Insertion order | $O(n)$ | $O(1)$ front/back | $O(1)$ front/back |
| **`deque<T>`** | Double-ended queue | Duplicates | Insertion order | $O(1)$ by index | $O(1)$ front/back | $O(1)$ front/back |
| **`stack<T>`** | LIFO container | Duplicates | LIFO | $O(1)$ top only | $O(1)$ push | $O(1)$ pop |
| **`queue<T>`** | FIFO container | Duplicates | FIFO | $O(1)$ front/back | $O(1)$ push back | $O(1)$ pop front |
| **`priority_queue<T>`** | Heap (Max-heap default) | Duplicates | Max at top | $O(1)$ top only | $O(\log n)$ push | $O(\log n)$ pop |
| **`set<T>`** | Self-Balancing BST (Red-Black) | Unique | Ascending sorted | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ |
| **`multiset<T>`** | Red-Black Tree | Duplicates | Ascending sorted | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ |
| **`unordered_set<T>`** | Hash Table | Unique | Unordered | $O(1)$ avg, $O(n)$ worst | $O(1)$ avg | $O(1)$ avg |
| **`map<K, V>`** | Red-Black Tree | Unique Keys | Sorted by Key | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ |
| **`multimap<K, V>`** | Red-Black Tree | Duplicate Keys | Sorted by Key | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ |
| **`unordered_map<K, V>`** | Hash Table | Unique Keys | Unordered | $O(1)$ avg, $O(n)$ worst | $O(1)$ avg | $O(1)$ avg |

---

## 5. Sequential Containers Cheat Sheet

### Vector (`std::vector`)
```cpp
vector<int> v;              // Empty vector (size = 0)
vector<int> v(5);           // [0, 0, 0, 0, 0] (size = 5)
vector<int> v(5, 100);      // [100, 100, 100, 100, 100]

v.push_back(10);            // Adds 10 at the end
v.emplace_back(20);         // Faster in-place construction
v.pop_back();               // Removes last element
v.front();                  // First element
v.back();                   // Last element
v.size();                   // Number of elements
v.empty();                  // Check if empty
v.clear();                  // Remove all elements

// Erasing
v.erase(v.begin() + 1);               // Erase element at index 1
v.erase(v.begin() + 1, v.begin() + 3); // Erase range [1, 3) -> index 1 and 2

// Inserting
v.insert(v.begin(), 5);               // Insert 5 at beginning
v.insert(v.begin() + 1, 2, 50);       // Insert two copies of 50 at index 1
```

### Stack (`std::stack` - LIFO)
```cpp
stack<int> st;
st.push(10);
st.emplace(20);
int topVal = st.top(); // 20 (does NOT remove)
st.pop();              // Removes 20
// Note: st[0] is INVALID (no random indexing)
```

### Queue (`std::queue` - FIFO)
```cpp
queue<int> q;
q.push(10);
q.push(20);
int f = q.front(); // 10
int b = q.back();  // 20
q.pop();           // Removes 10
```

### Priority Queue (`std::priority_queue` - Heap)
```cpp
// Max-Heap (Default: largest element at top)
priority_queue<int> maxHeap;
maxHeap.push(10);
maxHeap.push(30);
maxHeap.top(); // 30

// Min-Heap (Smallest element at top)
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(10);
minHeap.push(30);
minHeap.top(); // 10
```

---

## 6. Iterators & The `[start, end)` Rule

- `v.begin()`: Points to the first element.
- `v.end()`: Points **one past the last element**.
- `v.rbegin()`, `v.rend()`: Reverse iterators.

> **Crucial Rule:** All STL range operations operate on `[start, end)` where `start` is included and `end` is excluded!

```cpp
// Traverse using iterators
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}

// Range-based loop (cleanest)
for (auto x : v) {
    cout << x << " ";
}
```

---

## 7. Algorithms & Built-ins

```cpp
#include <algorithm>

// 1. Sorting
sort(v.begin(), v.end());                         // Ascending
sort(v.begin(), v.end(), greater<int>());         // Descending
sort(v.begin() + 1, v.begin() + 4);               // Sort partial range

// 2. Min / Max Element (returns iterator -> dereference with *)
int maxVal = *max_element(v.begin(), v.end());
int minVal = *min_element(v.begin(), v.end());

// 3. Permutations
string s = "123";
sort(s.begin(), s.end()); // MUST sort first to get all permutations
do {
    cout << s << endl;
} while (next_permutation(s.begin(), s.end()));

// 4. Bit Manipulation Built-ins
int count1 = __builtin_popcount(7);         // Returns 3 (for int)
int count2 = __builtin_popcountll(1LL << 40); // For long long
```

---

## 8. Custom Comparators

### The Core Thinking:
Take only **two elements (`p1`, `p2`)** and ask:
> *"Should `p1` come BEFORE `p2`?"*
- If yes $\rightarrow$ `return true;`
- If no $\rightarrow$ `return false;`

### Example: Sort pairs by second ascending; if equal, first descending
```cpp
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second != p2.second) {
        return p1.second < p2.second; // Smaller second first
    }
    return p1.first > p2.first;       // Larger first first
}
sort(v.begin(), v.end(), comp);

// Or via Lambda:
sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first > b.first;
});
```
