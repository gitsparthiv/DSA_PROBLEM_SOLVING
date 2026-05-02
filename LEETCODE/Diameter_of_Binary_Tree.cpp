class Solution {
public:
    int maxi = 0;

    int findMax(TreeNode* node) {
        if (node == NULL) return 0;

        int lh = findMax(node->left);
        int rh = findMax(node->right);
        maxi = max(maxi, lh + rh);
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        findMax(root);
        return maxi;
    }
};
