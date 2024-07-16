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
    bool dfs(TreeNode* root, int tar, string& path) {
        if (!root) return false;
        if (root->val == tar) return true;

        path += "L";
        if (dfs(root->left, tar, path)) return true;
        path.pop_back();

        path += "R";
        if (dfs(root->right, tar, path)) return true;
        path.pop_back();
        
        return false;
    }
public:
    string getDirections(TreeNode* root, int stVal, int destVal) {
        string stPath = "", destPath = "", dir = "";
        
        dfs(root, stVal, stPath);
        dfs(root, destVal, destPath);

        int intersect = 0;

        while (intersect < stPath.size() && intersect < destPath.size() && stPath[intersect] == destPath[intersect]) intersect++;

        for (int i = 0; i < stPath.size() - intersect; i++) dir += "U";

        while (intersect < destPath.size()) dir += destPath[intersect++];

        return dir;
    }
};