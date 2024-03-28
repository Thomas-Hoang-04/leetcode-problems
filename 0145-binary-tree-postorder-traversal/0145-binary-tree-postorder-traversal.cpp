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
void postOrder(TreeNode* root, vector<int> &res) {
    if (root != nullptr) {
        postOrder(root->left, res);
        postOrder(root->right, res); 
        res.push_back(root->val);
    }
}

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> res;
        postOrder(root, res);
        return res;
    }
};