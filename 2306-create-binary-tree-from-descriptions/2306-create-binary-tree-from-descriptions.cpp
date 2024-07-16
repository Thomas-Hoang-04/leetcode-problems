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
#pragma GCC optimize (O3, "unroll-loops")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* nodes[100001] = {nullptr};
        bool child[100001] = {0};
        bool par[100001] = {0};

        for (vector<int>& node: descriptions) {
            if (!nodes[node[0]]) nodes[node[0]] = new TreeNode(node[0]);
            if (!nodes[node[1]]) nodes[node[1]] = new TreeNode(node[1]);
            if (node[2]) nodes[node[0]]->left = nodes[node[1]];
            else nodes[node[0]]->right = nodes[node[1]];

            child[node[1]] = true;
            par[node[0]] = !child[node[0]];
            par[node[1]] = !child[node[1]];
        }

        for (int i = 1; i < 100001; i++) if (par[i]) return nodes[i];

        return nullptr;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();