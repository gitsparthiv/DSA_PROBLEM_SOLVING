# The 4th-Year C++ for DSA Interview Handbook

> **Purpose:** A high-yield, zero-fluff reference of the 25 essential C++ STL patterns and syntax rules required for technical coding interviews. Review this for 5 minutes before every coding session.

---

## 1. Vector Essentials (Avoid the 3 Classic Traps)

```cpp
// TRAP 1: Empty vs Pre-filled
vector<int> a;        // size = 0. MUST use a.push_back(x);
vector<int> b(5);     // size = 5 pre-filled with 0s: [0,0,0,0,0]. MUST use b[i] = x;
vector<int> c(5, -1); // size = 5 pre-filled with -1: [-1,-1,-1,-1,-1]

// TRAP 2: 2D Vectors (Dynamic Matrix / Buckets)
int rows = 3, cols = 4;
vector<vector<int>> matrix(rows, vector<int>(cols, 0)); // 3x4 grid of zeros

// TRAP 3: Bucket List (List of Lists)
vector<vector<int>> buckets(N + 1); // N+1 empty vectors ready for .push_back()
buckets[freq].push_back(num);

// Common Vector Operations:
v.size();            // number of elements
v.empty();           // true if size == 0
v.push_back(val);    // append to end - O(1) amortized
v.pop_back();        // remove last element - O(1)
v.back();            // inspect last element - O(1)
```

---

## 2. Unordered Map & Set (Hashing Patterns)

```cpp
#include <unordered_map>
#include <unordered_set>

// 1. Frequency Counting
unordered_map<int, int> count;
for (int num : nums) count[num]++;

// 2. TRAP: mp[key] creates default entries if key is missing!
// Safe existence check:
if (count.find(target) != count.end()) {
    // target exists!
}

// 3. Iterating over Maps:
for (auto& pair : count) {
    int key = pair.first;
    int val = pair.second;
}

// 4. Set Membership:
unordered_set<int> seen(nums.begin(), nums.end()); // O(N) initialization
if (seen.count(target)) { /* target is in set */ }
```

---

## 3. String & Character Utilities

```cpp
#include <string>
#include <cctype>
#include <algorithm>

string s = "A man, a plan!";

// Character Checks:
isalnum(c);   // true if letter or digit
isalpha(c);   // true if letter
isdigit(c);   // true if 0-9
tolower(c);   // converts 'A' -> 'a'

// Sorting Strings (Canonical Anagram Key):
string key = s;
sort(key.begin(), key.end()); // sorts characters alphabetically

// Substrings:
string sub = s.substr(start_index, length); // O(length)
```

---

## 4. Sorting & Custom Comparators

```cpp
#include <algorithm>

vector<int> nums = {4, 1, 3};
sort(nums.begin(), nums.end());                   // Ascending: [1, 3, 4]
sort(nums.rbegin(), nums.rend());                 // Descending: [4, 3, 1]

// Sorting Pairs (e.g. by second value descending):
vector<pair<int, int>> pairs = {{1, 10}, {2, 5}};
sort(pairs.begin(), pairs.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
    return a.second > b.second; // descending by frequency
});
```

---

## 5. Pointer (`*`) vs Reference (`&`) Rules

- **Use `&` in Range Loops:** `for (const auto& s : strs)` avoids expensive copying of large objects.
- **Use `&` to Mutate Original Container:** `for (int& x : nums) x *= 2;`
- **Use Pass-by-Reference in Helpers:**
  ```cpp
  void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int& result)
  ```
  *(Passing large vectors by value creates a full copy on every recursive call, causing TLE/MLE!)*

---

## 6. Stack & Queue Traps

```cpp
#include <stack>
#include <queue>

// CRITICAL TRAP: Always check !empty() before calling .top() or .front()!
stack<int> st;
if (!st.empty()) {
    int val = st.top();
    st.pop();
}

queue<int> q; // FIFO for BFS
q.push(root);
while (!q.empty()) {
    int levelSize = q.size(); // snapshot size for level-by-level BFS
    for (int i = 0; i < levelSize; i++) {
        int curr = q.front(); q.pop();
    }
}
```

---

## 7. Priority Queue (Heap) Syntax

```cpp
#include <queue>

// Default: MAX-HEAP (Largest on top)
priority_queue<int> maxHeap;
maxHeap.push(10);
int largest = maxHeap.top(); maxHeap.pop();

// MIN-HEAP (Smallest on top) - The Syntax to Memorize:
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(10);
int smallest = minHeap.top(); minHeap.pop();
```

---

## 8. Binary Search Overflow Protection

```cpp
// BAD (Can overflow 32-bit int if left + right > 2*10^9):
int mid = (left + right) / 2;

// GOOD (Always mathematically safe):
int mid = left + (right - left) / 2;
```
