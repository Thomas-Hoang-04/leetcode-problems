/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL) return root->val == targetSum;
    int next = targetSum - root->val;
    return hasPathSum(root->left, next) || hasPathSum(root->right, next);
}