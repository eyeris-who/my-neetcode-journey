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
    bool isValidHelper(TreeNode* root, int minVal, int maxVal) {
        if (!root || (!root->left && !root->right)) return true;
        int rootVal = root->val;
        if (root->left && root->right) {
            int leftVal = root->left->val;
            int rightVal = root->right->val;
            if (leftVal <= minVal || leftVal >= maxVal || rightVal <= minVal || rightVal >= maxVal) return false;
            if (leftVal >= rootVal || rightVal <= rootVal) return false;
            return isValidHelper(root->left, minVal, rootVal) && isValidHelper(root->right, rootVal, maxVal);
        } else if (root->left) {
            int leftVal = root->left->val;
            if (leftVal <= minVal || leftVal >= maxVal) return false;
            if (leftVal >= rootVal) return false;
            return isValidHelper(root->left, minVal, rootVal);
        } else if (root->right) {
            int rightVal = root->right->val;
            if (rightVal <= minVal || rightVal >= maxVal) return false;
            if (rightVal <= rootVal) return false;
            return isValidHelper(root->right, rootVal, maxVal);
        }
    }
    bool isValidBST(TreeNode* root) {
        return isValidHelper(root, -1000000001, 1000000001);
    }
};
