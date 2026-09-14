// https://neetcode.io/problems/balanced-binary-tree/question

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int height(TreeNode* root, bool& balanced) {
        if (!root) return 0;
        int lh = height(root->left, balanced);
        int rh = height(root->right, balanced);
        int diff = lh-rh;
        if (diff<=-2 || diff>=2) balanced = false;
        return 1+max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        bool balanced = true;
        height(root, balanced);
        return balanced;
    }
};
