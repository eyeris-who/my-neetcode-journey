// https://neetcode.io/problems/count-good-nodes-in-binary-tree/question

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
    int goodNodesHelper(TreeNode* root, int maximum) {
        if (!root) return 0;
        int val = root->val;
        int goodNode = 0;
        if (val >= maximum) goodNode = 1;
        maximum = max(maximum, root->val);
        return goodNode + goodNodesHelper(root->left, maximum) + goodNodesHelper(root->right, maximum);
    }
    int goodNodes(TreeNode* root) {
        return goodNodesHelper(root, -101);
    }
};
