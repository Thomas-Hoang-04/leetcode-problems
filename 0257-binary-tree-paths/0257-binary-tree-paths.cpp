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
    vector<string> ans;
    void dfs(TreeNode* root, string path) {
        if (!root) return;

        const size_t tmp = path.size();
        path += to_string(root->val);

        if (!root->left && !root->right) {
            ans.push_back(path);
        } else {
            path += "->";
            dfs(root->left, path);
            dfs(root->right, path);
        }

        path.resize(tmp);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();