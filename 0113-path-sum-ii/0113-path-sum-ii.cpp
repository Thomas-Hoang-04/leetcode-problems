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
    vector<vector<int>> ans;

    void path(TreeNode* root,int sum, int targetSum, vector<int> &res) {
    if (root == nullptr) return;
    res.push_back(root->val);
    sum += root->val;
    if (root->left == nullptr && root->right == nullptr) {
        if (sum == targetSum) ans.push_back(res);
    } else {
        path(root->left, sum, targetSum, res);
        path(root->right, sum, targetSum, res);
    }
    res.pop_back();
}

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    int sum = 0;
    vector<int> res;
    path(root, sum, targetSum, res);
    return ans;
    }
};