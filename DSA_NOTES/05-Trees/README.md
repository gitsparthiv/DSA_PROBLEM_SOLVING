# Binary Trees Handbook

---

## 1. TreeNode Definition & Core Traversal (DFS Recursion)

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
```

---

## 2. Core Tree Patterns

### Pattern 1: Invert Binary Tree (LC 226)
- Swap left and right subtrees recursively.

```cpp
TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    
    root->left = right;
    root->right = left;
    return root;
}
```
- **Complexity:** Time $\mathcal{O}(n)$, Space $\mathcal{O}(h)$ ($h = \text{height of tree}$).

---

### Pattern 2: Maximum Depth of Binary Tree (LC 104)
```cpp
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
```

---

### Pattern 3: Diameter of Binary Tree (LC 543)
- **Definition:** Longest path between any two nodes.
- **Mental Model & Trick:**
  > *"At every node: use both sides (`lh + rh`) for the local diameter answer, but return only ONE side upward (`1 + max(lh, rh)`)."*

```cpp
class Solution {
public:
    int maxi = 0;
    
    int height(TreeNode* root) {
        if (!root) return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        // Update global diameter
        maxi = max(maxi, lh + rh);
        
        // Return height of current subtree
        return 1 + max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxi;
    }
};
```

### Common Tree Mistakes to Avoid:
1. Returning `left + right` instead of height from helper function.
2. Checking diameter only at root (path can lie entirely inside a subtree).
3. Overcomplicating base cases (simply check `if (!root) return 0;`).
