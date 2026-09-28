# 📚 DSA Master Notes & Revision Guide

A structured, clean, and comprehensive collection of Data Structures & Algorithms notes, syntax cheat sheets, patterns, and mental models.

---

## 🗂️ Table of Contents

### 1. [00-Core-Foundations](00-Core-Foundations/)
- [**C++ STL Complete Handbook**](00-Core-Foundations/cpp-stl-handbook.md) — Vector, Map, Set, Stack, Queue, Priority Queue, Iterators, Custom Comparators, and Built-ins.
- [**Time & Space Complexity Analysis**](00-Core-Foundations/time-complexity.md) — Big-O notation, growth hierarchy, sequential vs. nested loops, and memory analysis.

### 2. Topic-Wise Handbooks
- [**01 - Arrays & Dynamic Arrays**](01-Arrays/README.md) — Vector allocation pitfalls, single-pass min/max, prefix/suffix products.
- [**02 - Hashing (Set & Map)**](02-Hashing/README.md) — `unordered_set` vs `unordered_map`, frequency counting, map sorting idiom, finding keys vs values.
- [**03 - Binary Search**](03-Binary-Search/README.md) — Standard template, search insert position, integer square root, 2D matrix search, rotated array minimum.
- [**04 - Linked Lists**](04-Linked-List/README.md) — Reversal 3-pointer idiom, merge sorted lists, Floyd’s cycle detection, $N$-th node removal from end.
- [**05 - Binary Trees**](05-Trees/README.md) — DFS recursion, tree inversion, maximum depth, subtree diameter calculations.

---

## 💡 Quick Rules to Remember
1. **Pointers vs Values:** `*p` gets the value, `&x` gets the memory address.
2. **STL Range Invariant:** All ranges in C++ STL are `[start, end)` (start included, end excluded).
3. **Map Existence:** Never use `mp[key]` to check if a key exists (it creates a default entry). Use `mp.find(key) != mp.end()`.
4. **Vector Access:** Never write `v[i] = x` on an empty vector; either pre-size `vector<int> v(n)` or use `v.push_back(x)`.
5. **Continuous Updates:** New patterns, learnings, and syntax discovered during problem solving will be integrated directly into these notes.
