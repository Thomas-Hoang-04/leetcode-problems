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
private:
    vector<TreeNode*> ans;
    bool del[1000] = { 0 };
    void dfs(TreeNode* root, TreeNode* prev, bool stat) {
        if (!root) return;

        if (del[root->val - 1]) {
            if (root->left && !del[root->left->val - 1]) ans.push_back(root->left);
            if (root->right && !del[root->right->val - 1]) ans.push_back(root->right);
            if (prev) {
                if (stat) prev->left = nullptr;
                else prev->right = nullptr;
            }
        }

        dfs(root->left, root, true);
        dfs(root->right, root, false);
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root) return {};
        for (int d: to_delete) del[d - 1] = true;
        if (!del[root->val - 1]) ans.push_back(root);
        dfs(root, nullptr, false);
        return ans;
    }
};