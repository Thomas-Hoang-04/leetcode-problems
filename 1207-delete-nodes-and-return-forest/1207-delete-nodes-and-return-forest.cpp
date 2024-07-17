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
    unordered_map<int, bool> del;
    void dfs(TreeNode* root, TreeNode* prev, bool stat) {
        if (!root) return;

        if (del[root->val]) {
            if (root->left && !del[root->left->val]) ans.push_back(root->left);
            if (root->right && !del[root->right->val]) ans.push_back(root->right);
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
        for (int d: to_delete) del[d] = true;
        if (!del[root->val]) ans.push_back(root);
        dfs(root, nullptr, false);
        return ans;
    }
};