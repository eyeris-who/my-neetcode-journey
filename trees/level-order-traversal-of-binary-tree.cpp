// https://neetcode.io/problems/level-order-traversal-of-binary-tree/question

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            TreeNode* top = q.front().first;
            int layer = q.front().second;
            if (top) {
                q.push({top->left, layer+1});
                q.push({top->right, layer+1});
                if (result.size() == layer) result.push_back({top->val});
                else result[layer].push_back(top->val);
            }
            q.pop();
        }
        return result;
    }
};
