/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inOrder(int* sum, struct TreeNode* root) {
    if (!root) return;
    
    if (root->left && root->left->left == NULL && root->left->right == NULL) {
        *sum += root->left->val;
    }

    inOrder(sum, root->left);
    inOrder(sum, root->right);
}

int sumOfLeftLeaves(struct TreeNode* root) {
    int sum = 0;
    inOrder(&sum, root);
    return sum;
}