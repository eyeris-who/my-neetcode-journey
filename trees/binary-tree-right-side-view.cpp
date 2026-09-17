// https://neetcode.io/problems/binary-tree-right-side-view/question

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
    // basically get last node of each level
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<int> result;
        if (!root) return result;
        pair<TreeNode*, int> last = {root, 1};
        q.push(last);
        while(!q.empty()) {
            int count = q.front().second;
            int lastCount = last.second;
            TreeNode* node = q.front().first;
            TreeNode* lastNode = last.first;
            if (count > lastCount) result.push_back(lastNode->val);
            last = q.front();
            if (node->left) q.push({node->left, count+1});
            if (node->right) q.push({node->right, count+1});
            q.pop();
        }
        result.push_back(last.first->val);
        return result;
    }
};
