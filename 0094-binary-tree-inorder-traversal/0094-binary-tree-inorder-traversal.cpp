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
void inOrder(TreeNode* root, vector<int> &res) {
    if (root != nullptr) {
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res); 
    }
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> res;
        inOrder(root, res);
        return res;
    }
};