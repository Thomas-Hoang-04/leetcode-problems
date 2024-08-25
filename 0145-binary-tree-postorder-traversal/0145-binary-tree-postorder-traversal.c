/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void postOrder(struct TreeNode* root, int* ans, int* size) {
    if (!root) return;
    postOrder(root->left, ans, size);
    postOrder(root->right, ans, size);
    ans[(*size)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    postOrder(root, ans, returnSize);
    return ans;
}