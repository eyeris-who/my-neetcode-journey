// https://neetcode.io/problems/lowest-common-ancestor-in-binary-search-tree/question

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rootVal = root->val;
        int pVal = p->val;
        int qVal = q->val;
        if (rootVal == pVal || rootVal == qVal || (pVal < rootVal && qVal > rootVal) || (qVal < rootVal && pVal > rootVal)) return root;
        else if (pVal < rootVal && qVal < rootVal) return lowestCommonAncestor(root->left, p, q);
        else if (pVal > rootVal && qVal > rootVal) return lowestCommonAncestor(root->right, p, q);
    }
};
