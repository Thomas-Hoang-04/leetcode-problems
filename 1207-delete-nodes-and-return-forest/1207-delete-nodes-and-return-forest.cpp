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
    bool del[1001] = { 0 };
    TreeNode* dfs(TreeNode* root, TreeNode* prev) {
        if (!root) return nullptr;

        root->left = dfs(root->left, root);
        root->right = dfs(root->right, root);

        if (del[root->val]) {
            if (root->left && !del[root->left->val]) ans.push_back(root->left);
            if (root->right && !del[root->right->val]) ans.push_back(root->right);
            return nullptr;
        }

        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root) return {};
        for (int d: to_delete) del[d] = true;
        if (!del[root->val]) ans.push_back(root);
        dfs(root, nullptr);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();